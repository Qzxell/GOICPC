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
	vii was;
	f(i,1,n+1){
		int x;
		cin >> x;
		if(x < i)was.pb({x,i});
	}
	sort(all(was));
	ll ans = 0;
	f(i,0,sz(was)){
		int pu = was[i].se;
		int li = 0, lf = sz(was),mid;
		while(li < lf){
			mid = (li+lf)/2;
			if(was[mid].fi > pu)lf = mid;
			else li = mid+1;
		}
		if(was[li].fi <= pu)continue;
		ans += sz(was)-li;
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
