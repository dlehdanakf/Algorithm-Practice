#include <stdio.h>

int a[100002];
long long p1[100002];
long long p2[100002];
char ans[10002];

char check(int n) {
    int j;
    for(j = n; j >= 1; j--) {
        p2[j] = p2[j + 1] + a[j];

        if((j != n && p1[j] >= p1[n]) || (j != 1 && p2[j] >= p1[n])) {
            return 'N';
        }
    }

    return 'Y';
}
int main(void) {
    int i, j, t, n;
    char _has_negative;

    a[0] = 0;
    p1[0] = 0;
    p2[100001] = 0;

    scanf("%d", &t);
    for(i = 0; i < t; i++) {
        _has_negative = 'N';

        scanf("%d", &n);
        for(j = 1; j <= n; j++) {
            scanf("%d", &a[j]);
            p1[j] = p1[j - 1] + a[j];
            if(a[j] <= 0) {
                _has_negative = 'Y';
            }
        }

        if(_has_negative == 'N') {
            ans[i] = 'Y'; continue;
        }

        ans[i] = check(n);
    }

    for(i = 0; i < t; i++) {
        if(ans[i] == 'N') {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}
