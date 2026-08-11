#pragma once

#include <nlohmann/json.hpp>

#include <Engine/Graphics/Image.hpp>
#include <Engine/Graphics/Mesh.hpp>
#include <Engine/Graphics/Model.hpp>
#include <Engine/Graphics/Triangle.hpp>
#include <Engine/Graphics/Vertex.hpp>

namespace Engine
{
    void to_json(nlohmann::json& imageJson, const Image& image);
    void from_json(const nlohmann::json& imageJson, Image& image);

    template <std::size_t N>
    void to_json(nlohmann::json& vectorJson, const Vector<N>& v);
    template <std::size_t N>
    void from_json(const nlohmann::json& vectorJson, Vector<N>& v);

    void to_json(nlohmann::json& vertexJson, const Vertex& vertex);
    void from_json(const nlohmann::json& vertexJson, Vertex& vertex);

    void to_json(nlohmann::json& triangleJson, const Triangle& triangle);
    void from_json(const nlohmann::json& triangleJson, Triangle& triangle);

    void to_json(nlohmann::json& meshJson, const Mesh& mesh);
    void from_json(const nlohmann::json& meshJson, Mesh& mesh);

    void to_json(nlohmann::json& modelJson, const Model& model);
    void from_json(const nlohmann::json& modelJson, Model& model);
}

#include <Engine/Assets/Serialization.ipp>