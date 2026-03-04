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
        vi a(n),b(n);
        f(i,0,n)cin >> a[i];
        f(i,0,n)cin >> b[i];
        vector<vector<ll>> dp(n+1,vector<ll>(n+1));
        f(i,0,n){
                int l = i; int r = i;
                ll acu = 0;
                while(l >= 0 and r < n){
                        if(l == r){
                                acu += a[l]*1ll*b[r];
                                dp[l][r] = acu;
                                l--,r++;
                                continue;
                        }
                        acu += a[l]*1ll*b[r] + a[r]*1ll*b[l];
                        dp[l][r] = acu;
                        l--,r++;
                }
                l = i;r = i+1;
                acu = 0;
                while(l >= 0 and r < n){
                        if(l == r){
                                acu += a[l]*1ll*b[r];
                                dp[l][r] = acu;
                                l--,r++;
                                continue;
                        }
                        acu += a[l]*1ll*b[r] + a[r]*1ll*b[l];
                        dp[l][r] = acu;
                        l--,r++;
                }
        }
        vector<ll> ps(n+1,0);
        f(i,1,n+1)ps[i] = ps[i-1] + a[i-1]*1ll*b[i-1];
        ll ans = 0;
        ll tot = ps[n];
        f(i,0,n)f(j,i,n){
                ans = max(ans,tot - ps[j+1] + ps[i] + dp[i][j]);
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



