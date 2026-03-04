#include <bits/stdc++.h>

using namespace std;

const int N  = 1e5 + 5;
const int INF  = (1<<30);
int dp[N][27];//estoy aca, como propago 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int k ,a,b;
	cin >> k;
	vector<int> pro(27,-1);
	for(int i = 1; i <= k ;i++){
		string ab;
		cin >> ab;
		a = ab[0] - 'a';
		b = ab[1]-'a';
		pro[a]=b;
		pro[b]=a;
	}
	int n = s.size();
	for(int i = 0 ; i < N;i++)
	for(int j = 0 ; j < 27;j++)
		dp[i][j] = INF;

	dp[0][26] = 0;

	for(int i = 0; i <= n-1 ;i++){
		for(int ch = 0; ch < 27; ch++){
			int ind = i-1;
			int ne =i;
			int proxi = s[ne] - 'a';
			if(proxi != pro[ch]){
				dp[i+1][proxi] = min(dp[i+1][proxi],dp[i][ch]);
			}
			dp[i+1][ch] = min(dp[i+1][ch],dp[i][ch] + 1);
		}
	}
	//for(int i = 1; i <= n-1 ;i++){
		//for(int ch = 0; ch < 26; ch++){
			//cout << (dp[i][ch] == INF ? -1 : dp[i][ch]) << ' ';
		//}
		//cout << '\n';
	//}
	int ans = n;
	for(int i = 0; i < 26;i++){
		ans = min(ans,dp[n][i]);
	}
	cout << ans << '\n';

	return 0;
}
