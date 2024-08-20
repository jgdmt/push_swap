# Push Swap - 42Cursus Project

**Push swap** is a **42 cursus** project that requires sorting data on a stack with a limited set of operations and another stack. The goal is to sort the stack using as few moves as possible. The project challenges you to create an efficient algoritm.

## ✨ Project Overview

The program takes a list of integers as input and sorts them using two stacks (`a` and `b`) and the following operations:
- `sa` (swap a): Swap the first two elements at the top of `a`.
- `sb` (swap b): Swap the first two elements at the top of `b`.
- `ss`: `sa` and `sb` at the same time (counts as one operation).
- `pa` (push a): Take the element at the top of `b` and put it at the top of `a`.
- `pb` (push b): Take the element at the top of `a` and put it at the top of `b`.
- `ra` (rotate a): Shift up all elements of `a` by one. The first element becomes the last one.
- `rb` (rotate b): Shift up all elements of `b` by one. The first element becomes the last one.
- `rr`: `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shift down all elements of `a` by one. The last element becomes the first one.
- `rrb` (reverse rotate b): Shift down all elements of `b` by one. The last element becomes the first one.
- `rrr`: `rra` and `rrb` at the same time. 

## ⭐ Mandatory Part

### Parsing
The program does not take arguments other than integers or duplicates. 

### Algorithm
The algorithm used follows thoses steps:
- Push all elements but three from `a` to `b`.
- Sort the three elements left in `a` using as few moves as possible.
- For each element in `b`, calculate the minimum moves required to push it to `a` in the right place.
- Push the element that requires the fewest moves to the right place in `a`.
- Loop until `b` is empty.
- Rotate or reverse rotate until `a` is sorted.

### Usage
The program takes a list of integers as argument. It will output each operation it does to sort the stack.

## 💫 Bonus Part
The bonus part requires to create a **checker**. It will check whether the operations sorted the stack correctly.

## 🛠️ Installation & Compilation Guide

### 📦 Dependencies

Make sure you have the following installed:

- **GCC** or another C compiler
- **Make**

### 🏗️ Compilation

Clone the repository:
```bash
git clone https://github.com/jgdmt/push_swap.git
```
Compile (executable is `push_swap`):
```bash
make
```
Compile the bonus (executable is `checker`):
```bash
make bonus
```

## 🚀 Usage

**Mandatory Part**
Run the program:
```bash
./push_swap [list of integers]
```

**Bonus Part**
Run the checker with `push_swap`:
```bash
ARG="[list of integers]"; ./push_swap $ARG | ./checker $ARG
```
It will read the ouputs of `push_swap` and execute the same operations then check if the stack is sorted at the end.
