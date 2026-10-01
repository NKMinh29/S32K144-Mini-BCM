# S32K144 Mini BCM

A hands-on embedded C learning project for the NXP S32K144, progressing from
register-level GPIO to a small body-control application.

**Current stage: GPIO blink foundation.** The current source configures PTD0 as
an output and toggles it in a bare-metal super-loop. CAN communication, an RTOS,
and an AUTOSAR stack are future milestones, not implemented features of this revision.

## What the current code does

1. Writes the watchdog configuration used by this learning example.
2. Enables the PORTD clock gate.
3. Selects GPIO functionality for PTD0.
4. Configures PTD0 as an output.
5. Toggles the output using a busy-loop delay.

The `delay_ms(333)` call expresses an intended interval. The loop is not calibrated:
its actual duration depends on the core clock, compiler, optimization, and generated
instructions. No measured timing accuracy or compliance with automotive lighting
requirements is claimed here. Confirm the LED pin and polarity for your board revision.

## Repository contents

| Path | Purpose |
|---|---|
| `src/main.c` | Current application and delay loop |
| `include/registers.h` | Register aliases used by the example |
| `include/` | Device and startup headers |
| `Project_Settings/Startup_Code/` | Startup sources |
| `Project_Settings/Linker_Files/` | Flash and RAM linker scripts |
| `Project_Settings/Debugger/` | Existing P&E launch configurations |

## Build and hardware setup

The repository contains source and project-support files. The Eclipse/S32DS
`.project` and `.cproject` metadata are currently excluded by `.gitignore`, so
this checkout is **not yet a complete one-click S32DS import**.

To reconstruct the project, use a compatible S32K144 project in your installed
S32 Design Studio environment, add the application and headers, and select the
matching startup and linker configuration. Record the exact toolchain version,
core clock, board revision, and compiler flags before publishing timing results.
Do not add a second startup/vector-table implementation to an existing project.

Hardware validation should start with the board's documented GPIO/LED connection.
This README was checked against the committed source; no build, flashing or hardware
measurement was performed as part of the documentation update.

## Development milestones

- [ ] Record a reproducible S32DS setup and a successful build log.
- [ ] Replace the busy-loop delay with a hardware timer and measure its period.
- [ ] Add a debounced input and a documented light state machine.
- [ ] Separate application logic from GPIO/time adapters for host testing.
- [ ] Add CAN signals, timeouts and recovery scenarios.
- [ ] Map the resulting components to a Classic AUTOSAR learning architecture.

For each milestone, keep a short demo, setup description, test cases and known limitations.
An educational layered design should be identified separately from integration with
an actual AUTOSAR stack.

## Attribution

This repository includes vendor-origin device/startup files. Preserve their existing
copyright and license notices; the application and third-party components should
be identified separately before assigning a repository-wide license.

Maintained by [NKMinh29](https://github.com/NKMinh29).
