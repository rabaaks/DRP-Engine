#pragma once

#include <nlohmann/json.hpp>

namespace Runtime
{
    struct Pickup
    {
        bool collected{false};
    };

    void to_json(nlohmann::json& pickupJson, const Pickup& pickup);
    void from_json(const nlohmann::json& pickupJson, Pickup& pickup);
}
