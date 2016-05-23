#pragma once

namespace ZGE
{
    constexpr static unsigned int MaxDepth = 15;

#define Sine(x) Sin<0>::Val (x)

    template<unsigned int depth>
    struct Sin
    {
        constexpr static float Val (const float &x)
        {
            return x * Term (x);
        }

        constexpr static float Term (const float &x)
        {
            return 1 - x * x / (2 * depth + 2) / (2 * depth + 3) * Sin<depth + 1>::Term (x);
        }
    };

    template<>
    struct Sin<MaxDepth>
    {
        constexpr static float Term (const float &x)
        {
            return 1.0f;
        }
    };
}
