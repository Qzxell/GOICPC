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
        int lon = (1<<10);
        vector<ll> dp(lon,0);
        int mod = 1e9 + 7;
        auto lcm = [&](ll nu1,ll nu2)->ll{
                return (nu1*nu2)/gcd(nu1,nu2);
        };
        auto fu = [&](int mask) ->int{
                int num = 1;
                f(i,1,10)if((mask>>i)&1) num = lcm(num,i);
                return num;
        };
        auto fu_ = [&](ll num)->int{
                int mask = 0;
                f(i,1,10)if(num%i == 0) mask |= (1<<i);
                return mask;
        };
        
        dp[1] = 1;
        f(i,0,n){
                int x; cin >> x;
                int mas = fu_(x);
                for(int j = lon-1; j>=1 ; j--){
                        int nu1 = fu(j);
                        int nu2 = fu(mas);
                        int mask = fu_(nu1*1ll*nu2);
                        dp[mask] = (dp[mask] + dp[j])%mod;
                }
        }
        cout << dp[(1<<10)-2] ;
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



