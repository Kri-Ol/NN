#pragma once

#include "config.hpp"

template <typename T>
struct interface_synapse
{
#pragma region Data
    public: double _weight;
    public: double _prevweight;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: interface_synapse():
        _weight{0.0},
        _prevweight{-1.0}
    {
    }

    public: interface_synapse(const interface_synapse&  is) = default;
    public: interface_synapse(      interface_synapse&& is) = default;

#pragma endregion

#pragma region Interfaces
    public: func output() const -> double
    {
        return static_cast<const T*>(this)->actual_output();
    }

    public: func update_weight(const double learning_rate,
                               const double delta) const -> double
    {
        return static_cast<const T*>(this)->actual_update_weight();
    }
#pragma endregion

#pragma region Observers
    public: func weight() const -> double
    {
        return _weight;
    }

    public: func weight() const -> double
    {
        return _weight;
    }
#pragma endregion
};
