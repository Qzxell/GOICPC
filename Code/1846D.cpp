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
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	double n,d,h;
	cin >> n >> d >> h;
	double ans = 0;
	vi v(n);
	f(i,0,n)cin >> v[i];

	f(i,0,n){
		if(i == n-1){
			ans += (double)(d*h)/2.0;
			break;
		}
		int l = v[i+1] - v[i];
		if(l >= h ){
			ans += (double)(d*h)/2.0;
			continue;
		}
		double ga = (1.0/2.0)*(double)(d + d*(double)(h - l)/h)*(double)l;
		ans += ga;
	}
	cout << ans << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(6);

    int tt = 1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
