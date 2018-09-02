#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string tag = s.size() % 2 ? "ODD" : "EVEN";

        int l = 0, r = s.size()-1;
        bool palin = true;
        while(l<=r) {
            if (s[l] != s[r]) {
                palin = false;
                break;
            }
            l++;
            r--;
        }

        if (!palin) {
            cout << "NO" << endl;
        } else {
            cout << "YES " << tag << endl;
        }
    }
    return 0;
}
