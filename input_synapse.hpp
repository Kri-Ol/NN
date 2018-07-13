#pragma once

#include "interface_synapse.hpp"

struct neuron;

struct input_synapse: interface_synapse<input_synapse>
{
#pragma region Data
    private: double  _output;
    private: neuron* _2neuron;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: input_synapse(neuron* tneuron):
        interface_synapse{},
        _output{0.0},
        _2neuron{tneuron}
    {
    }

    public: input_synapse(const input_synapse& is) = default;
    public: input_synapse& operator=(const input_synapse& is) = default;

    public: input_synapse(const input_synapse& is) = default;
    public: input_synapse& operator=(const input_synapse& is) = default;

    public: ~input_synapse() = default;
#pragma endregion

#pragma region Implementation
    public: func calc_activation_function(double input) const -> double
    {
        return std::max(0.0, input);
    }
#pragma endregion
};
