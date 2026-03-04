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
	map<int,vi>m;
	f(i,0,n){
		int x;
		cin >> x;
		m[x].pb(i);
	}
	int ans = -1;
	for(auto x: m){
		if(sz(x.se) == 1)continue;
		int ma = 1e9;
		int le = sz(x.se);
		f(i,0,le-1){
			ma = min(ma,x.se[i+1]-x.se[i] +1);
		}
		if(ans == -1)ans = ma;
		else ans = min(ans,ma);
	}
	cout << ans ;
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
