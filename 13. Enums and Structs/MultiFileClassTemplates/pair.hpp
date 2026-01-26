#pragma once

template <typename T>
struct Pair
{
    T first {};
    T second {};
};

template <typename T>
constexpr T max(Pair<T> p)
{
    return p.first < p.second ? p.second : p.first;
}