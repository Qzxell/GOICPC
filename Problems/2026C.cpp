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
<<<<<<< HEAD
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int dis = 0;
        f(i,0,n){
                dis++;
                if(s[i] == '1'){
                        
                }
        }
=======
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(n==1){
		cout << 1 << ln;
		return;
	}
	vi ind;
	f(i,0,n)if(s[i] == '1')ind.pb(i+1);
	int le = sz(ind);

	auto can = [&](int c){
		int in = le - c;
		int res = 0;
		ll acu = 0;
		f(i,in,le){
			if(ind[i] - res > 1){
				acu += ind[i];
				res += 2;
			}else {
				return -1ll;
			}
		}

		return acu;
	};
	int lo = 0, lf = le,mid;
	ll ans = -2;
	//return;
	while(lo < lf){
		mid = (lo+lf+1)/2;
		if(can(mid) >= 0){
			lo = mid;
			ans = can(mid);
		}else{
			lf = mid - 1;
		}
	}
	cout << (n*1ll*(n+1))/2 - ans << ln;
>>>>>>> 587772d4b7b6d3cce06f52c44301c74db1273d3f
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
