#include "common.h"
#include <cstdint>

TEST(trigonometry, sin)
{
    using P = fpm::fixed<std::int32_t, std::int64_t, 12>;
    const double PI = std::acos(-1);

    constexpr auto MAX_ERROR_PERC = 0.025;

    for (int angle = -1800; angle <= 1800; ++angle)
    {
        auto flt_angle = angle * PI / 180;
        auto sin_real = std::sin(flt_angle);
        auto sin_fixed = static_cast<double>(sin(P(flt_angle)));
        EXPECT_TRUE(HasMaximumError(sin_fixed, sin_real, MAX_ERROR_PERC));
    }
}

TEST(trigonometry, cos)
{
    using P = fpm::fixed<std::int32_t, std::int64_t, 12>;
    const double PI = std::acos(-1);

    constexpr auto MAX_ERROR_PERC = 0.025;

    for (int angle = -1800; angle <= 1800; ++angle)
    {
        auto flt_angle = angle * PI / 180;
        auto cos_real = std::cos(flt_angle);
        auto cos_fixed = static_cast<double>(cos(P(flt_angle)));
        EXPECT_TRUE(HasMaximumError(cos_fixed, cos_real, MAX_ERROR_PERC));
    }
}

TEST(trigonometry, tan)
{
    using P = fpm::fixed<std::int32_t, std::int64_t, 12>;
    const double PI = std::acos(-1);

    constexpr auto MAX_ERROR_PERC = 0.025;

    for (int angle = -1800; angle <= 1800; ++angle)
    {
        // Tangent goes to infinite at 90 and -90 degrees.
        // We can't represent that with fixed-point maths, so don't test for it.
        if ((angle + 90) % 180 != 0)
        {
            auto flt_angle = angle * PI / 180;
            auto tan_real = std::tan(flt_angle);
            auto tan_fixed = static_cast<double>(tan(P(flt_angle)));
            EXPECT_TRUE(HasMaximumError(tan_fixed, tan_real, MAX_ERROR_PERC));
        }
    }
}

TEST(trigonometry, atan)
{
    using P = fpm::fixed<std::int32_t, std::int64_t, 12>;

    constexpr auto MAX_ERROR_PERC = 0.025;

    for (int x = -1000; x <= 1000; ++x)
    {
        auto value = x / 10.0;
        auto atan_real = std::atan(value);
        auto atan_fixed = static_cast<double>(atan(P(value)));
        EXPECT_TRUE(HasMaximumError(atan_fixed, atan_real, MAX_ERROR_PERC));
    }

    for (int x = -1000; x <= 1000; ++x)
    {
        auto value = x / 1000.0;
        auto atan_real = std::atan(value);
        auto atan_fixed = static_cast<double>(atan(P(value)));
        EXPECT_TRUE(HasMaximumError(atan_fixed, atan_real, MAX_ERROR_PERC));
    }
}

TEST(trigonometry, asin)
{
    using P = fpm::fixed<std::int32_t, std::int64_t, 12>;

    constexpr auto MAX_ERROR_PERC = 0.025;

    for (int x = -1000; x <= 1000; ++x)
    {
        auto value = x / 1000.0;
        auto asin_real = std::asin(value);
        auto asin_fixed = static_cast<double>(asin(P(value)));
        EXPECT_TRUE(HasMaximumError(asin_fixed, asin_real, MAX_ERROR_PERC));
    }
}

TEST(trigonometry, acos)
{
    using P = fpm::fixed<std::int32_t, std::int64_t, 12>;

    constexpr auto MAX_ERROR_PERC = 0.025;

    for (int x = -1000; x <= 1000; ++x)
    {
        auto value = x / 1000.0;
        auto acos_real = std::acos(value);
        auto acos_fixed = static_cast<double>(acos(P(value)));
        EXPECT_TRUE(HasMaximumError(acos_fixed, acos_real, MAX_ERROR_PERC));
    }
}

TEST(trigonometry, atan2)
{
    using P = fpm::fixed<std::int32_t, std::int64_t, 12>;
    const double PI = std::acos(-1);

    constexpr auto MAX_ERROR_PERC = 0.025;

    for (int angle = 0; angle <= 360; ++angle)
    {
        const auto y = std::sin(angle * PI / 180);
        const auto x = std::cos(angle * PI / 180);

        auto atan2_real = std::atan2(y, x);
        auto atan2_fixed = static_cast<double>(atan2(P(y), P(x)));
        EXPECT_TRUE(HasMaximumError(atan2_fixed, atan2_real, MAX_ERROR_PERC));
    }
}

