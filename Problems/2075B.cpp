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
	int n,k;
	cin >> n >> k;
	vi v(n);
	f(i, 0 , n)cin >> v[i];
	if(k==1){
		vi vv;
		vv.pb(v[0]);
		vv.pb(v[n-1]);
		int wasa= 0;
		f(i,1,n-1)wasa=max(wasa,v[i]);
		vv.pb(wasa);
		sort(all(vv));
		cout<< vv[1] + vv[2] << ln;
		return;
	}
	sort(rall(v));
	ll acu = 0 ;
	f(i,0,k+1)acu += v[i];
	cout << acu << ln;
	
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
