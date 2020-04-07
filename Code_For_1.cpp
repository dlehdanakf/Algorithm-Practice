#include <stdio.h>

long long solve(long long n, long long l, long long r, long long x, long long y) {
    if (r < x || l > y || n == 0) return 0;
    if (n == 1) return 1;
    long long mid = (x + y) / 2;
    return solve(n / 2, l, r, x, mid - 1) + solve(n % 2, l, r, mid, mid) + solve(n / 2, l, r, mid + 1, y);
}

int main() {
    long long n, l, r;
    long long ans;
    scanf("%lld %lld %lld", &n, &l, &r);
    long long max = 1; while (max <= n) { max *= 2; }
    ans = solve(n, l, r, 1, max);
    printf("%lld\n", ans);
    return 0;
}