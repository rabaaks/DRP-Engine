#include <Engine/Assets/Serialization.hpp>

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
                image.GetPixel(i, j).value = imageJson[i][j];
            }
        }
    }
}