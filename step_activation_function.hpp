#pragma once

#include "interface_activation_function.hpp"

struct step_activation_function : public interface_activation_function<step_activation_function>
{
#pragma region Data
    private: double _threshold;
#pragma endregion

    public: step_activation_function(double treshold):
        _threshold(treshold)
    {
    }

    public: func calc_activation_function(double input) -> double
    {
        return input > _threshold ? 1.0 : 0.0;
    }
};
