# Simple Command Line Parser (CLI)

This is simple CLI Parser library, codded in C. This acts as a pattern for further developments in the embedded bootcamp program.

The project uses **Command Pattern (Lookup Table)** together with **Function Pointer** helps the code structure easier to read, differentiate the Parser part and the Handlers.

## Noticable features

* **No dynamic memory allocation:** Does not use `malloc` or `free`, completely eliminating the risk of memory fragmentation on MCU.
* **High scalabitiy:** Adding a new command simply requires writing a new handler function and adding a new line to the command table. No modification to the Parser needed.
* **Comprehensive error handling:** Robust exception handling with clean Status Code: 
  * `CMD_NOT_FOUND`: The command does not exist.
  * `CMD_TOO_LONG`: Prevent buffer overflow when handling excessively long strings.
  * `CMD_EMPTY`: Ignore empty commands.
  * `CMD_INVALID_ARG`: Catches invalid argument errors at the handler layer.

## Project structures 

* `cmd_line.h`: Defines data structure (`cmd_line_t`), function pointer types and Status Codes.
* `cmd_line.c`: Core source code containing the `cmd_line_parser` function, tokenizing strings and performing lookups.
* `main.c`: The Application Layer, contains specific handler functions (e.g: `led_handler`, `help_handler`), command table initialization, and simulated UART communication loop.

## Build, run, results 

The project can be compiled and executed directly on your computer using `GCC` (supports Windows, Linux/WSL, and macOS).

**Step 1: Compile the source code**
Open your Terminal in the project directory and run the following command:
```bash
gcc main.c cmd_line.c -o test_app
```
**Step 2: Run the application** 
```bash
./test_app
```

## Test Result
<img width="868" height="386" alt="image" src="https://github.com/user-attachments/assets/2dd386a2-b76b-486d-9d4e-fd7c9b32e465" />

## 📝 Credits
* **Author:** Honag
* **Credit:** Based on the source code and idea of GaoKong (Mentor Trong Than)
* **Date:** 08 - 04 - 2026
    




