# DRP Engine
DRP Engine is a game engine, mainly for me to become more familiar with graphics and larger C++ projects. Unlike a standard game engine, it uses a software renderer, again because it was something I wanted to learn about.

Currently it renders using the CPU and shows images to the screen using SDL. The sample game shows the basic functionality with a scene, entities, component, and script.

## Project layout

### Folders
- **Editor:** Executable for the game editor. Creates cmake configuration for user created projects. It has not been implemented yet so you have to do its functionality manually.
- **Engine:** Main game engine library with assets, rendering, window, input, scene, and scripting. Gets linked into runtime when compiling.
- **Runtime:** The actual game executable. Dynamically accesses user scripts.

## Basic Info

### Requirements

The project uses C++20 and CMake 3.20. Currently it only works for windows with the dynamic scripts. All third-party libraries are included.

### Architecture
Game scenes consist of entities, which consist of purely data components, and user-defined scripts. Systems are created globally and act on certain components.

### Build the engine
```powershell
cmake -S . -B build
cmake --build build
```

### Demo game
Use the github pages link to play the game in the browser. Alternatively, download the project files and modify the game project files in /examples/Game/
```powershell
./build/Runtime.exe examples/Game/project.json
```
Use WASD to control the main box. When you go to a collectable it will disappear.

## How to make a game

### Necessary files
project.json
```json
{
  "name": "My Game",
  "width": 1280,
  "height": 720,
  "scriptModules": ["GameScripts.dll"],
  "startScene": 5
}
```
assets.json
```json
[
    {
        "id": 0,
        "path": "models/object.model",
        "sourcePath": "object.stl",
        "type": "model"
    }
]
```

### Scenes and entities
Each scene stores an array of entities with their asset IDs. 
```json
{
    "entities": [1, 2, 3, 4]
}
```
Each entity contains a name, an array of scripts, and a components object. Currently the only components are Transform and MeshRenderer, which will render a mesh to the screen when combined in anentity. User made games can also have their own components like Pickup in the sample game
```json
{
    "name": "MyEntity",
    "scripts": ["MyScript"],
    "components": {
        "Transform": { "position": [0.0, 0.0, 0.0], "rotation": [0.0, 0.0, 0.0], "scale": [1.0, 1.0, 1.0] },
        "MeshRenderer": { "model": 0 }
    }
}
```

### Gameplay scripts

Gameplay scripts are made by creating a class that derives from Engine::Script. The file should end with the REGISTER_SCRIPT macro, which exports the create and destroy functions in the script with C linkage.
```cpp
class MyScript : public Engine::Script
{
public:
    void Create(Engine::Entity& entity) override {}
    void Update(Engine::Entity& entity, const Engine::Input& input, float deltaTime) override {}
    void Destroy(Engine::Entity& entity) override {}
};

REGISTER_SCRIPT(MyScript)
```
The names of scripts should also be listed in the module's json file. Each module is compiled into its own dll file.
```json
{
    "scripts": ["MyScript"]
}
```