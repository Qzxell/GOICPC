#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	int n;
	cin >> n;
	vi v(n+1);//index-1
	f(i,1,n+1)cin >> v[i];
	string s;
	cin >> s;
	vi dp(n+1,-1);
	vi vis(n+1,0);
	auto dfs = [&](int u){
		int cur = u;
		int con = 0;
		while(vis[cur] != 1){
			con += (s[cur-1] == '0' ? 1 : 0);
			vis[cur]++;
			cur = v[cur];
		}
		while(vis[cur] != 2){
			dp[cur] = con;
			vis[cur]++;
			cur = v[cur];
		}
	};
	f(i,1,n+1){
		if(dp[i] == -1)dfs(i);
		cout << dp[i] << ' ';
	}
	cout << ln;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
