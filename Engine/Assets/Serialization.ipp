#include <Engine/Assets/Serialization.hpp>

#include <cstdint>

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

    template <typename T>
    void to_json(nlohmann::json& assetJson, const Asset<T>& asset)
    {
        assetJson = asset.id;
    }

    template <typename T>
    void from_json(const nlohmann::json& assetJson, Asset<T>& asset)
    {
        asset.id = assetJson.get<std::uint64_t>();
    }
}