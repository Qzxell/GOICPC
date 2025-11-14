#include <bits/stdc++.h>

using namespace std;

using ii = pair<long long,long long>;
using vii = vector<ii>  ;
using vi = vector<long long>  ;
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
#define point complex<long long>
#define re real()
#define im imag()

void so(int test){
        int n;
        cin >> n;
        vi a(n),c(n);
        f(i,0,n)cin >> a[i];
        f(i,0,n)cin >> c[i];
        ll inf = LLONG_MAX;
        vector<vii> dp(2,vii(n+1,{inf,inf}));
        dp[0][0] = {0,1 };
        dp[1][0] = {0,1 };
        f(i,1,n+1){
                f(j,0,2)
                f(k,0,2)
                {
                        ii r1 = dp[j][i-1];
                        if(r1.fi == inf)continue;
                        ii &cur = dp[k][i];
                        if( k == 0){
                                if(r1.se > a[i-1])continue;
                                cur = min(cur,{r1.fi,a[i-1]});
                                continue;
                        }
                        if( k == 1){
                                cur = min(cur,{r1.fi + c[i-1] ,r1.se});
                                continue;
                        }
                }
        }
        cout << min(dp[0][n],dp[1][n]).fi << ln;
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



