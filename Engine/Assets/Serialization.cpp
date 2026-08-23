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

    void to_json(nlohmann::json& transformJson, const Transform& transform)
    {
        transformJson["position"] = transform.position;
        transformJson["rotation"] = transform.rotation;
        transformJson["scale"] = transform.scale;
    }

    void from_json(const nlohmann::json& transformJson, Transform& transform)
    {
        transform.position = transformJson.at("position").get<Vector<3>>();
        transform.rotation = transformJson.at("rotation").get<Vector<3>>();
        transform.scale = transformJson.at("scale").get<Vector<3>>();
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
        model.meshes = modelJson.at("meshes").get<std::vector<Mesh>>();
    }

    void to_json(nlohmann::json& entityJson, const Entity& entity, ComponentManager& componentManager)
    {
        entityJson["name"] = entity.GetName();
        entityJson["scripts"] = entity.GetScriptNames();

        entityJson["components"] = nlohmann::json::object();
        for (auto& [typeName, component] : entity.GetComponents())
        {
            entityJson["components"][typeName] = componentManager.ToJson(typeName, component.get());
        }
    }

    void from_json(const nlohmann::json& entityJson, Entity& entity, ComponentManager& componentManager)
    {
        entity.SetName(entityJson.at("name"));

        for (const std::string& name : entityJson.at("scripts"))
        {
            entity.AddScriptName(name);
        }

        for (auto& [typeName, componentJson] : entityJson.at("components").items())
        {
            std::shared_ptr<void> component{componentManager.Create(typeName)};
            componentManager.FromJson(typeName, component.get(), componentJson);
            entity.AddComponent(typeName, component);
        }
    }

    void to_json(nlohmann::json& sceneJson, const Scene& scene)
    {
        // Only serialize the entity assets
        sceneJson["entities"] = scene.GetEntityAssets();
    }

    void from_json(const nlohmann::json& sceneJson, Scene& scene)
    {
        for (const Asset<Entity>& entityAsset : sceneJson.at("entities").get<std::vector<Asset<Entity>>>())
        {
            scene.AddEntityAsset(entityAsset);
        }
    }

    void to_json(nlohmann::json& meshRendererJson, const MeshRenderer& meshRenderer)
    {
        // Uses the generic to_json
        meshRendererJson["model"] = meshRenderer.model;
    }

    void from_json(const nlohmann::json& meshRendererJson, MeshRenderer& meshRenderer)
    {
        meshRenderer.model = meshRendererJson.at("model").get<Asset<Model>>();
    }
}