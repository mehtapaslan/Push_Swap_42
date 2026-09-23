*This project has been created as part of the 42 curriculum by beakduma, mehaslan.*

# Push_swap

## Description

**Push_swap** is a sorting algorithm project built around a very constrained model: you are given a random, duplicate-free list of integers loaded into stack `a`, an empty stack `b`, and a small set of operations (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`) to manipulate them.

The goal is to write a C program that computes and prints, to standard output, the **smallest possible sequence** of these operations that sorts stack `a` in ascending order.

Beyond just "sort the stack," this project's real objective is to explore **algorithmic complexity in practice**: the program implements and can select between four distinct sorting strategies (`O(n²)`, `O(n√n)`, `O(n log n)`, and an adaptive strategy that picks its internal method based on a measured *disorder* score), with the cost measured directly in the number of Push_swap operations generated — not textbook array complexity.

A `checker` bonus program is also included to validate that a given operation sequence actually sorts stack `a` correctly.

## Instructions

### Compilation

```bash
make          # builds the push_swap binary
make bonus    # builds the checker binary (bonus)
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + all
```

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <list of integers>
```

- No arguments → no output, program returns silently.
- Invalid arguments (non-integers, out-of-range values, duplicates) → prints `Error` to `stderr`.
- If no strategy flag is given, `--adaptive` is used by default.
- `--bench` prints benchmark metrics (disorder %, strategy used, total operation count, per-operation breakdown) to `stderr`, while the operation sequence itself stays on `stdout`.

**Examples:**

```bash
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
```

### Checker (bonus)

```bash
./checker <list of integers>
```

Reads operations from `stdin` (one per line) and executes them against the given stack. Prints `OK` if the result is sorted and `b` is empty, `KO` otherwise, and `Error` to `stderr` on invalid input.

## Algorithms

The project implements four distinct sorting strategies, selectable at runtime, all generating sequences of Push_swap operations against a **circular doubly linked list** representation of the stacks (which keeps rotate/reverse-rotate operations at O(1) — see the technical-choices note below).

- **Simple — O(n²):** [describe which baseline method you implemented, e.g. selection-sort-style repeated min extraction — explain the logic and why it fits n²]
- **Medium — O(n√n):** [describe your chunk/bucket-based method, why √n buckets, how elements are dispatched and reassembled]
- **Complex — O(n log n):** [describe your chosen method, e.g. radix sort on the operation stream, or a stack-adapted merge/quicksort]
- **Adaptive:** Measures the stack's *disorder* before making any move (fraction of inverted pairs among all pairs, per the subject's `compute_disorder` definition) and dispatches to an internal method meeting the required complexity target for that regime:
  - disorder `< 0.2` → O(n²) regime
  - `0.2 ≤` disorder `< 0.5` → O(n√n) regime
  - disorder `≥ 0.5` → O(n log n) regime

  *[Explain here why you chose these particular internal techniques per regime, and give a brief upper-bound argument for time and space in the Push_swap operation model.]*

### Technical choice: circular doubly linked list

Stacks are represented as circular doubly linked lists rather than arrays. This means:
- `ra`/`rb`/`rr` and `rra`/`rrb`/`rrr` only move a `top` pointer to the next/previous node — no elements are physically shifted, making these O(1) instead of the O(n) an array-shift would cost.
- `pa`/`pb` unlink a node from one list and relink it as the new top of the other list.
- `sa`/`sb`/`ss` swap the values of the top two nodes in place.

## Resources

- [Big-O notation / algorithmic complexity — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Sorting algorithm — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Stack (abstract data type) — Wikipedia](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Circular doubly linked list overview](https://en.wikipedia.org/wiki/Doubly_linked_list)
- *[Add here any specific tutorials/articles you personally used, e.g. on radix sort or Turkish-language sources on push_swap]*

### AI usage disclosure

AI (Claude) was used during this project for the following, limited purposes:
- Explaining conceptually what the 11 Push_swap operations correspond to when implemented on a circular doubly linked list (no code was generated or copy-pasted from AI for the core sorting algorithms).
- Assisting in drafting the structure of this README file, in line with the subject's Readme Requirements.

All sorting algorithms, the disorder-based adaptive strategy, and the circular linked list implementation were designed and written by beakduma and mehaslan, and both learners are able to explain and defend every part of the code during the evaluation.

## Contributions

- **beakduma**:
- Designed and implemented the `t_stack` data structure (circular doubly linked list) along with `build_stack` and `free_stack` for stack construction/cleanup.
- Implemented all stack manipulation operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- Implemented the mandatory disorder metric (`compute_disorder`), measuring how far stack `a` is from being sorted (ratio of inverted pairs).
- Implemented the Simple (O(n²)) sorting strategy using a selection-sort-based approach: repeatedly finds the minimum among the remaining elements, rotates it to the top using the shorter of `ra`/`rra`, pushes it to stack `b`, then pushes everything back to `a`.
- **mehaslan**:
- Designed and implemented the `t_data` state structure along with `parse_args` and `control_numbers` for command-line argument extraction, supporting both individual arguments and space-delimited string inputs via `ft_split`.
- Implemented all configuration and strategy flag validations: `--bench`, `--simple`, `--medium`, `--complex`, `--adaptive`, ensuring these options strictly precede numeric inputs while actively rejecting redundant or conflicting flags.
- Implemented the safe integer conversion mechanism (`atoi_safety`), checking character validity (`is_valid_numbers`) and using pointer-based feedback to enforce strict 32-bit signed limits, effectively preventing arithmetic overflow before it occurs.
- Implemented the dynamic array population (`add_nbr`) and memory management system: repeatedly checks for duplicates (`is_duplicate`) during array reallocation, immediately intercepts invalid syntaxes, and guarantees zero memory leaks on any failure state via centralized cleanup (`error_exit`, `free_data`, `free_args`).