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
	int n,m;
	cin >> n >> m;
	vi adj[n+1];
	vi vis(n+1,0);
	vis[1] = 1;
	f(i,0,m){
		int a,b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	queue<int>qu;
	qu.push(1);
	while(!qu.empty()){
		int fr = qu.front();qu.pop();
		vis[fr] = 1;
		for(auto x : adj[fr])if(!vis[x]){
			qu.push(x);
		}
	}
	vi ans;
	f(i,1,n+1)if(!vis[i])ans.pb(i);
	if(ans.empty()){
		cout << "Connected";
		return;
	}
	for(auto x : ans)cout << x << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
