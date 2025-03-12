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
	int root;
	int edg = m;
	f(i,0,m){
		int u,v;
		cin >> u >> v;
		if(u==v){
			continue;
		}
		root = u;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int cont = 0;
	f(i,1,n+1){
		if(adj[i].empty())continue;
		sort(all(adj[i]));
		int le = sz(adj[i]);
		f(j,0,le){
			int cur = j;
			cont++;
			while(cur + 1 < le and adj[i][cur+1] == adj[i][j])cur++;
			j = cur;
		}
	}
	cout << edg - cont/2;

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
