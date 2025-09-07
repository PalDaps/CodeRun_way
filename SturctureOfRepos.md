# CodeRun_way Repository Structure

## 1. General Repository Structure

```
CodeRun_way/
├── CodeRun_i/        # Folder for each task
│   ├── Attempt/      # Attempts to solve the task on your own
│   ├── OwnOptimal/   # My own optimal solutions
│   └── Optimal/      # Optimal solutions (mix of my approach + internet solutions + other users' solutions)
```
---

### Folder Descriptions:

- **Attempt/** — All working attempts at solving the task. Sometimes they even pass tests, but often they are not optimal or poorly readable (e.g., O(n²) solution when optimal is O(n)).
- **OwnOptimal/** — My best solution that I reached on my own, close to the reference/optimal solution.
- **Optimal/** — Optimal solutions from various sources (internet, editorials, other users’ approaches). Often combines my approach with others' ideas.

---

## 2. Solution Files

- All solutions are stored as `source.cpp`.
- At the beginning of each file, it is recommended to include a **preamble** to structure your thoughts:

```cpp
/*

XX.XX.XXXX - Date when the solution was started
XX:XX - Time when the solution was started

Task: - The text of the task, after reading it and understanding what needs to be done.

Idea: - Short summary of the solution (1–2 sentences).

Solution: - Detailed description of the solution. You can describe each line of code as thoroughly as needed.

Brainstorm: - Space for recording thoughts, ideas, and reasoning during the problem-solving process.

P.S. | XX.XX.XXXX | XX:XX: - Additional notes, comments, or observations.
       If a date and time are indicated, it marks the moment the thought was recorded.
       If no date is provided, the note was made during the process of solving the task.

*/
```

## 3. Improving the Structure

To make the repository even more useful and visual:

- Add a .excalidraw file in each folder (Attempt/, OwnOptimal/, Optimal/) to schematically represent the solution or algorithm.
- Add a test.cpp file in each task folder to store test cases. This file can be used to quickly run your solution against sample inputs and check correctness.