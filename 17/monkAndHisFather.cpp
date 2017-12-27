// https://tinyurl.com/ya28nd78
// This program asks for minimum number of visits to money god, not minimum number of dollars

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll powers[60];

int find(ll val) {
	int low = 0, high = 59, mid;
	while(low<high) {
		mid = low + (high-low+1)/2;
		if (powers[mid] == val) {
			return mid;
		}
		if (powers[mid] < val) {
			low = mid;
		}
		if (powers[mid] > val) {
			high = mid-1;
		}
	}
	return low;
}

int main(int argc, char const *argv[]) {
	int t;
	cin >> t;
	powers[0] = 1;
	for(int i=1; i<60; i++) {
		powers[i] = 2*powers[i-1];
	}

	// for (int i = 0; i < 60; ++i) {
	// 	cout << powers[i] << endl;
	// }

	while(t--) {
		ll p;
		cin >> p;

		ll ans=0;
		while(p>0) {
			if (p == 1) {
				ans++;
				break;
			}
			int index = find(p);
			// ans += powers[index-1];
			ans++;
			p -= powers[index];
		}
		cout << ans << endl;
	}
	return 0;
}

