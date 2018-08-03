#pragma once

#include <algorithm>
#include <stdexcept>


#include "interface_synapse.hpp"

struct neuron;

struct input_synapse: interface_synapse<input_synapse>
{
#pragma region Data
    private: double  _output;
    private: neuron* _to_neuron;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: input_synapse(neuron* to_neuron):
        _to_neuron{to_neuron},
        _output{0.0}
    {
        _weight          = 1.0;
        _previous_weight = 0.0;
    }

    public: input_synapse(neuron* to_neuron, const double output):
        _to_neuron{to_neuron},
        _output{output}
    {
        _weight          = 1.0;
        _previous_weight = 0.0;
    }

    public: input_synapse(const input_synapse&  is) = default;
    public: input_synapse(      input_synapse&& is) = default;

    public: func operator=(const input_synapse&  is) -> input_synapse& = default;
    public: func operator=(      input_synapse&& is) -> input_synapse& = default;

    public: ~input_synapse() = default;
#pragma endregion

#pragma region Implementation
    public: func actual_output() const -> double
    {
        return _output;
    }

    public: func actual_update_weight(const double learning_rate, const double delta) const -> double
    {
        throw std::runtime_error("Not allowed to call it");
    }

    public: func is_from_neuron(const neuron& nrn)
    {
        return false;
    }
#pragma endregion
};
