#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
	int tt;
	cin >> tt;
	while(tt--){
	    int n, k;
	    cin >> n >> k;

	    vector<char> desired(n);  // Color deseado ('R' o 'B')
	    vector<int> penalty(n);   // Penalización si queda mal pintado

	    for (int i = 0; i < n; i++) cin >> desired[i];
	    for (int i = 0; i < n; i++) cin >> penalty[i];

	    vector<int> dp(n + 1, INF);
	    dp[0] = 0;  // No hay penalización al inicio

	    deque<int> dq;
	    dq.push_back(0);

	    for (int i = 1; i <= n; i++) {
		while (!dq.empty() && dq.front() < i - k) {
		    dq.pop_front();
		}

		dp[i] = dp[dq.front()] + (desired[i - 1] == 'R' ? penalty[i - 1] : 0);

		while (!dq.empty() && dp[dq.back()] >= dp[i]) {
		    dq.pop_back();
		}
		dq.push_back(i);
	    }

	    cout << dp[n] << endl;
	}
    return 0;
}
