const int MOD = 998244353;
const double PI = acos(-1);


long long mod_pow(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) {
            result = (result * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

void fft(std::vector<std::complex<double>> &a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    std::vector<std::complex<double>> a0(n / 2), a1(n / 2);
    for (int i = 0; i < n / 2; i++) {
        a0[i] = a[i * 2];
        a1[i] = a[i * 2 + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    double angle = 2 * PI / n * (invert ? -1 : 1);
    std::complex<double> w(1), wn(cos(angle), sin(angle));
    for (int i = 0; i < n / 2; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

std::vector<long long> polynomial_multiplication(const std::vector<long long> &a, const std::vector<long long> &b) {
    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;

    std::vector<std::complex<double>> fa(n), fb(n);
    for (size_t i = 0; i < a.size(); i++) {
        fa[i] = a[i];
    }
    for (size_t i = 0; i < b.size(); i++) {
        fb[i] = b[i];
    }

    fft(fa, false);
    fft(fb, false);

    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }

    fft(fa, true);

    std::vector<long long> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = static_cast<long long>(fa[i].real()) % MOD;
    }

    return result;
}