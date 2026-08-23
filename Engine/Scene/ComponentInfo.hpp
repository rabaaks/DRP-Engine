#pragma once

#include <nlohmann/json.hpp>

#include <functional>
#include <memory>

namespace Engine
{
    struct ComponentInfo
    {
        std::function<std::shared_ptr<void>()> create;
        std::function<nlohmann::json(void*)> toJson;
        std::function<void(void*, const nlohmann::json&)> fromJson;
    };
}