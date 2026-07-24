# Question 2 - Process Management using fork()

## Objective

Design a C program that:

- Creates child processes using `fork()`.
- Monitors child execution.
- Prevents zombie processes.
- Terminates unresponsive child processes using signals.

---

## Files Included

- process_manager.c
- process_manager (Executable)
- screenshots/

---

## Commands Used

### gcc process_manager.c -o process_manager

Compiles the C source file into an executable.

### ./process_manager

Runs the executable.

### ls

Lists the files in the current directory.

---

## System Calls Used

### fork()

Creates a new child process.

### waitpid()

Allows the parent process to wait for the child process to finish, preventing zombie processes.

### kill()

Sends a signal (`SIGTERM`) to terminate the unresponsive child process.

### sleep()

Simulates a long-running child process.

---

## How the Solution Works

1. The parent creates a child process using `fork()`.
2. The child begins execution and intentionally sleeps.
3. The parent waits for a short period.
4. If the child is still running, the parent sends a `SIGTERM` signal.
5. The parent calls `waitpid()` to collect the child's exit status and prevent zombie processes.

---

## Explanation

- `fork()` creates a duplicate process.
- `kill()` is used to terminate an unresponsive child.
- `waitpid()` ensures that the child process is properly cleaned up and does not remain as a zombie.
- This approach helps keep the system responsive and avoids resource leaks.

---

## Sample Output

```
Parent Process. PID = xxxx
Created Child with PID = xxxx
Child Process Started. PID = xxxx
Checking child process...
Child is taking too long. Sending SIGTERM...
Child process terminated successfully.
Zombie process prevented using waitpid().
```