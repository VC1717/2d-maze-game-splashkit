# 2D Maze Game (C++ / SplashKit)

Three-level 2D maze game built with the SplashKit framework. Navigate from **S** (start) to **E** (end) while avoiding **T** (traps). Arrow keys to move.

**🎥 Video demo:** https://youtu.be/IDjlRQGs4kE

## Features
- 3 handcrafted maze levels with start/end and trap tiles
- Valid-move checks and collision prevention
- Win/Lose detection and level progression
- Clean game loop: input → update → render → state transitions

## Controls
- **Arrow keys**: Move (Up/Down/Left/Right)

## File
- `code.cpp` — main source (uses `splashkit.h`)

## Getting Started (macOS)
1. Install the **SplashKit** SDK (follow SplashKit’s macOS setup guide).
2. Create a new SplashKit C++ project (or open an existing one).
3. Add `code.cpp` to the project (or replace the default main file with it).
4. Build and run.

> Tip: If using Xcode/CLion, ensure include paths and libraries point to your SplashKit installation.

## Project Structure (simple)
