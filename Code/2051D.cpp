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
	//cout << "test" << ' ' << test << " :" << ln;
	ll n, x ,y;	
	cin >> n >> x >> y;
	vi v(n);
	ll sum = 0;
	f(i,0,n){
		cin >> v[i];
		sum += v[i];
	}
	sort(all(v));
	ll ans = 0;
	f(i,0,n-1){
		ll wasa = sum - v[i];
		int lo = i+1 ,lf = n-1;
		int mid;
		int sup, inf ;
		while( lo < lf){
			mid = (lo+lf)/2;
			if(wasa - v[mid] <= y)lf = mid;
			else lo = mid+1;
		}
		if(wasa - v[lo] > y){
			ans += 0;
			continue;
		}
		inf = lo;
		lo = i+1;lf = n-1;
		while( lo < lf){
			mid = (lo+lf+1)/2;
			if(wasa - v[mid] >= x)lo = mid;
			else lf = mid - 1;
		}
		if( lo == i+1 and wasa - v[lo] < x){
			continue;
		}
		sup = lo -1;
		if( wasa - v[lo] >= x){
			sup = lo;
		}
		//cout << v[i] << ':' << inf << ' ' << sup << ln;
		ans += max(0,sup-inf+1);
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
