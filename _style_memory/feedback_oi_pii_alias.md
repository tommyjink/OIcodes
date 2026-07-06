---
name: OI pair alias style
description: This user prefers Chinese OI-style code to define pii as pair<int,int> and use the alias consistently.
type: feedback
originSessionId: d27e09a7-d0ec-475a-81e6-0b6afd1c9a27
---
When writing contest code in the user's Chinese OI style, define `#define pii pair<int,int>` and prefer `pii` over spelling out `pair<int,int>`.

**Why:** The user explicitly said that formally they use `#define pii pair<int,int>`.
**How to apply:** For future OI-style C++ files in this project, add the `pii` macro near other macros and use it for pair containers and variables unless the user asks for a different style.
