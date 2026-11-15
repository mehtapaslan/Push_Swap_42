*This project has been created as part of the 42 curriculum by beakduma, mehaslan.*

# Push_swap

## Description

**Push_swap** sorts a list of integers using two stacks (`a` and `b`) and a fixed set of 11 operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`. At the start, stack `a` holds a duplicate-free list of integers and stack `b` is empty. The program prints to standard output a sequence of operations that leaves `a` sorted in ascending order (smallest on top), and tries to keep that sequence as short as possible.

The project is about **algorithmic complexity in practice**. The program contains four sorting strategies, and the cost of each one is measured in **number of Push_swap operations generated**:

| Strategy   | Flag         | Technique                                | Cost (operations) |
|------------|--------------|------------------------------------------|-------------------|
| Simple     | `--simple`   | Minimum extraction (selection sort)      | O(n²)             |
| Medium     | `--medium`   | Chunk-based sorting with ~√n/2 chunks    | O(n√n)            |
| Complex    | `--complex`  | Two-sided LSD radix sort on ranks        | O(n log n)        |
| Adaptive   | `--adaptive` | Picks one of the above from the disorder | depends on regime |

`--adaptive` is the default when no strategy flag is given.

## Instructions

### Compilation

```bash
make          # builds libft first (with its own Makefile), then push_swap
make clean    # removes object files (project + libft)
make fclean   # clean + removes push_swap and libft.a
make re       # fclean + all
```

The Makefile compiles with `cc -Wall -Wextra -Werror` and does not relink when nothing has changed.

### Usage

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers...>
```

- Flags must come **before** the numbers. Each flag can be given at most once, and at most one strategy can be selected.
- Numbers can be passed as separate arguments (`3 2 1`) or inside one string (`"3 2 1"`). The first number is the top of stack `a`.
- No arguments: the program prints nothing and exits.
- Input that is already sorted (or a single number): the program prints no operations.
- Invalid input (a value that is not an integer, a value outside the `int` range, a duplicate, an empty argument, an unknown or repeated flag): the program prints `Error` followed by a newline on `stderr` and exits with status 1.

### Examples

```bash
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker_linux $ARG
shuf -i 0-9999 -n 500 > args.txt; ./push_swap $(cat args.txt) | wc -l
```

### Benchmark mode

`--bench` prints metrics to **stderr** after sorting, so the operations on stdout can still be piped into a checker:

```bash
$> ARG="4 67 3 87 23"; ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker_linux $ARG
OK
$> cat bench.txt
[bench] disorder:  40.00%
[bench] strategy:  Adaptive / O(n^2)
[bench] total_ops:  9
[bench] sa: 0  sb: 0  ss: 0  pa: 2  pb: 2
[bench] ra: 4  rb: 0  rr: 0  rra: 1  rrb: 0  rrr: 0
```

The bench output shows:
- the disorder of the initial stack, as a percentage with two decimals
- the strategy that was used and its complexity class
- the total number of operations
- the count of each operation type

Each operation goes through `put_op()`, which prints it and increments a counter. The counters live in a `static` array inside `op_counts()`, so no global variable is used.

## Algorithms

### Data structure

Each stack is a **circular doubly linked list** (`t_stack`), and the stack pointer always points at the top node.

- `ra` / `rra` only move the top pointer one node forward or backward, so they take O(1) time and no node is moved.
- `pa` / `pb` unlink the top node from one list and link it as the new top of the other.
- `sa` / `sb` relink the first two nodes.

### Index normalization

Before sorting, `index_stack()` gives every node a **rank** in `0 … n-1`: it copies the stack, sorts the copy, and looks up each node's position in the sorted copy. Medium and Complex work on these ranks instead of the raw values. This makes them independent of value range and sign (for example `-2147483648` and `5000` are handled the same way), and lets the algorithms reason about positions like "the lowest 20%".

### Disorder metric

`compute_disorder()` follows the subject's definition:

```
disorder = number of pairs (i < j) with a[i] > a[j]  /  (n(n-1)/2)
```

It is computed **once, before any operation is performed**. A sorted stack has disorder 0 and a reversed stack has disorder 1.

### Simple — O(n²): minimum extraction

1. While more than 3 elements remain in `a`, find the minimum. Bring it to the top using the cheaper of `ra` and `rra` (at most `remaining / 2` rotations), then `pb` it.
2. Sort the last 2–3 elements of `a` with `sort_three` in **at most 2 operations**: move the largest to the bottom with `ra` or `rra`, then `sa` if the top two are out of order.
3. `pa` everything back. The minimums were pushed in increasing order, so they come back in sorted order.

**Bound:** each extraction costs at most n/2 rotations plus one push. That gives Σ (k/2 + 2) ≤ n²/4 + 2n, which is **O(n²)** operations. Extra space is O(1).

For 5 numbers this uses at most **10 operations**. For 3 numbers it uses at most **2**.

### Medium — O(n√n): chunk sorting

The ranks are split into `k = ⌊√n⌋ / 2` consecutive ranges, called chunks. The last chunk takes whatever remains.

**Phase 1 — push to `b` chunk by chunk, from the smallest chunk to the largest:**
1. For the current chunk, find the element of `a` that belongs to it and is closest to the top or the bottom (`find_chunk_move`). The function returns a signed count: positive means that many `ra`, negative means that many `rra`.
2. Rotate that element to the top and `pb` it.
3. If the element is in the **lower half** of its chunk, `rb` sends it to the bottom of `b`. Otherwise it stays on top. Larger elements of each chunk collect near the top of `b` and smaller ones near the bottom, so no element ends up deep in the middle.

**Phase 2 — rebuild `a`:** repeatedly look up the largest rank still in `b`, bring it to the top with the cheaper of `rb` and `rrb`, and `pa` it. The largest elements go first, so `a` ends up in ascending order.

**Bound:** in phase 1, each chunk costs O(n) rotations, so the total is O(n·k). In phase 2, the target is always inside the current chunk's region of `b`, which holds about n/k elements, so each `pa` costs O(n/k) rotations and the total is O(n²/k). With k ≈ √n both terms are **O(n√n)**. We use √n/2 because it gave fewer operations in our tests. Extra space is O(n) for the rank copy.

### Complex — O(n log n): two-sided LSD radix sort

The algorithm sorts the ranks bit by bit, from the least significant bit to the most significant one, over `⌈log₂ n⌉` rounds. A plain radix sort sends every 0-bit element to `b` and pushes all of them back after each round. Our version keeps `b` as the "0 bucket" between rounds:

1. `process_b`: for each element in `b`, if its current bit is 1 it goes back to `a` (`pa`). Otherwise it stays in `b` (`rb`).
2. `process_a`: for each element in `a`, if its current bit is 0 it goes to `b` (`pb`). Otherwise it stays in `a` (`ra`).
3. After the last round, everything left in `b` is pushed back with `pa`.

Each round is a stable partition on one bit, which is what makes LSD radix sort correct. An element whose bit stays 0 for two rounds in a row costs a single `rb` instead of `pa` + `pb`. This saves about 15% compared to the plain version (500 numbers: 6784 → 5765 operations).

**Bound:** each round touches every element a constant number of times, which is O(n), over ⌈log₂ n⌉ rounds, giving **O(n log n)** operations. The cost depends only on n, not on the input order. Extra space is O(n) for the rank copy.

### Adaptive — choosing by disorder

Before any move, `sort_adaptive()` measures the disorder and picks one of the methods above:

| Condition                    | Method used                  | Cost       |
|------------------------------|------------------------------|------------|
| n ≤ 5                        | Simple (with `sort_three`)   | ≤ 10 ops   |
| disorder < 0.2               | Simple (minimum extraction)  | O(n²)      |
| 0.2 ≤ disorder < 0.5         | Medium (chunks)              | O(n√n)     |
| disorder ≥ 0.5               | Complex (radix)              | O(n log n) |

**Rationale for the thresholds and techniques:**
- **Low disorder (< 0.2):** the subject requires an O(n²) method in this regime. When the input is nearly sorted, many minimums are already close to the top, so minimum extraction needs few rotations in practice. It also uses no extra memory.
- **Medium disorder (0.2 – 0.5):** chunk sorting benefits from partial order, because elements of the same chunk tend to be close together. In our measurements it is cheaper than radix sort for this kind of input.
- **High disorder (≥ 0.5):** radix sort has a fixed cost that does not depend on input order, so it gives a safe upper bound on fully random input.
- **n ≤ 5:** the size is a constant, so all three methods are bounded by a constant. The Simple path gives the shortest output.

**Space:** every regime uses O(n) memory: the two stacks hold n nodes in total, plus the temporary rank copy.

When a strategy flag is given (`--simple`, `--medium` or `--complex`), that algorithm is used for **every** input size, as the subject requires.

## Performance

Measured on random inputs with values in `[-2³¹, 2³¹)`, 30 runs per row:

| Strategy                 | 100 numbers (avg / max) | 500 numbers (avg / max) |
|--------------------------|-------------------------|-------------------------|
| Adaptive (default)       | 785 / 913               | 5838 / 6048             |
| Medium                   | 666 / 709               | 5935 / 6138             |
| Complex                  | 913 / 913               | 5765 / 5765             |
| Simple                   | 1432 / 1718             | ~32 600 (O(n²))         |

The default mode stays below the subject's "good" thresholds (1500 / 8000).

## Testing

The following checks were run before submission:
- Every permutation of 1 to 7 elements was sorted correctly with each flag. Correctness was checked by a simulator that replays the printed operations.
- Random inputs of 100 and 500 numbers, and nearly sorted inputs.
- Error cases from the subject, plus overflow, `-0 0`, empty strings, a lone `+` or `-`, and repeated or unknown flags.
- `valgrind --leak-check=full` reports 0 bytes in use at exit and 0 errors for every strategy and for the error and sorted-input paths.
- `norminette` reports no errors, including on `libft`.

## Resources

- [Big O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Sorting algorithm — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Selection sort — Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Bucket sort — Wikipedia](https://en.wikipedia.org/wiki/Bucket_sort) (the idea behind chunk sorting)
- [Inversion (discrete mathematics) — Wikipedia](https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)) (the disorder metric)
- [Doubly linked list — Wikipedia](https://en.wikipedia.org/wiki/Doubly_linked_list)

### AI usage

We used AI assistants (Claude) for the following tasks:
- **Explanations:** how chunk-based sorting works, walked through on a small example by hand, and how LSD radix sort works.
- **Norm formatting:** fixing indentation and alignment errors reported by `norminette`. Only formatting was changed, not logic.
- **Documentation:** drafting this README.

## Contributions

**beakduma**
- Stack operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr` on the circular doubly linked list.
- `t_stack` construction and cleanup: `build_stack`, `free_stack`.
- Disorder metric (`compute_disorder`).
- Simple strategy (minimum extraction) and the small-stack case (`sort_three`).
- Medium strategy (chunk sorting: `sort_medium`, `find_chunk_move`, `push_chunk`, `push_back_to_a`).
- Benchmark mode and operation counting (`bench.c`, `op_counter.c`).
- Adaptive dispatcher (`sort_adaptive`, `sort_stack`) and integration in `main.c`.

**mehaslan**
- Argument parsing: `t_data`, `parse_args`, `control_numbers`, and support for separate arguments and quoted strings via `ft_split`.
- Flag validation: `--bench`, `--simple`, `--medium`, `--complex`, `--adaptive`. Flags must come before the numbers, and repeated or conflicting flags are rejected.
- Safe integer parsing (`atoi_safety`, `is_valid_numbers`) with strict 32-bit limits, duplicate detection (`is_duplicate`), and leak-free error handling (`error_exit`, `free_data`, `free_args`).
- Index normalization (`copy_stack`, `selection_sort`, `assign_index`, `index_stack`), shared by Medium and Complex.
- Complex strategy: two-sided LSD radix sort (`sort_complex`, `process_a`, `process_b`, `get_max_bits`).
- libft integration and Makefile.
