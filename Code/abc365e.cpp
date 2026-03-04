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

ll ans = 0;
const int N = 2e5 + 1;
vector<ll> v(N);

bool sp(ll x,int pos){ return ((x>>pos)&1); }

ll fu(int sh, int pos){
	if (pos == 0 ) return sp(v[0],sh);
	int onn = fu(sh, pos -1);
	int off = pos - onn;
	if( sp(v[pos],sh) ){
		swap(onn,off);	
		ans += (1ll<<sh)*onn;
		onn++;
	}else {
		ans += (1ll<<sh)*onn;
	}
	return onn;
}
void so(int test){
	int n;
	cin >> n;
	f(i,0,n)cin >> v[i];
	f(i,0,62){
		ll wa = fu(i,n-1);
	}

	cout << ans << ln;

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
