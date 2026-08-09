#pragma once

#include <nlohmann/json.hpp>

#include <Engine/Graphics/Image.hpp>

namespace Engine
{
    void to_json(nlohmann::json& imageJson, const Image& image);
    void from_json(const nlohmann::json& imageJson, Image& image);
}