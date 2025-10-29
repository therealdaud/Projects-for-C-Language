# Projects-for-C-Language
C Language Projects Collection (10 Mini Projects)

This repository contains 10 C programming mini-projects that practice core concepts: arrays, pointers, strings, dynamic memory, file I/O, sorting, and basic data structures (linked lists & queues).
Each project lives in its own folder (Project 1 … Project 10) with a focused problem and a small, self-contained program.

---

✨ Features

- Hands-on practice with arrays, pointers, and dynamic memory

- String processing (tokenization, splitting, scoring)

- File I/O with CSV/text parsing and writing

- Sorting & selection patterns

- Linked list queue for a registration system

- Modular design with header/implementation separation and a Makefile (Project 10)

- Clear build & run examples for each project

---

## 📂 Project Structure

- **Project 1/**

  - `project1_bounce_house.c`


- **Project 2/**

  - `project2_task1.c`

  - `project2_task2.c`


- **Project 3/**

  - `project3_task1.c`

  - `project3_task2.c`


- **Project 4/**

  - `project4_task1.c`

  - `project4_task2.c`


- **Project 5/**

  - `project5_task1.c`

  - `project5_task2.c`


- **Project 6/**

  - `project6_tokenizer.c`


- **Project 7/**

  - ``project7_studio (1).c``


- **Project 8/**

  - `project8_registration.c`


- **Project 9/**

  - `project9_registration.c`

  - `project9_studio.c`


- **Project 10/**

  - `makefile`

  - `project10_registration.c`

  - `student.c`

  - `student.h`

---

🧪 How to Build & Run

You’ll need a C compiler (e.g., gcc or clang).
All examples below use gcc -std=c99 -Wall.

Project 1 — Bounce House Cost Calculator

Calculates rental charges based on bounce house type and hours/days.

````bash
cd "Project 1"
gcc -std=c99 -Wall project1_bounce_house.c -o project1
./project1

````

Project 2 — Oscillations & Sequence Scoring

Task 1: Count “oscillating” grades relative to prior values.

Task 2: Score two letter sequences and declare the winner.

````bash
cd "Project 2"
gcc -std=c99 -Wall project2_task1.c -o p2_task1
gcc -std=c99 -Wall project2_task2.c -o p2_task2
./p2_task1
./p2_task2
````

Project 3 — Good Sequence Check & Distinct Sort

Task 1: “Good” sequence if each number is a perfect square or < n.

Task 2: Remove duplicates then sort ascending.

````bash
cd "Project 3"
gcc -std=c99 -Wall project3_task1.c -o p3_task1
gcc -std=c99 -Wall project3_task2.c -o p3_task2
./p3_task1
./p3_task2
````

Project 4 — End-Pick Game & Before/After Counts

Task 1: Game where players pick from ends to maximize their sum.

Task 2: For each element, count occurrences before and after it (pointer arithmetic).

````bash
cd "Project 4"
gcc -std=c99 -Wall project4_task1.c -o p4_task1
gcc -std=c99 -Wall project4_task2.c -o p4_task2
./p4_task1
./p4_task2
````

Project 5 — Split Two Words & Word Scoring

Task 1: Split a two-word input string into separate words.

Task 2: Score two words (letter-based rules) and declare winner.

````bash
cd "Project 5"
gcc -std=c99 -Wall project5_task1.c -o p5_task1
gcc -std=c99 -Wall project5_task2.c -o p5_task2
./p5_task1
./p5_task2   # expects two words via stdin/args depending on the implementation
````

Project 6 — File Tokenizer

Tokenizes text: builds a dictionary of unique words (alphabetical), then outputs token IDs per sentence.

````bash
cd "Project 6"
gcc -std=c99 -Wall project6_tokenizer.c -o tokenizer
./tokenizer input.txt output.txt
````

Project 7 — Customer Filter (CSV)

Reads customers, filters by minimum lessons taken, writes filtered list to CSV.

````bash
cd "Project 7"
gcc -std=c99 -Wall "project7_studio (1).c" -o p7
./p7
````

Project 8 — Registration Queue (Linked List)

Menu-driven queue for students: add, pop, list, filter by GPA or grade, clear.

````bash
cd "Project 8"
gcc -std=c99 -Wall project8_registration.c -o p8
./p8
````

Project 9 — Registration (Variant) & CSV Sorter

registration.c: Similar queue manager with attempts/GPA/grade filtering.

studio.c: Read CSV, sort by lessons (descending), write a new CSV.

````bash
cd "Project 9"
gcc -std=c99 -Wall project9_registration.c -o p9_reg
gcc -std=c99 -Wall project9_studio.c -o p9_studio
./p9_reg
./p9_studio
````

Project 10 — Modular Registration System (with Makefile)

Modularized queue manager (student.h/.c, project10_registration.c) with a Makefile.

````bash
cd "Project 10"
make           # builds 'project10_registration'
./project10_registration
# Clean:
make clean
````

---

▶️ Example Inputs/Outputs (Typical)

Interactive programs prompt for values (e.g., names, NetIDs, GPA, grades).

File-based programs expect filenames (e.g., input.txt, output.csv) and will write formatted results.

Tip: If you’re on Windows and the resulting binary is *.exe, call .\binaryname.exe accordingly.

🎯 Learning Outcomes

Strengthened C fundamentals: control flow, arrays, strings, pointers

Implemented dynamic memory and pointer arithmetic

Practiced CSV/text parsing and file output

Built a small linked list queue with modular headers/impl files

Used a Makefile for multi-file builds

🧰 Requirements

C compiler: gcc or clang

make (for Project 10)

A terminal/shell to compile and run programs

📜 Authors

Daud Ahmad Nisar
Computer Science Student at the University of South Florida
daudnisar1@gmail.com

📄 License

This repository includes a LICENSE. See that file for terms.
