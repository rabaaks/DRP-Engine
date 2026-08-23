# DRP Engine
DRP Engine is a game engine, mainly for me to become more familiar with graphics and larger C++ projects. Unlike a standard game engine, it uses a software renderer, again because it was something I wanted to learn about.

## Project layout

### Folders
- **Editor:** Executable for the game editor. Creates cmake configuration for user created projects.
- **Engine:** Main game engine library. Gets linked into runtime when compiling.
- **Runtime:** The actual game executable. Dynamically accesses user scripts.

## Architecture
Game scenes consist of entities, which consist of purely data components, and user-defined scripts. Systems are created globally and act on certain components.

## Demo game
Use the github pages link to play the game in the browser. Alternatively, download the project files and modify the game project files in /examples/Game/