target_sources(Runtime PRIVATE
    Application/Application.cpp
    
    main.cpp
)

target_link_libraries(Runtime PRIVATE Engine)