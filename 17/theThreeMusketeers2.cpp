// https://tinyurl.com/yavvxbvl

#pragma GCC optimize ("O3")
#include <stdio.h>
#include <string.h>
using namespace std;

typedef long long ll;

int n;
int vowels[(int)1e4+10];
ll dp[(int)1e4+10][32][3];

ll solve(int mask, int index, int done) {
    // printf(">%d >= %d, %d\n", index, n);
    if (index >= n) return 0;

    if (dp[index][mask][done] != -1) return dp[index][mask][done];

    ll count = 0;
    int temp = mask & vowels[index];
    if (temp) {
        if ((done+1) == 3) count++;
        else count += solve(temp, index+1, done+1);
    }
    count += solve(mask, index+1, done);
    dp[index][mask][done] = count;
    // printf("%lld\n",count);
    return count;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for(int i=0; i<n; i++) vowels[i] = 0;
        memset(dp, -1, sizeof dp);
        // count = 0;
        char s[20];

        int _n = n;

        while(_n--) {
            scanf("%s", s);
            bool a = true, b = true, c = true, d = true, e = true;
            for(int i=0; i<strlen(s); i++) {
                if (a && s[i] == 'a') {
                    a = false;
                    vowels[_n] = vowels[_n] | 1;
                }
                if (b && s[i] == 'e') {
                    b = false;
                    vowels[_n] = vowels[_n] | 2;
                }
                if (c && s[i] == 'i') {
                    c = false;
                    vowels[_n] = vowels[_n] | 4;
                }
                if (d && s[i] == 'o') {
                    d = false;
                    vowels[_n] = vowels[_n] | 8;
                }
                if (e && s[i] == 'u') {
                    e = false;
                    vowels[_n] = vowels[_n] | 16;
                }
            }
        }

        // printf("%d\n",n);
        ll count = solve(31, 0, 0);
        printf("%lld\n",count);
    }
    return 0;
}
