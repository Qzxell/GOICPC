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
	vi v(n);
	int pr,im;
	pr = im = 0;
	ll acu = 0;
	int ma = 0;
	vi imp;
	f(i,0,n){
		cin >> v[i];
		ma = max(ma,v[i]);
		if(v[i]&1){
			im++;
			imp.pb(v[i]);
		} else {
			pr++;
		}
		acu += v[i];
	}
	if(im == 0 or pr == 0){
		cout << ma << ln;
		return;
	}
	cout << acu  - im + 1<< ln;

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
