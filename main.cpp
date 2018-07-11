#include "config.hpp"

#include <iostream>

#include "step_activation_function.hpp"
#include "rectified_activation_function.hpp"
#include "sigmoid_activation_function.hpp"

func main() -> int
{
    // sigmoid_activation_function saf{0.5};
    rectified_activation_function saf{};

    for(int k = 0; k != 21; ++k) {
        double x = -1.0 + 0.1 * double(k);
        auto q = saf.calc_output(x);

        std::cout << x << "    " << q << "\n";
    }

    return 0;
}
