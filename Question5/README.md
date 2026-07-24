# Question 5 - Recovery Mechanisms in vi/vim

## Objective

Evaluate the recovery mechanisms available in vi/vim when the system crashes before a file is saved.

---

## Recovery Mechanisms

### 1. Swap Files (.swp)

- Vim automatically creates a swap file while editing.
- If the editor or system crashes, the swap file can be used to recover unsaved changes.
- Recovery command:

```bash
vim -r config.conf
```

---

### 2. Undo History

- Vim stores recent editing actions in memory.
- Changes can be reversed using:

```vim
u
```

- Persistent undo history is available if the `undofile` option is enabled.

---

### 3. Registers

- Registers temporarily store copied or deleted text.
- They help recover accidentally deleted content during the editing session.

Example:

```vim
"ap
```

---

### 4. Backup Files

- If backup mode is enabled, Vim creates backup copies of files before saving.
- These backups can restore the previous saved version.

---

### 5. Auto-Recovery

- When Vim detects an existing swap file after an unexpected shutdown, it offers recovery options automatically when reopening the file.

---

## Most Reliable Recovery Strategy

The most reliable recovery method is **using Vim swap files together with backup files**.

### Justification

- Swap files preserve unsaved edits after unexpected crashes.
- Backup files protect the last saved version.
- Undo history helps reverse accidental edits.
- Registers help recover deleted text during editing.

Using swap files and backup files together provides the highest chance of recovering both unsaved and previously saved work.

---

## Commands Used

```bash
vim config.conf
vim -r config.conf
ls -la
```

---

## Conclusion

Vim provides several recovery mechanisms including swap files, undo history, registers, backup files, and auto-recovery. Among these, swap files combined with backup files offer the most reliable recovery strategy because they protect both unsaved changes and previously saved data after unexpected failures.