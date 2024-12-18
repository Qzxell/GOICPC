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
	int n,m,q;
	cin >> n >> m >> q;
	vi v(m);
	f(i,0,m)cin >> v[i];
	sort(all(v));
	while(q--){
		int pos;
		cin >> pos;
		int ga = lower_bound(all(v),pos) - v.begin();
		if(ga < m and v[ga] == pos){
			cout << 0 << ln;
			continue;
		}
		int lo,lf;
		if(ga == m){
			cout << n - v.back() << ln;
			continue;
		}else if(ga == 0){
			cout << v[ga]-1 << ln;
			continue;
		}else{
			lo = v[ga-1];
			if(lo == pos){
				cout << 0 << ln;
				continue;
			}
			lf = v[ga];
			cout << (lf-lo)/2 << ln;
			continue;
		}
	}
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
