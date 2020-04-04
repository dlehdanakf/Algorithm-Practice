#include <stdio.h>

int main(void) {
    int i, a, n;
    int g1, g2, g3, g4;
    int ans = 0;

    scanf("%d", &n);
    g1 = g2 = g3 = g4 = 0;
    for(i = 0; i < n; i++) {
        scanf("%d", &a);

        switch(a) {
            case 1: g1 += 1; break;
            case 2: g2 += 1; break;
            case 3: g3 += 1; break;
            case 4: g4 += 1; break;
        }
    }

    // for g4
    ans += g4;

    // for g3
    ans += g3;
    if(g3 <= g1) { g1 = g1 - g3; }
    else { g1 = 0; }

    // for g2;
    ans += g2 / 2;
    if(g2 % 2 == 1) {
        ans += 1;

        if(g1 > 1) { g1 = g1 - 2; }
        else if(g1 == 1) { g1 = g1 - 1; }
    }

    // for g1
    if(g1 >= 1) {
        ans += g1 / 4;
        if(g1 % 4 > 0) {
            ans += 1;
        }
    }

    printf("%d", ans);
    return 0;
}