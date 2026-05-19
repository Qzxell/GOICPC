#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

const int N = 5005;
ll dp[N][N];

void so(int test){
	int n,m,k;
	cin >> n >> m >> k;
	vl v(n),ps(n+1,0);
	forn(i,n){
		cin >> v[i];
		ps[i+1] = ps[i] + v[i];
	}
	auto sum = [&](int l, int r)->ll{
		return ps[r] - ps[l-1];
	};

	for(int t_k = 0; t_k < k; t_k++) forsn(pos,0,n+1)
	{
		dp[pos+1][t_k] = max(dp[pos+1][t_k] , dp[pos][t_k]);
		if(pos+m <= n)
			dp[pos+m][t_k+1] = max(dp[pos+m][t_k+1] , dp[pos][t_k] + sum(pos+1,pos+m));
	}

	ll ans = -1;
	forsn(i,1,n+1){
		ans = max(ans,dp[i][k]);
	}
	cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

