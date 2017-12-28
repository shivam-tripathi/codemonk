#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int infs = 1e5+100;
const int inf = 1e9 + 100;
const ll infll = 1e18 + 500;
const ll base = 1e9 + 7;

int arr[20];
int n;

int solve(int val, int index, int op) {
    if (index >= n) return val;

    int a = arr[index];
    int val1;

    if (op == 0) {
        val1 = val | a;
    }

    if (op == 1) {
        val1 = val ^ a;
    }

    if (op == 2) {
        val1 = val + a;
    }

    int next1 = solve(val1, index+1, (op+1)%3);
    int next2 = solve(val, index+1, op);

    return (next1 > next2) ? next1 : next2;
}

int main(){
    int t;
    string temp;
    cin >> t;
    while(t--) {
        cin >> temp;
        int predict = (temp == "Even") ? 0 : 1;

        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }

        int parity = 0;
        int ans = -1;
        for(int i=0; i<n; i++) {
            int val = solve(arr[i], i+1, 0);
            if (ans < val) ans = val;
        }

        parity = ans%2;

        if (parity == predict) {
            cout << "Monk" << endl;
        }
        else cout << "Mariam" << endl;
    }
    return 0;
}
