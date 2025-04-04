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
        vii wa(n+1,{-1,-1});
        vi v(2*n);
        f(i,0,2*n){
                cin >> v[i];
                if(wa[v[i]].fi != -1)wa[v[i]].se = i;
                else wa[v[i]].fi = i;
        }
        sort(all(wa));
        int ans  =0;
        f(i,0,n){
                if(wa[i+1].fi - wa[i].fi != 1)continue;
                if(wa[i].se - wa[i].fi == 1)continue;
                if(wa[i+1].se - wa[i+1].fi == 1)continue;
                if(abs(wa[i+1].se - wa[i].se) == 1)ans++;
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
