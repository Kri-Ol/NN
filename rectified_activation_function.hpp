#pragma once

#include <algorithm>

#include "interface_activation_function.hpp"

struct rectified_activation_function : public interface_activation_function<rectified_activation_function>
{
#pragma region Ctor/Dtor/op=
    public: rectified_activation_function()
    {
    }

    public: rectified_activation_function(const rectified_activation_function& raf) = default;
    public: rectified_activation_function& operator=(const rectified_activation_function& raf) = default;

    public: rectified_activation_function(rectified_activation_function&& raf) = default;
    public: rectified_activation_function& operator=(rectified_activation_function&& raf) = default;

    public: ~rectified_activation_function() = default;
#pragma endregion

#pragma region Implementation
    public: func calc_activation_function(const double input) const -> double
    {
        return std::max(0.0, input);
    }
#pragma endregion
};
