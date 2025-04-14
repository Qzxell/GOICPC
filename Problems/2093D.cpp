#include <bits/stdc++.h>

using namespace std;

using ii = pair<long long,long long>;
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

ll qu(int n, ll l ,ll r){
        if(n ==0){
                return 1;
        }
        ll le = (1ll<<n);
        ll mi = (le>>1);
        ll cu_x,cu_y;
        if(l > mi)cu_x = 1;
        else cu_x = 0;
        if(r > mi)cu_y = 1;
        else cu_y = 0;
        ll lost = qu(n-1,l- cu_x*mi, r -cu_y*mi);

        if(cu_x == 0 and cu_y == 0){
                return lost;
        }
        if(cu_x == 1 and cu_y == 1){
                ll ret = lost + mi*mi;
                return ret;
        }
        if(cu_x == 1 and cu_y == 0){
                ll ret = lost + 2*mi*mi;
                return ret;
        }
        if(cu_x == 0 and cu_y == 1){
                ll ret = lost + 3*mi*mi;
                return ret;
        }
        return lost;

}

ii fin(int n,ll num){
        if(n == 0){
                return {0,0};
        }
        ll le = (1ll<<n);
        ll mi = (le>>1);
        ll cap = (mi*mi);
        ll now = num%(cap);
        ii lost = fin(n-1,now);
        if(num < mi*mi) return lost;
        if(num < 2*mi*mi) return {lost.fi + mi,lost.se + mi};
        if(num < 3*mi*mi) return {lost.fi + mi,lost.se };
        if(num < 4*mi*mi) return {lost.fi,lost.se + mi};
        return lost;
}

void so(int test){
        int n;
        cin >> n;
        int q;
        cin >> q;
        f(i,0,q){
                string s;
                cin >> s;
                ll l,r,nu;
                if(s == "->"){
                        cin >> l >> r;
                        ll ans = qu(n,l,r);
                        cout << ans << ln;
                }
                else{
                        cin >> nu;
                        ii ans = fin(n,nu-1);
                        cout << ans.fi+1 << ' ' << ans.se+1 << ln;
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
