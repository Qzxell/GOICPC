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

const ll INF = 1e17 + 9;
const int N = 3e5 + 5;
const int MX = __lg(N) + 5;

ll dp[N];
int dp_p[N][MX];
int G[N][2];
ll dp_acu[N][MX];
int tin[N],line[N+N+N+5];

int tim = 0;

ll add (ll a, ll b){
	return min(INF,a+b);
}
void dfs(int nod){
	bool ok = 0;
	line[tim] = nod;
	tin[nod] = tim++;
	dp[nod] = 0;
	for(auto x : G[nod]) if(x!=0){
		dp_p[x][0] = nod;
		dfs(x);

		line[tim++] = nod;
		dp[nod] += dp[x];
		ok = 1;
	}
	if(ok) dp[nod] += 4;
}

int solve (int nod, int k){
	int cur = k;
	for(int i = MX - 1; i >= 0 ; i--){
		if(cur >= dp_acu[nod][i]){
			cur -= dp_acu[nod][i];
			nod = dp_p[nod][i];
		}
	}
	return line[tin[nod] + cur];
}

void so(int test){
	int n,q;
	cin >> n >> q;


	forsn(i,1,n+1){
		int l,r;
		cin >> l >> r;
		G[i][0] = l;
		G[i][1] = r;
	}
	dfs(1);

	forsn(j,1,MX) forsn(i,1,n+1)
			dp_p[i][j] = dp_p[dp_p[i][j-1]][j-1];

	forsn(i,1,n+1)
		dp_acu[i][0] = add(1, dp[i]);

	forsn(j,1,MX)
		for(int i = 1; i <= n; i++){
			int pa = dp_p[i][j-1];
			dp_acu[i][j] = add(dp_acu[i][j-1] , dp_acu[pa][j-1]);
		}

	forn(i,q){
		int v,k;
		cin >> v >> k;
		//solve(v,k);
		cout << solve(v,k) << ' ';
	}
	cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
