#pragma once

#include "config.hpp"

template <typename T>
struct interface_activation_function
{
    public: func calc_output(double input) -> double
    {
        return dynamic_cast<T*>(this)->calc_activation_function(input);
    }
};
