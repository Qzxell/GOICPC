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
	int n,m,d;
	cin >> n >> m >> d;
	vi v(m);
	f(i,0,m)cin >> v[i];
	v.insert(v.begin(), 1 - d);
	v.push_back(n + 1);
	int mi = 2e9;
	ll acu = m-1;
	f(i,1,m+2) acu += (v[i] - 1 - v[i-1])/d;
	vi res;

	f(i,1,m+1){
		int nor,salt;
		nor =(v[i] - 1 - v[i-1])/d + (v[i+1] -1 - v[i])/d;
		salt =(v[i+1] - 1 - v[i-1])/d;
		swap(nor,salt);
		if(nor - salt < mi){
			mi = nor-salt;
			res.clear();
		}
		if(nor - salt == mi){
			res.pb(v[i]);
		}
	}
	cout << acu + mi << ' ' << res.size() <<  ln;
	
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
