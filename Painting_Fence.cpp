#include <stdio.h>

int a[5005];
int solve(int i, int j) {
    int vans, hans;
    vans = j - i + 1;

    int mini = a[i];
    for(int k = i + 1; k <= j; k++) {
        if(mini > a[k]) mini = a[k];
    }

    hans = mini;
    for(int k = i; k <= j; k++) {
        a[k] -= mini;
    }

    for(int k = i; k <= j;) {
        if(a[k] == 0) { k++; }
        else {
            int s, t;
            s = t = k;
            while(t <= j && a[t] != 0) { t++; }

            hans += solve(s, t - 1);
            k = t;
        }
    }

    if(vans < hans) return vans;
    return hans;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int ans = solve(1, n);
    printf("%d\n", ans);

    return 0;
}



