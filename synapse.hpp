#pragma once

#include <algorithm>

struct neuron;

struct synapse
{
#pragma region Data
    private: neuron* _neuron;
    private:
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: synapse()
    {
    }

    public: rectified_activation_function(const rectified_activation_function& saf) = default;
    public: rectified_activation_function& operator=(const rectified_activation_function& saf) = default;

    public: rectified_activation_function(rectified_activation_function&& saf) = default;
    public: rectified_activation_function& operator=(rectified_activation_function&& saf) = default;

    public: ~rectified_activation_function() = default;
#pragma endregion

#pragma region Implementation
    public: func calc_activation_function(double input) const -> double
    {
        return std::max(0.0, input);
    }
#pragma endregion
};
