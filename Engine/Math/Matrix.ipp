#include <Engine/Math/Matrix.hpp>

namespace Engine
{
    template <std::size_t M, std::size_t N>
    Vector<N>& Matrix<M, N>::operator[](std::size_t index)
    {
        return data[index];
    }

    template <std::size_t M, std::size_t N>
    template <std::size_t P>
    Matrix<M, P> Matrix<M, N>::operator*(const Matrix<N, P>& other) const
    {
        Matrix<M, P> result;
        for (std::size_t i; i < M; ++i)
        {
            for (std::size_t j; j < P; ++j)
            {
                float sum{};
                for (std::size_t k; k < N; ++k)
                {
                    sum += this[i][k] * other[k][j];
                }
            }
        }
        return result;
    }
}