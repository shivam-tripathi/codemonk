// https://tinyurl.com/y8qqqyyf

#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int infs = 1e5+100;
const int inf = 1e9 + 100;
const ll infll = 1e18 + 500;
const ll base = 1e9 + 7;

int main(){
    ll match[32];

    for(int i=0; i<32; i++) {
        match[i] = (1LL<<i);
    }

    int t;
    cin >> t;
    while(t--) {
        int n;
        ll count[32] = {0};
        cin >> n;
        ll p;
        for(int i=0; i<n; i++) {
            cin >> p;
            for(int i=0; i<32; i++) {
                if (p & match[i]) {
                    count[i]++;
                }
            }
        }
        int max_=count[0], index=0;
        for(int i=1; i<32; i++) {
            if (max_<count[i]) {
                index = i;
                max_ = count[i];
            }
        }
        cout << index << endl;
    }
    return 0;
}
