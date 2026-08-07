target_sources(Runtime PRIVATE
    Game/Game.cpp
    
    main.cpp
)

target_link_libraries(Runtime PRIVATE Engine)
target_link_libraries(Engine PUBLIC nlohmann_json::nlohmann_json)