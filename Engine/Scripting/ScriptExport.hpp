#pragma once

#include <Engine/Scripting/Script.hpp>

// Convert the C++ classes to C
#define SCRIPT_EXPORT extern "C" __declspec(dllexport)
#define REGISTER_SCRIPT(ClassName) \
    SCRIPT_EXPORT Engine::Script* Create_##ClassName() {return new ClassName();} \
    SCRIPT_EXPORT void Destroy_##ClassName(Engine::Script* script) {delete script;}