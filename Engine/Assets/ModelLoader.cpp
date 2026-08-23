#include <Engine/Assets/ModelLoader.hpp>
#include <Engine/Graphics/Mesh.hpp>
#include <Engine/Graphics/Model.hpp>
#include <Engine/Math/Vector.hpp>

#include <cstddef>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>

namespace Engine
{
    void ModelLoader::Load(std::filesystem::path path, void* object)
    {
        Model& model{*static_cast<Model*>(object)};
        Mesh mesh;
        
        std::ifstream file{path};
        std::string line, word;
        Vector<3> normal{};

        while (std::getline(file, line))
        {
            std::istringstream stream{line};
            stream >> word;
            if (word == "facet")
            {
                // Ignore word normal
                std::string ignore;
                stream >> ignore;
                stream >> normal.x >> normal.y >> normal.z;
            }
            else if (word == "vertex")
            {
                Vertex vertex{};
                stream >> vertex.position.x >> vertex.position.y >> vertex.position.z;
                vertex.normal = normal;
                mesh.vertices.push_back(vertex);

                std::size_t index{mesh.vertices.size() - 1};
                if (index % 3 == 2)
                {
                    mesh.triangles.push_back(Triangle{{index - 2, index - 1, index}});
                }
            }
        }
        model.meshes.push_back(mesh);
    }
}