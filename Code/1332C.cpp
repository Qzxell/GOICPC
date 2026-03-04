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
	int n , k;
	cin >> n >> k;
	string s;
	cin >> s;
	vi v(n);

	set<int> adj[n+1];

	int color = 1;
	for(int i = 0;i < k; i++){
		int wasa = color++;
		for(int j = i; j < n ; j+= k)v[j] = wasa; 
	}

	int u,to;	
	for(int i = 0;i < n/2;i++){
		if(v[i] != v[n-i-1]){
			u = v[i];
			to = v[n-i-1];
			adj[u].insert(to);
			adj[to].insert(u);
		}
	}
	queue<int> qu;
	vector<bool> vis(n+1,0);
	vi cul(n+1,0);
	auto BFS = [&](int root){
		qu.push(root);
		int col = root;
		while(!qu.empty()){
			int uu = qu.front();
			vis[uu] = 1;
			cul[uu] = col;
			qu.pop();
			for(auto x : adj[uu])if(!vis[x]){
				qu.push(x);
			}
		}
	};
	f(i,1,k+1)if(!vis[i]){
		BFS(i);
	}
	vector<vi> abe(n+1,vi(27));
	f(i,0,n){
		abe[cul[v[i]]][s[i] -'a']++;
	}
	int ans = 0;
	f(i,1,n+1){
		int to = 0;
		int ma = 0;
		f(j,0,27){
			to += abe[i][j];
			ma = max(abe[i][j],ma);
		}
		ans += to - ma;
	}
	cout << ans << ln;
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
