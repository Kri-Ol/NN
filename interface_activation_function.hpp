#pragma once

#include "config.hpp"

template <typename T>
struct interface_activation_function
{
    public: func calc_output(const double input) const -> double
    {
        return static_cast<const T*>(this)->calc_activation_function(input);
    }
};
