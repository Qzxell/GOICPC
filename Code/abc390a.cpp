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
	int h,w;
	cin >> h >> w;
	vector<string> v(h);
	f(i,0,h)cin >> v[i];
	bool ans = 1;
	ll u,d,t,c;
	u = d = t = c = 1e5;
	d = c = -1;
	f(i,0,h){
		f(j,0,w)if(v[i][j] == '#'){
			t = min(t,i);
			c = max(c,i);
			u = min(u,j);
			d = max(d,j);
		}
	}
	for(int i = t ; i <= c; i++){
		for(int j = u ; j <= d; j++){
			if(v[i][j] == '.')ans = 0;
		}
	}
	cout << ( ans ? "Yes" : "No");
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
