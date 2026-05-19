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
#define pb push_back
#define imp(v) {for(auto x:v)cout<<x<<' ';cout<<'\n';}

void so(int test){
	int n,m;
	cin >> n >> m;

	vector<vi> G(n);
	forn(i,m){
		int u,v;
		cin >> u >> v;
		u--;v--;
		G[u].pb(v);
	}
	vi sig(n);
	vi per(n);
	sig[0] = 1;
	int tam = 0;
	int ans = 1;
	queue<int> qu;
	forn(i,n){
		per[i] = 1;
		if(sig[i]){
			ans--;
			tam++;
			per[i] = 0;
			qu.push(i);
			while(!qu.empty()){
				int fr = qu.front();qu.pop();
				for(auto x : G[fr])if(x > i){
					if(!sig[x])
						ans++;
					sig[x] = 1;
				}
				for(auto x : G[fr])if(per[x]){
					tam++;
					qu.push(x);
					per[x] = 0;
				}
			}
			if(tam != i + 1)
				cout << -1 << '\n';
			else
				cout << ans << '\n';
		}else{
			cout << -1 << '\n';
		}
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
