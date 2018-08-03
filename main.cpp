#include "config.hpp"

#include <iostream>

#include "step_activation_function.hpp"
#include "rectified_activation_function.hpp"
#include "sigmoid_activation_function.hpp"

#include "input_synapse.hpp"
#include "synapse.hpp"
#include "neuron.hpp"

func main() -> int {
    sigmoid_activation_function saf{0.5};
    rectified_activation_function raf{};
    step_activation_function taf{0.0};

    for(int k = 0; k != 21; ++k) {
        double x = -1.0 + 0.1 * double(k);
        auto q = saf.calc_output(x);
        auto r = raf.calc_output(x);
        auto s = taf.calc_output(x);

        std::cout << x << "     " << q << "     " << r << "     " << s << "\n";
    }

    return 0;
}
