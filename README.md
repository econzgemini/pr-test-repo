# PR Test Repo — VECS Hub Baseline

This is the **clean baseline** branch. Create PRs off this repo to test
whether the code-review agent correctly flags guideline violations.

## Files

- `CANHandler.c / .h` — CAN frame dispatch (clean, follows all guidelines)
- `DeviceConfig.c / .h` — Device config get/set (clean, follows all guidelines)

## Coding Guidelines Summary

- Module prefix on all public symbols (`CAN_`, `DCFG_`, etc.)
- Hungarian notation: `u8`, `u16`, `u32`, `i8`, `i16`, `b`, `f`, `pc`, `pst`
- Allman braces — opening `{` on its own line for functions and control flow
- Doxygen `@brief / @param / @return` on all public functions
- No magic numbers — use `#define` constants
- No `//` comments — only `/* */` block comments
