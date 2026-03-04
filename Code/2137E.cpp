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
        int mex = 0;
        vi m(n+1,0);
        vi v(n);
        f(i,0,n){
                int x;
                cin >> x;
                v[i] = x;
                m[x]++;
                while(m[mex])mex++;
        }
        int prox_mex = mex;
        int inu = 0;
        ll ans = 0;
        vi aux(n);
        f(i,0,n){
                if(v[i] < mex){
                        if(m[v[i]] > 1){
                                prox_mex = min(prox_mex,v[i]);
                                aux[i] = mex;
                        }else aux[i] = v[i];
                }else aux[i] = mex;
        }
        if(k == 1){
                ans = 0;
                f(i,0,n){
                        ans+= aux[i];
                }
                cout << ans << ln;
                return;
        }
        f(i,0,n){
                if(aux[i] >= prox_mex)inu++;
                else ans += aux[i];
        }
        if(inu == 1){
                ans += mex;
                cout << ans << ln;
                return;
        }
        int eq = 1;
        f(i,0,n){
                if(aux[i] >= prox_mex){
                        if(aux[i] != prox_mex)eq =0;
                }
        }
        cout << ans + inu*1ll*((k+eq)&1 ? prox_mex +1: prox_mex) << ln;

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



