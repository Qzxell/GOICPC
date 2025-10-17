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
        int n,m;
        cin >> n >> m;
        vector<ll> dp(m + 10,0);
        dp[0] = 1;
        f(_,0,n){
                vector<ll> dp_(m + 10,0);
                for(int su = m;su >= (_?1:0) ; su--){
                        for(int dig = (_ == 0? 1 : 0);dig <= 9;dig++)if(su + dig <= m){
                                dp_[su+dig] += dp[su];
                        }
                }
                swap(dp_,dp);
        }
        cout << dp[m] << ln;
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



