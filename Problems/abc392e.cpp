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

const int N = 200003;

vi pha(N,0);

int who(int x){
	if(pha[x] != x)
		pha[x] = who(pha[x]);
	return pha[x];
}

void so(int test){
	int n,m;
	cin >> n >> m;
	f(i,0,n+1) pha[i] = i;
	vector<pair<int,ii>> edg;
	vector<pair<int,ii>> ans;
	f(i,0,m){
		int a,b;
		cin >> a >> b;
		if(who(a) != who(b)){
			pha[who(a)] = who(b);
		}else{
			edg.pb({(int)i+1,{a,b}});
		}
	}
	vi vis(n+1,0);
	vi leders;
	f(i,1,n+1){
		if(!vis[who(i)]){
			leders.pb(who(i));
		}
		vis[who(i)] = 1;
	}
	int root = leders.back();
	leders.pop_back();
	f(i,0,n+1)vis[i] = 0;
	vis[root] = 1;

	for(auto war : edg){
		if(!vis[who(war.se.fi)]){
			vis[who(war.se.fi)] = 1;
			war.se.se = root;
			ans.pb(war);
		}else{
			while(sz(leders) and vis[leders.back()])leders.pop_back();
			if(sz(leders) == 0)continue;
			war.se.se = leders.back();
			ans.pb(war);
			vis[leders.back()] = 1;
		}
	}
	cout << sz(ans)<<ln;
	for(auto [a,bc] : ans){
		auto [b,c] = bc;
		cout << a << ' ' << b << ' ' << c << ln;
	}

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
