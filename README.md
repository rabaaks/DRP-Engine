# DRP Engine
DRP Engine is a game engine based on a software renderer, mainly for me to become more familiar with graphics.

## Project layout

### Folders
- **Editor:** Executable for the game editor. Creates cmake configuration for user created projects.
- **Engine:** Main game engine library. Gets linked into runtime when compiling.
- **Runtime:** The actual game executable. Dynamically accesses user scripts.

## Architecture
Game scenes consist of entities, which consist of purely data components, and user-defined scripts. Systems are created globally and act on certain components.