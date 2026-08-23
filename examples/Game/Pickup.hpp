#pragma once

#include <nlohmann/json.hpp>

namespace Runtime
{
    struct Pickup
    {
        bool collected;
    };

    void to_json(nlohmann::json& pickupJson, const Pickup& pickup)
    {
        pickupJson["collected"] = pickup.collected;
    }

    void from_json(const nlohmann::json& pickupJson, Pickup& pickup)
    {
        pickup.collected = pickupJson.value()
    }
}