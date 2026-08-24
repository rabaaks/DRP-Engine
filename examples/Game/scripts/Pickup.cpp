#include "Pickup.hpp"

#include <Engine/Scene/ComponentManager.hpp>
#include <Engine/Scripting/ScriptExport.hpp>

namespace Runtime
{
    void to_json(nlohmann::json& pickupJson, const Pickup& pickup)
    {
        pickupJson["collected"] = pickup.collected;
    }

    void from_json(const nlohmann::json& pickupJson, Pickup& pickup)
    {
        pickup.collected = pickupJson.value("collected", false);
    }
}

// Every component this module owns gets registered here - ScriptLibrary::LoadModule
// calls this if it finds the symbol, so Runtime never needs to know Pickup exists
SCRIPT_EXPORT void RegisterComponents(Engine::ComponentManager& componentManager)
{
    componentManager.AddComponent<Runtime::Pickup>("Pickup");
}
