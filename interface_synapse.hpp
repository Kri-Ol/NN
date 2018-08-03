#pragma once

#include "config.hpp"

struct neuron;

template <typename T>
struct interface_synapse
{
#pragma region Data
    public: double _weight;
    public: double _previous_weight;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: interface_synapse():
        _weight{0.0},
        _previous_weight{-1.0}
    {
    }

    public: interface_synapse(const interface_synapse&  is) = default;
    public: interface_synapse(      interface_synapse&& is) = default;

    public: func operator=(const interface_synapse&  is) -> interface_synapse& = default;
    public: func operator=(      interface_synapse&& is) -> interface_synapse& = default;

    public: ~interface_synapse() = default;
#pragma endregion

#pragma region Interfaces
    public: func output() const -> double
    {
        return static_cast<const T*>(this)->actual_output();
    }

    public: func update_weight(const double learning_rate, const double delta) -> double
    {
        return static_cast<T*>(this)->actual_update_weight(learning_rate, delta);
    }

    public: func is_from_neuron(const neuron& nrn) const -> bool
    {
        return static_cast<const T*>(this)->actual_from_neuron(nrn);
    }
#pragma endregion

#pragma region Observers
    public: func weight() const -> double
    {
        return _weight;
    }

    public: func previous_weight() const -> double
    {
        return _previous_weight;
    }
#pragma endregion
};
