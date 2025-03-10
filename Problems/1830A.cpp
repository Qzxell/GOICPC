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
	vii adj[n+1];//  weight, to
	f(i,1,n){
		int a,b;
		cin >> a >> b;
		adj[a].pb({i,b});
		adj[b].pb({i,a});
	}
	queue<ii> qu;
	vi punt(n+1,0);
	punt[1] = 1;
	qu.push({1,0});// node, punt
	vi vis(n+1,0);
	while(!qu.empty()){
		auto [cur,scor] = qu.front();
		vis[cur] = 1;
		qu.pop();
		for(auto [w,to] : adj[cur])if(!vis[to]){
			if(w > scor){
				qu.push({to,w});
				punt[to] = punt[cur];
			} else {
				qu.push({to,w});
				punt[to] = punt[cur] + 1;
			}
		}
	}
	int ans = 0;
	f(i,1,n+1)ans = max(ans,punt[i]);
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
