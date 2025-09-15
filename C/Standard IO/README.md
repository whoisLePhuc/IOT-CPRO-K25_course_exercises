# 📘 How the Logger Program Works

This document explains how the C Logger module works internally and how it should be used in your application.

## 🧠 Overview

The logger module is responsible for writing structured log messages to the console and optionally to a file. It includes metadata like timestamp, source file, and line number. Log messages can be filtered by severity level.


## 🔄 Execution Flow

### 1. ✅ Logger Initialization

```c
logger_init(LOG_INFO, "log_output.txt");
```

- Sets the minimum log level.
- Opens the log file (if provided) for appending.
- Stores the file pointer and log level for internal use.


### 2. 🧾 Logging a Message

Use the macro:

```c
log_message(LOG_ERROR, "Failed to connect: code %d", error_code);
```

- Automatically captures the current `__FILE__` and `__LINE__`.
- Calls the internal `logger_log()` function.


### 3. ⚙️ Inside `logger_log(...)`

Performs the following steps:

#### a. Filter by level

```c
if (level > current_level) return;
```

Skips messages below the configured level.

#### b. Get timestamp

```c
time_t now = time(NULL);
strftime(buffer, ...); // format: YYYY-MM-DD HH:MM:SS
```

#### c. Format message

Uses `vsnprintf()` to safely format the message with variable arguments.

#### d. Add metadata

Final message format:

```
[YYYY-MM-DD HH:MM:SS] [LEVEL] [FILENAME:LINE] - Message
```

#### e. Output the log

- If level is `LOG_ERROR` or more severe → prints to `stderr`.
- Otherwise → prints to `stdout`.
- If a log file is open → also writes to file.

---

### 4. 🔄 Changing Log Level at Runtime

You can change the filtering level during execution:

```c
logger_set_level(LOG_DEBUG);
```

Now more detailed logs (e.g. `LOG_DEBUG`) will appear.

---

### 5. ❌ Closing the Logger

At the end of the program:

```c
logger_close();
```

Closes the log file and flushes any pending output.

---

## 🔁 Summary Flow

```
main() 
 └── logger_init(level, file)
     └── open file if given

log_message(level, ...)
 └── logger_log(...)
     ├── level filtering
     ├── timestamp generation
     ├── message formatting
     ├── console output
     └── optional file output

logger_set_level(...)  // adjust filtering

logger_close()         // cleanup
```

---

## 🎯 Conclusion

This logger module acts as a centralized logging system:
- Helps track errors and debug more easily.
- Provides structured log output.
- Is reusable and configurable for any C project.
