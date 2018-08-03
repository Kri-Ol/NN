#pragma once

#include "config.hpp"

#include <cstdint>
#include <list>

#include "uuid.hpp"
#include "input_synapse.hpp"
#include "synapse.hpp"

struct neuron
{
#pragma region Data
    protected: uuid   _uuid;
    protected: double _previous_partial_deriative;
#pragma endregion

#pragma region Ctor/Dtor/op=
    public: neuron():
        _uuid{generate_uuid()},
        _previous_partial_deriative{0.0}
    {
    }

    public: neuron(const neuron&  nrn) = default;
    public: neuron(      neuron&& nrn) = default;

    public: func operator=(const neuron&  nrn) -> neuron& = default;
    public: func operator=(      neuron&& nrn) -> neuron& = default;

    public: ~neuron() = default;
#pragma endregion


#pragma region Observers
    public: func id() const -> uuid {
        return _uuid;
    }


#pragma endregion
};
