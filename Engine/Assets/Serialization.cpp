#include <Engine/Assets/Serialization.hpp>

#include <vector>

namespace Engine
{
    void to_json(nlohmann::json& imageJson, const Image& image)
    {
        int width{image.GetWidth()};
        int height{image.GetHeight()};

        imageJson["width"] = width;
        imageJson["height"] = height;

        for (int i{}; i < width; ++i)
        {
            imageJson.push_back(nlohmann::json{});
            for (int j{}; j < height; ++j)
            {
                imageJson[i].push_back(image.GetPixel(i, j).value);
            }
        }
    }

    void from_json(const nlohmann::json& imageJson, Image& image)
    {
        int width{imageJson["width"]};
        int height{imageJson["height"]};

        image = Image{width, height};

        for (int i{}; i < width; ++i)
        {
            for (int j{}; j < height; ++j)
            {
                image.GetPixel(i, j).value = imageJson.at(i).at(j);
            }
        }
    }

    void to_json(nlohmann::json& vertexJson, const Vertex& vertex){
        vertexJson["position"] = vertex.position;
        vertexJson["normal"] = vertex.normal;
        vertexJson["uv"] = vertex.uv;
    }

    void from_json(const nlohmann::json& vertexJson, Vertex& vertex)
    {
        vertex.position = vertexJson.at("position").get<Vector<3>>();
        vertex.normal = vertexJson.at("normal").get<Vector<3>>();
        vertex.uv = vertexJson.at("uv").get<Vector<2>>();
    }

    void to_json(nlohmann::json& triangleJson, const Triangle& triangle)
    {
        triangleJson = triangle.indices;
    }

    void from_json(const nlohmann::json& triangleJson, Triangle& triangle)
    {
        triangle.indices = triangleJson.get<std::vector<std::size_t>>();
    }

    void to_json(nlohmann::json& meshJson, const Mesh& mesh)
    {
        // Add material later
        meshJson["vertices"] = mesh.vertices;
        meshJson["triangles"] = mesh.triangles;
    }

    void from_json(const nlohmann::json& meshJson, Mesh& mesh)
    {
        mesh.vertices = meshJson.at("vertices").get<std::vector<Vertex>>();
        mesh.triangles = meshJson.at("triangles").get<std::vector<Triangle>>();
    }

    void to_json(nlohmann::json& modelJson, const Model& model)
    {
        modelJson["meshes"] = model.meshes;
    }

    void from_json(const nlohmann::json& modelJson, Model& model)
    {
        model.meshes = modelJson.at("meshes");
    }
}