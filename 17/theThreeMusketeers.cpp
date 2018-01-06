// https://preview.tinyurl.com/yavvxbvl

#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int infs = 1e5+100;
const int inf = 1e9 + 100;
const ll infll = 1e18 + 500;
const ll base = 1e9 + 7;


ll binom(int x) {
    if (x < 3) return 0;

    x--;
    return (x-1LL)*x*(x+1LL)/6LL;
}

set<string> _set;

int main(){


    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        int c_a = 0, c_e = 0, c_i = 0, c_o = 0, c_u = 0;

        int ab, ac, ad, ae, bc, bd, be, cd, ce, de;
        ab = 0, ac = 0, ad = 0, ae = 0, bc = 0, bd = 0, be = 0, cd = 0, ce = 0, de = 0;

        int abc, abd, abe, acd, ace, ade, bcd, bce, bde, cde;
        abc = 0, abd = 0, abe = 0, acd = 0, ace = 0, ade = 0, bcd = 0, bce = 0, bde = 0, cde = 0;

        int abcd, abce, abde, bcde, acde;
        abcd =0, abce =0, abde =0, bcde =0, acde = 0;

        int abcde;
        abcde = 0;

        char s[20];
        while(n--) {
            bool a=false, b=false, c=false, d=false, e=false;
            scanf("%s", s);
            for(int k=0; k<strlen(s); k++) {
                if (s[k] == 'a') a = true;
                if (s[k] == 'e') b = true;
                if (s[k] == 'i') c = true;
                if (s[k] == 'o') d = true;
                if (s[k] == 'u') e = true;
            }

            if (a) {
                    c_a++;
                    if (b) ab++;
                    if (c) ac++;
                    if (d) ad++;
                    if (e) ae++;
            }
            // aeiou
            if (b) {
                c_e++;
                if (c) bc++;
                if (d) bd++;
                if (e) be++;
            }
            if (c) {
                c_i++;
                if (d) cd++;
                if (e) ce++;
            }
            if (d) {
                c_o++;
                if (e) de++;
            }
            if (e) c_u++;

            if (a && b && c) abc++;
            if (a && b && d) abd++;
            if (a && b && e) abe++;
            if (a && c && d) acd++;
            if (a && c && e) ace++;
            if (a && d && e) ade++;
            if (b && c && d) bcd++;
            if (b && c && e) bce++;
            if (b && d && e) bde++;
            if (c && d && e) cde++;

            if (a && b && c && d) abcd++;
            if (a && b && c && e) abce++;
            if (a && b && d && e) abde++;
            if (b && c && d && e) bcde++;
            if (a && c && d && e) acde++;

            if (a && b && c && d && e) abcde++;
        }

        ll ans = 0;

        ans += binom(c_a);
        ans += binom(c_e);
        ans += binom(c_i);
        ans += binom(c_o);
        ans += binom(c_u);

        ans -= binom(ab);
        ans -= binom(ac);
        ans -= binom(ad);
        ans -= binom(ae);
        ans -= binom(bc);
        ans -= binom(bd);
        ans -= binom(be);
        ans -= binom(cd);
        ans -= binom(ce);
        ans -= binom(de);

        ans += binom(abc);
        ans += binom(abd);
        ans += binom(abe);
        ans += binom(acd);
        ans += binom(ace);
        ans += binom(ade);
        ans += binom(bcd);
        ans += binom(bce);
        ans += binom(bde);
        ans += binom(cde);

        ans -= binom(abcd);
        ans -= binom(abce);
        ans -= binom(abde);
        ans -= binom(bcde);
        ans -= binom(acde);

        ans += binom(abcde);

        cout << ans << endl;
    }
    return 0;
}