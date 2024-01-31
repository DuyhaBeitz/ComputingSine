#include <cstddef>
#include <cstdint>
#include <type_traits>

template<typename T, typename T2, size_t dp>
class fixed
{
public:
    T value = T(0);

    //constructor
    constexpr fixed() = default;
    constexpr fixed(const double d)
    {
        value = T(d * double(1 << dp) + (d >= 0 ? 0.5 : -0.5));
    }

    //to double
    constexpr operator double() const
    {
        return double(value) / double(1 << dp);
    }

private:
    static constexpr fixed form(T v)
    {
        fixed k;
        k.value = v;
        return k;
    }

public:
    //Assign
    constexpr fixed& operator = (const fixed& f) = default;

    //Negate
    constexpr fixed& operator - () const
    {
        return form(-this->value);
    }

    //Addition
    constexpr fixed& operator + (const fixed& f) const
    {
        return form(this->value + f.value);
    }

    constexpr fixed& operator += (const fixed& f) 
    {
        this->value += f.value;
        return *this;
    }

    //Subtraction
    constexpr fixed& operator - (const fixed& f) const
    {
        return form(this->value - f.value);
    }

    constexpr fixed& operator -= (const fixed& f) 
    {
        this->value -= f.value;
        return *this;
    }

    //Multiplication
    constexpr fixed& operator * (const fixed& f) const
    {
        return form( (T2(this->value) * T2(f.value)) >> dp );
    }
    constexpr fixed& operator *= (const fixed& f)
    {
        this->value = (T2(this->value) * T2(f.value)) >> dp;
        return *this;
    }

    //Division
    constexpr fixed& operator / (const fixed& f) const
    {
        return form((T2(this->value) << dp) / T2(f.value));
    }
    constexpr fixed& operator /= (const fixed& f)
    {
        this->value = (T2(this->value) << dp) / T2(f.value);
        return *this;
    }
};

