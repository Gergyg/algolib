struct Fraction {
    int64_t num = 1;
    int64_t den = 1;

    Fraction(int64_t num_, int64_t den_) : num(num_), den(den_) {
        if (den < 0) {
            num *= -1;
            den *= -1;
        }
        auto gcd = std::gcd(std::abs(num), den);
        num /= gcd;
        den /= gcd;
    }
};

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int64_t den = lhs.den * rhs.den;
    int64_t num = lhs.num * rhs.den + rhs.num * lhs.den;
    return {num, den};
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int64_t den = lhs.den * rhs.den;
    int64_t num = lhs.num * rhs.den - rhs.num * lhs.den;
    return {num, den};
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int64_t den = lhs.den * rhs.den;
    int64_t num = lhs.num * rhs.num;
    return {num, den};
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    int64_t den = lhs.den * rhs.num;
    int64_t num = lhs.num * rhs.den;
    return {num, den};
}

bool operator<(const Fraction& lhs, const Fraction& rhs) {
    return lhs.num * rhs.den < rhs.num * lhs.den;
}
