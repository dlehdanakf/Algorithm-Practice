#include <stdio.h>

int a[5005];
int p[5005];
int n, k;

int main(void) {
    int i, j;
    double ans = 0;

    scanf("%d", &n);
    scanf("%d", &k);

    a[0] = p[0] = 0;
    for(i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        p[i] = p[i - 1] + a[i];
    }

    for(i = 1; i <= n; i++) {
        for(j = i + k - 1; j <= n; j++) {
            int sum = p[j] - p[i - 1];
            double avg = ((double) sum) / (j - i + 1);

            if(ans < avg) {
                ans = avg;
            }
        }
    }

    printf("%.15f", ans);
    return 0;
}
