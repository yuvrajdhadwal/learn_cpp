#pragma once

template <typename T>
inline auto max(T x_x, T y_y) -> T {
    return (x_x < y_y) ? y_y : x_x;
}
