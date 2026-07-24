# Question 1 - Linux Shell Scripting Assignment

## Objective

Design a shell script that:

- Identifies duplicate submissions.
- Creates a backup of unique submissions.
- Generates a report.
- Stores error messages separately.

---

## Files Included

- backup.sh
- report.txt
- errors.log
- submissions/
- backup/
- screenshots/

---

## Linux Commands Used

### mkdir
Creates directories required for organizing the assignment files.

### cd
Changes the current working directory.

### pwd
Displays the current working directory.

### ls
Lists files and directories to verify the results.

### touch
Creates empty files.

### echo
Writes sample data into submission files.

### cp
Copies unique files into the backup folder.

### cat
Displays the contents of report and log files.

### chmod +x
Makes the shell script executable.

### ./backup.sh
Executes the shell script.

### md5sum
Generates an MD5 hash for each file to detect duplicate content.

### awk
Extracts only the hash value from the md5sum output.

---

## Redirection Operators Used

### >
Redirects output to a file and overwrites its contents.

Example:

echo "Assignment by Alice" > submissions/alice.txt

---

### >>

Appends output to an existing file.

Example:

echo "Files Processed : 5" >> report.txt

---

### 2>>

Redirects error messages to the error log file.

Example:

cp file backup/ 2>> errors.log

---

## File Handling Techniques

- Created sample submission files.
- Compared files using MD5 hashing.
- Copied only unique files into the backup directory.
- Generated a report containing processed, duplicate, and backed-up file counts.
- Stored any errors in a separate log file.

---

## Output Summary

- Total Files Processed: 5
- Duplicate Files: 2
- Files Backed Up: 3

The script successfully detected duplicate submissions, backed up unique files, generated a report, and stored errors separately.