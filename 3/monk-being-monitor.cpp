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
        vector< pair<int, int> > acc;
        int cur = heights[0], count = 0;
        for(int i=0; i<n; i++) {
            if (cur == heights[i]) {
                count++;
            }
            else {
                acc.push_back(make_pair(count, heights[i]));
                count = 1;
                cur = heights[i];
            }
        }
        acc.push_back(make_pair(count, heights[n-1]));

        int len = acc.size()-1;
        int greatest_count_till_now = 0;
        int height_with_max_count = 0;
        int maxDiff = 0;
        bool changed = false;
        pair<int, int> ans;

        while(len >= 0) {
            if (greatest_count_till_now < acc[len].first) {
                greatest_count_till_now = acc[len].first;
                height_with_max_count = acc[len].second;
            }
            if (maxDiff < (acc[len].first - greatest_count_till_now)) {
                changed = true;
                maxDiff = (acc[len].first - greatest_count_till_now);
                ans.first = height_with_max_count;
                ans.second = acc[len].second;
            }
            len--;
        }

        if (changed) {
            cout << maxDiff << endl;
        } else {
            cout << 1 << endl;
        }
    }
    return 0;
}