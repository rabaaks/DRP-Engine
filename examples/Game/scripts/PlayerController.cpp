#include <Engine/Scripting/ScriptExport.hpp>

#include <Engine/Graphics/Transform.hpp>
#include <Engine/Scene/Entity.hpp>
#include <Engine/Scene/Scene.hpp>

#include "Pickup.hpp"

#include <SDL3/SDL.h>

#include <cmath>
#include <iostream>

namespace
{
    constexpr float moveSpeed{3.0f};
    constexpr float pickupRadius{0.75f};
    constexpr int totalPickups{3};
}

class PlayerController : public Engine::Script
{
public:
    void Create(Engine::Entity& entity) override
    {

    }

    void Update(Engine::Entity& entity, const Engine::Input& input, float deltaTime) override
    {
        if (!entity.GetComponents().contains("Transform") || !entity.GetScene()) return;
        Engine::Transform* transform{entity.GetComponent<Engine::Transform>("Transform")};

        Engine::Vector<3> move{};
        if (input.IsKeyDown(SDL_SCANCODE_W)) move.z += 1.0f;
        if (input.IsKeyDown(SDL_SCANCODE_S)) move.z -= 1.0f;
        if (input.IsKeyDown(SDL_SCANCODE_A)) move.x -= 1.0f;
        if (input.IsKeyDown(SDL_SCANCODE_D)) move.x += 1.0f;

        float magnitude{std::sqrt(move.x * move.x + move.z * move.z)};
        if (magnitude != 0)
        {
            move.x /= magnitude;
            move.y /= magnitude;
        }

        transform->position = transform->position + move * moveSpeed * deltaTime;

        for (Engine::Entity& other : entity.GetScene()->GetEntities())
        {
            if (!other.GetComponents().contains("Pickup") || !other.GetComponents().contains("Transform")) continue;

            Runtime::Pickup* pickup{other.GetComponent<Runtime::Pickup>("Pickup")};
            if (pickup->collected) continue;

            Engine::Transform* pickupTransform{other.GetComponent<Engine::Transform>("Transform")};
            Engine::Vector<3> diff{transform->position - pickupTransform->position};
            if (diff.Dot(diff) > pickupRadius * pickupRadius) continue;

            pickup->collected = true;
            collectedCount++;
            std::cout << "Collected " << collectedCount << " / " << totalPickups << std::endl;

            if (collectedCount == totalPickups)
            {
                std::cout << "You win!" << std::endl;
            }
        }
    }

    void Destroy(Engine::Entity& entity) override
    {

    }

private:
    int collectedCount{};
};

REGISTER_SCRIPT(PlayerController)
