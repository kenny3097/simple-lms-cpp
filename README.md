# Simple Library Management System (C++)

## Project Overview
This is a **Simple Library Management System (LMS)** developed in C++ to demonstrate **Object-Oriented Programming (OOP) concepts** and core C++ features.  
The system allows users to manage books, borrow and return them, merge inventories, and view a weekly borrow schedule.  

This project showcases:
- Classes, objects, and encapsulation  
- Inheritance and polymorphism  
- Operator overloading and function overloading  
- Dynamic arrays and pointer arithmetic  
- Exception handling  
- 1D and 2D arrays  
- Constructors and destructors  

---

## Features
1. **User Inventory Management** – Add, borrow, and return books.  
2. **Merging Inventories** – Combine multiple inventories using operator overloading.  
3. **Weekly Borrow Schedule** – Display a 2D array schedule.  
4. **Exception Handling** – Handles borrowing when no copies are available.  
5. **OOP Demonstrations** – Inheritance (`Person`, `User`, `Admin`), polymorphism, and encapsulation.  

---

## How to Run the Program

### Requirements
- C++ compiler (g++, MinGW on Windows, or any C++ compiler)  
- GitHub Desktop and Visual Studio Code (optional, for editing and version control)  

### Steps
1. Clone the repository:
```bash
git clone https://github.com/your-username/simple-lms-cpp.git

2. Navigate to the repository folder:

cd simple-lms-cpp

3.  Compile the program:

g++ LibrarySystem.cpp -o LibrarySystem

4.  Run the executable:

LibrarySystem.exe


Testing the Program



1. Borrowing a Book

Action: Borrow "C++ Basics" from User Inventory.

Expected Output: Copies decrease from 5 → 4.

Actual Output:

C++ Basics | John | 123 | Copies: 4
OOP Concepts | Alice | 234 | Copies: 3


2. Merging Inventories

Action: Merge two inventories: lib1 (Python) and lib2 (Java).

Expected Output: Both books appear in merged inventory.

Actual Output:

Python | Ann | 345 | Copies: 4
Java | Bob | 456 | Copies: 2


3. Weekly Borrow Schedule (2D Array)

Action: Display schedule for a week.

Expected Output: Shows 7 days with morning/evening slots.

Actual Output:


Day 1: Borrow: C++ Book | Evening: None
Day 2: Morning: None | Evening: None
...
Day 7: Morning: None | Evening: None



4. Exception Handling

Action: Borrow a book with 0 copies.

Expected Output: Error message is displayed.

Actual Output:

No copies available for [Book Name]








