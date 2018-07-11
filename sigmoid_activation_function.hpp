#pragma once

#include <cmath>

#include "interface_activation_function.hpp"

struct sigmoid_activation_function : public interface_activation_function<sigmoid_activation_function>
{
#pragma region Data
    private: double _coeff;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: sigmoid_activation_function(double coeff):
        _coeff{coeff}
    {
    }

    public: sigmoid_activation_function(const sigmoid_activation_function& saf) = default;
    public: sigmoid_activation_function& operator=(const sigmoid_activation_function& saf) = default;

    public: sigmoid_activation_function(sigmoid_activation_function&& saf) = default;
    public: sigmoid_activation_function& operator=(sigmoid_activation_function&& saf) = default;

    public: ~sigmoid_activation_function() = default;
#pragma endregion

#pragma region Implementation
    public: func calc_activation_function(double input) const -> double
    {
        return 1.0 / (1.0 + exp(-input * _coeff));
    }
#pragma endregion

#pragma region Observers
    public: func coefficient() const -> double
    {
        return _coeff;
    }
#pragma endregion
};
