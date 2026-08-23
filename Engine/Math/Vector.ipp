#include <Engine/Math/Vector.hpp>

namespace Engine
{
    template <std::size_t N>
    float Vector<N>::Dot(const Vector<N>& other) const
    {
        float result{};
        for (std::size_t i{}; i < N; ++i) {
            result += this->data[i] * other.data[i];
        }
        return result;
    }

    template <std::size_t N>
    Vector<N> Vector<N>::Cross(const Vector<N>& other) const requires (N == 3)
    {
        return 
        {
            this->y * other.z - this->z * other.y,
            this->z * other.x - this->x * other.z,
            this->x * other.y - this->y * other.x
        };
    }

    template <std::size_t N>
    float& Vector<N>::operator[](std::size_t index)
    {
        return this->data[index];
    }

    template <std::size_t N>
    float Vector<N>::operator[](std::size_t index) const
    {
        return this->data[index];
    }

    template <std::size_t N>
    Vector<N> Vector<N>::operator+(const Vector<N>& other) const
    {
        Vector<N> result;
        for (std::size_t i{}; i < N; i++)
        {
            result[i] = (*this)[i] + other[i];
        }
        return result;
    }

    template <std::size_t N>
    Vector<N> Vector<N>::operator-(const Vector<N>& other) const
    {
        Vector<N> result;
        for (std::size_t i{}; i < N; i++)
        {
            result[i] = (*this)[i] - other[i];
        }
        return result;
    }

    template <std::size_t N>
    Vector<N> Vector<N>::operator*(float scalar) const
    {
        Vector<N> result;
        for (std::size_t i{}; i < N; i++)
        {
            result[i] = (*this)[i] * scalar;
        }
        return result;
    }

    template <std::size_t N>
    Vector<N> Vector<N>::operator/(float scalar) const
    {
        Vector<N> result;
        for (std::size_t i{}; i < N; i++)
        {
            result[i] = (*this)[i] / scalar;
        }
        return result;
    }
}