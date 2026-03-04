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

const int N = 2e5 + 5;
vi G[N];
int dp[N];
int dp2[N];
int n;

void dfs(int nod,int pat){
	dp[nod] = nod;
	dp2[nod] = n+1;
	for(auto to : G[nod])if(to != pat){
		dfs(to,nod);
		dp[nod] = min(dp[nod],dp[to]);
		dp2[nod] = min(dp2[nod],dp[to]);
	}
}


void so(int test){
	cin >> n;
	forn(i,n-1){
		int u,v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	vi ans(n+1);
	forsn(i,1,n+1){
		ans[i] = dp2[i] - 1;
	}
	ans[1] = -1;
	int nod = -1;
	for(auto x : G[1]){
		if(dp[x] == 2){
			nod = x;
		}
	}
	vi v(n+2,0);
	vi vis(n+2,0);
	queue<int> qu;
	qu.push(nod);
	vis[1] = 1;
	v[1] = 1;
	vis[nod] = 1;
	int mex = 1;
	while(!qu.empty()){
		int fr = qu.front();qu.pop();
		v[fr] = 1;
		while(v[mex] > 0)mex++;
		for(auto x : G[fr]) if(!vis[x]){
			qu.push(x);
			vis[x] = 1;
		}
	}
	ans[1] = mex-1;
	forsn(i,1,n+1)
		cout << ans[i] << " \n"[i==n];
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

