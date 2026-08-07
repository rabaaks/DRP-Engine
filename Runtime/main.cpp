#include <Runtime/Game/Game.hpp>

#include <filesystem>
#include <iostream>

int main(int argc, char* argv[])
{
    // If project.json path is passed in then use that, usually when the editor is running the runtime directly
    // If not, then check the executable folder, because the game might be run from a different working directory
    std::filesystem::path projectFilePath;

    if (argc > 1)
    {
        projectFilePath = argv[1];
    }
    else
    {
        projectFilePath = std::filesystem::path(argv[0]).parent_path() / "project.json";
    }

    Runtime::Game game{Runtime::Game::load(projectFilePath)};
    game.Run();

    return 0;
}