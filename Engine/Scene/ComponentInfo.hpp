#pragma once

#include <nlohmann/json.hpp>

#include <functional>
#include <memory>

namespace Engine
{
    // Separate struct for the create function
    struct ComponentInfo
    {
        std::function<std::shared_ptr<void>()> create;
        std::function<nlohmann::json(void*)> toJson;
        std::function<void(void*, const nlohmann::json&)> fromJson;
    };
}