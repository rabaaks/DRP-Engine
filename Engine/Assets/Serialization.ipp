#include <Engine/Assets/Serialization.hpp>

namespace Engine
{
    template <std::size_t N>
    void to_json(nlohmann::json& vectorJson, const Vector<N>& v)
    {
        for (std::size_t i{}; i < N; ++i)
        {
            vectorJson.push_back(v[i]);
        }
    }

    template <std::size_t N>
    void from_json(const nlohmann::json& vectorJson, Vector<N>& v)
    {
        for (std::size_t i{}; i < N; ++i)
        {
            v[i] = vectorJson.at(i);
        }
    }
}