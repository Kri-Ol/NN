#pragma once

#include "config.hpp"

#include <cstdint>

using uuid = uint64_t;

inline uuid generate_uuid() {
    static auto v = uuid{0};
    return ++v;
}
