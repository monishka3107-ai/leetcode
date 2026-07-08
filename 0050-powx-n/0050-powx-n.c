double myPow(double x, int n) {
    long long e = n;              // avoids overflow when n = INT_MIN
    if (e < 0) {
        x = 1.0 / x;
        e = -e;
    }
    double res = 1.0;
    while (e) {
        if (e & 1) res *= x;
        x *= x;
        e >>= 1;
    }
    return res;
}