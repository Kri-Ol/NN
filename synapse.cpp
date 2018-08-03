#include "config.hpp"

#include "synapse.hpp"

#include "neuron.hpp"

func synapse::actual_from_neuron(const neuron& nrn) const -> bool
{
    return nrn.id() == _from_neuron->id();
}

func synapse::actual_output() -> double
{
    return 1.0; // _from_neuron->calc_output();
}
