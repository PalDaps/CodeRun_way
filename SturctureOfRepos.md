# CodeRun_way Repository Structure

## 1. General Repository Structure

```
CodeRun_way/
├── CodeRun_i/                            # Folder for each task
│   ├── Attempt/                          # Attempts to solve the task on your own
│   ├── OwnOptimal/                       # My own optimal solutions
│   ├── Optimal/                          # Optimal solutions (mix of my approach + internet solutions + other users' solutions)
│   ├── CodeRun_i.excalidraw.md           # A diagram for the problem to make it easier
│   ├── Noted.md                          # A more detailed explanation of the issue, if necessary
│   └── Repeat/                           # Folder containing task retry attempts
│       └── 1/                            # First attempt to repeat the task
│       └── i/                            # Subsequent attempts to repeat the task    
```
---

### Folder Descriptions:

- **Attempt/** — All working attempts at solving the task. Sometimes they even pass tests, but often they are not optimal or poorly readable (e.g., O(n²) solution when optimal is O(n)).
- **OwnOptimal/** — My best solution that I reached on my own, close to the reference/optimal solution.
- **Optimal/** — Optimal solutions from various sources (internet, editorials, other users’ approaches). Often combines my approach with others' ideas.
- **CodeRun_i.excalidraw.md** — A diagram for the problem to make it easier to come up with an idea or simply understand the solution.
- **Noted.md** — A diagram for the problem to make it easier to come up with an idea or simply understand the solution.
- **Repeat/** — A folder containing attempts to repeat tasks, used to track changes in thinking over time.
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

Pattern: - To which well-known patterns does the task belong?

Solution: - Detailed description of the solution. You can describe each line of code as thoroughly as needed.

Complexity: - I calculate the algorithm's complexity to gauge its computational value.

Brainstorm: - Space for recording thoughts, ideas, and reasoning during the problem-solving process.

P.S. | XX.XX.XXXX | XX:XX: - Additional notes, comments, or observations.
       If a date and time are indicated, it marks the moment the thought was recorded.
       If no date is provided, the note was made during the process of solving the task.

*/
```

## 3. Improving the Structure

To make the repository even more useful and visual:

- Add a test.cpp file in each task folder to store test cases. This file can be used to quickly run your solution against sample inputs and check correctness.
- Add folders like easy, medium, hard for sorting tasks. And within them, various topics such as graphs, strings, dp, binary search, etc. Or vice versa.