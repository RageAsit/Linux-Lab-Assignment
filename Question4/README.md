# Question 4 - Linux Log Monitoring

## Objective

Develop a shell command pipeline that:

- Continuously monitors a log file.
- Filters only ERROR messages.
- Stores errors in a separate report.
- Suppresses unnecessary error messages.

---

## Files Included

- system.log
- error_report.txt
- screenshots/

---

## Commands Used

### tail -f

Continuously monitors new log entries.

### grep --line-buffered "ERROR"

Filters only log entries containing the word "ERROR". The `--line-buffered` option ensures each matching line is processed immediately in a pipeline.

### >>

Appends matching log entries to `error_report.txt`.

### 2>/dev/null

Redirects error messages to `/dev/null`, preventing them from appearing in the terminal.

### cat

Displays the contents of the log and report files.

---

## How the Pipeline Works

1. `tail -f` continuously watches the log file.
2. Output is passed through a pipe (`|`) to `grep`.
3. `grep` filters only ERROR messages.
4. Matching lines are appended to `error_report.txt`.
5. Any error messages are discarded using `/dev/null`.

---

## Sample Pipeline

```bash
tail -f system.log | grep --line-buffered "ERROR" >> error_report.txt 2>/dev/null
```

---

## Sample Output

```
ERROR Memory usage exceeded
ERROR Network timeout
```