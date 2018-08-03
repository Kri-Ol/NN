#pragma once

#include "config.hpp"

#include <algorithm>
#include <chrono>
#include <random>

#include "interface_synapse.hpp"

struct neuron;

struct synapse: public interface_synapse<synapse>
{
#pragma region Data
    private: neuron* _from_neuron;
    private: neuron* _to_neuron;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: synapse(neuron* from_neuron, neuron* to_neuron, const double weight):
        _from_neuron{from_neuron},
        _to_neuron{to_neuron}
    {
        _weight = weight;
        _previous_weight = 0.0;
    }

    public: synapse(neuron* from_neuron, neuron* to_neuron):
        _from_neuron{from_neuron},
        _to_neuron{to_neuron}
    {
        // auto t = std::chrono::system_clock::now();
        auto t = 987654321ULL;
        std::mt19937_64 rng{t};
        std::uniform_real_distribution<> dst{0.0, 1.0};

        _weight = dst(rng);
        _previous_weight = 0.0;
    }

    public: synapse(const synapse&  syn) = default;
    public: synapse(      synapse&& syn) = default;

    public: func operator=(const synapse&  syn) -> synapse& = default;
    public: func operator=(      synapse&& syn) -> synapse& = default;

    public: ~synapse() = default;
#pragma endregion

#pragma region Implementation
    public: func actual_update_weight(const double learning_rate, const double delta) -> void
    {
        _previous_weight = _weight;
        _weight         += learning_rate * delta;
    }

    public: func actual_from_neuron(const neuron& nrn) const -> bool;

    public: func actual_output() -> double;

#pragma endregion
};
