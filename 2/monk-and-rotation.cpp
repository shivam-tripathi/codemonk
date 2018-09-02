#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int arr[n];
		int count = 0;
		while(count < n) {
			cin >> arr[k++];
			k %= n;
			count++;
		}
		for(int i=0; i<n; i++) {
			cout << arr[i] << ' ';
		}
	}
	return 0;
}