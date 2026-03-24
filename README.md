# HomeworkWorkspace

This repository is organized as a **workspace launcher** plus **standalone task projects**.

- Root executable: `LauncherMain`
- Standalone tasks: `Task1`, `Task2`, `Task3`
- Build system: CMake (C++17)

## Project Layout

```text
project_root/
|- CMakeLists.txt
|- main.cpp
|- include/
|  `- Launcher.h
|- src/
|  `- Launcher.cpp
`- tasks/
   |- Task1/
   |- Task2/
   `- Task3/
```

Each task in `tasks/TaskN/` has its own `CMakeLists.txt`, `main.cpp`, and support files, so it can be developed as an independent mini-project while still being included in the root workspace.

## How the Launcher Works

The root program (`LauncherMain`) asks for a task name, for example `Task1`.

`Launcher` then performs these steps:

1. Builds the executable path for the selected task.
   - Example target: `build/tasks/Task1/Task1.exe` on Windows.
2. Reads `tasks/<TaskName>/in.txt`.
3. Removes newline characters from `in.txt` content so it becomes one argument string.
4. Builds the final command:
   - `<task_executable_path> <arguments_from_in.txt>`
5. Runs the command with `std::system()`.

The implementation uses platform macros to handle executable extension and path handling behavior.

## Build Instructions

### Requirements

- CMake >= 3.14
- A C++17 compiler
- Internet access on first configure (for `Task3`, which fetches `nlohmann_json`)

### Configure and Build

From `project_root`:

```powershell
cmake -S . -B build
cmake --build build
```

If your environment requires a specific generator/compiler (for example Cygwin GNU Make), pass generator/toolchain flags explicitly during configure.

## How to Run

### Run via Launcher (recommended)

From `project_root`:

```powershell
./build/LauncherMain.exe
```

Then type one of:

- `Task1`
- `Task2`
- `Task3`

The launcher will read that task's `in.txt` and execute the task with those arguments.

### Run Tasks Directly (optional)

```powershell
./build/tasks/Task1/Task1.exe 5 10 15
./build/tasks/Task2/Task2.exe
./build/tasks/Task3/Task3.exe "{\"name\":\"Student\",\"grade\":\"A\"}"
```

## What Each Task Does

- `Task1`: Parses integer CLI arguments and prints their sum (`calculateSum`).
- `Task2`: Demonstrates polymorphism with `Shape`, `Rectangle`, and `Circle`, then prints areas.
- `Task3`: Parses a JSON string using `nlohmann_json` and prints selected fields.

## Input Files

- `tasks/Task1/in.txt`: sample numeric arguments (for example `5 10 15`)
- `tasks/Task2/in.txt`: no required args (`No args needed` is acceptable)
- `tasks/Task3/in.txt`: quoted JSON string as a single argument

## Notes

- Keep task names exactly `Task1`, `Task2`, `Task3` when using the launcher.
- If a task executable is missing, build the workspace first.
- If `in.txt` is malformed (especially for `Task3` JSON), that task may fail at runtime.


