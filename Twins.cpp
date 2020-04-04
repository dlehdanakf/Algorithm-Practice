#include <stdio.h>
#include <algorithm>
using namespace std;

int a[200];

int main(void) {
    int n, i, sum, half, total = 0;
    long long ans = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        total += a[i];
    }

    half = total / 2;
    sort(a, a + n);

    i = n - 1;
    while(sum <= half) {
        sum += a[i];

        ans++;
        i--;
    }

    printf("%lld\n", ans);
    return 0;
}
