#pragma once

#include "interface_activation_function.hpp"

struct step_activation_function : public interface_activation_function<step_activation_function>
{
#pragma region Data
    private: double _threshold;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: step_activation_function(double treshold):
        _threshold{treshold}
    {
    }

    public: step_activation_function(const step_activation_function& saf) = default;
    public: step_activation_function& operator=(const step_activation_function& saf) = default;

    public: step_activation_function(step_activation_function&& saf) = default;
    public: step_activation_function& operator=(step_activation_function&& saf) = default;
#pragma endregion

#pragma region Implementation
    public: func calc_activation_function(double input) const -> double
    {
        return input > _threshold ? 1.0 : 0.0;
    }
#pragma endregion

#pragma region Observers
    public: func threshold() const -> double
    {
        return _threshold;
    }
#pragma endregion
};
