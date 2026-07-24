# Question 3 - File Processing using Linux System Calls

## Objective

Design a program that:

- Creates a file.
- Writes employee records.
- Updates specific records without rewriting the whole file.
- Retrieves records efficiently.

---

## Files Included

- file_processor.c
- file_processor (Executable)
- employees.txt
- screenshots/

---

## Commands Used

### gcc file_processor.c -o file_processor

Compiles the C source file.

### ./file_processor

Executes the program.

### ls

Lists all generated files.

### cat employees.txt

Displays the contents of the employee file.

---

## Linux System Calls Used

### open()

Creates or opens the employee file.

### write()

Writes employee records into the file.

### lseek()

Moves the file pointer to update a specific record without rewriting the entire file.

### read()

Reads employee records from the file.

### close()

Closes the file and releases system resources.

---

## How the Solution Works

1. The program creates a file using `open()`.
2. Employee records are written using `write()`.
3. `lseek()` moves the file pointer to update a record.
4. `read()` retrieves the file contents.
5. `close()` safely closes the file.

---

## Explanation

Linux system calls provide direct interaction with the operating system. Using `open()`, `write()`, `lseek()`, `read()`, and `close()` allows efficient file manipulation without relying on higher-level standard library functions.

---

## Sample Output

```
Employee Records:
101 Alice Manager
102 Senior Engineer
103 Charlie HR
```