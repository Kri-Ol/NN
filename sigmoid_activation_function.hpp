#pragma once

#include <cmath>

#include "interface_activation_function.hpp"

struct sigmoid_activation_function : public interface_activation_function<sigmoid_activation_function>
{
#pragma region Data
    private: double _coeficient;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: sigmoid_activation_function(const double coeficient):
        _coeficient{coeficient}
    {
    }

    public: sigmoid_activation_function(const sigmoid_activation_function&  saf) = default;
    public: sigmoid_activation_function(      sigmoid_activation_function&& saf) = default;

    public: func operator=(const sigmoid_activation_function&  saf) -> sigmoid_activation_function& = default;
    public: func operator=(      sigmoid_activation_function&& saf) -> sigmoid_activation_function& = default;

    public: ~sigmoid_activation_function() = default;
#pragma endregion

#pragma region Implementation
    public: func calc_activation_function(const double input) const -> double
    {
        return 1.0 / (1.0 + exp(-input * _coeficient));
    }
#pragma endregion

#pragma region Observers
    public: func coefficient() const -> double
    {
        return _coeficient;
    }
#pragma endregion
};
