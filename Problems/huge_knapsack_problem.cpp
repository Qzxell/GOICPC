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
        ll n,W;	
        cin >> n >> W;
        vector<pair<ll,ll>> vw(n);
        f(i,0,n){
                ll v,w;
                cin >> v >> w;
                vw[i] = {v,w};
        }
        if(n <= 20){
                ll ans = 0;
                ll acu_v,acu_w;
                f(mask,0,(1<<n)){
                        acu_v = acu_w = 0;
                        f(i,0,20)if((mask>>i)&1){
                                acu_v += vw[i].fi;
                                acu_w += vw[i].se;
                        }
                        if(acu_w <= W)ans = max(ans,acu_v);
                }
                cout << ans <<ln;
                return;
        }
        ll acu_v,acu_w;
        vector<pair<ll,ll>> group1;
        vector<pair<ll,ll>> group2;
        f(mask,0,(1<<20)){
                acu_v = acu_w = 0;
                f(i,0,20)if((mask>>i)&1){
                        acu_v += vw[i].fi;
                        acu_w += vw[i].se;
                }
                group1.pb({acu_w,acu_v});
        }
        f(mask,0,(1<<(n-20))){
                acu_v = acu_w = 0;
                f(i,0,20)if((mask>>i)&1){
                        acu_v += vw[i+20].fi;
                        acu_w += vw[i+20].se;
                }
                group2.pb({acu_w,acu_v});
        }
        sort(all(group1));
        f(i,1,sz(group1)){
                group1[i].se = max(group1[i].se,group1[i-1].se);
        }
        ll ans = 0;
        f(i,0,sz(group2)){
                ll w_cur = group2[i].fi;
                ll v_cur = group2[i].se;
                int lo = 0 , lf = sz(group1)-1,mid;
                while(lo < lf){
                        mid = (lo+lf+1)/2;
                        if(group1[mid].fi + w_cur <= W)lo = mid;
                        else lf = mid-1;
                }
                if(group1[lo].fi + w_cur > W)continue;
                ans = max(ans, v_cur + group1[lo].se);
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
