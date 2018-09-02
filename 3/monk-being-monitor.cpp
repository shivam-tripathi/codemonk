#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

const int SIZE = (int)1e5+100;
int main() {
    int t, n, heights[SIZE];

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> heights[i];
        }

        // Sort the heights
        std::sort(heights, heights+n);

        // Accumulate heights
        vector<int> acc;
        int cur = heights[0], count = 0;
        for(int i=0; i<n; i++) {
            if (cur == heights[i]) {
                count++;
            }
            else {
                acc.push_back(count);
                count = 1;
                cur = heights[i];
            }
        }
        acc.push_back(count);

        if (acc.size() == 1) {
            cout << -1 << endl;
            continue;
        }

        int len = acc.size() - 2;
        int greatest_count_till_now = acc[acc.size()-1];
        int maxDiff = 0;

        while(len >= 0) {
            maxDiff = max(maxDiff, greatest_count_till_now - acc[len]);
            greatest_count_till_now = max(greatest_count_till_now, acc[len]);
            len--;
        }

        cout << maxDiff << endl;
    }
    return 0;
}
