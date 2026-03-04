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
#define point complex<long long>

void so(int test){
        int n,m;
        cin >> n >> m;
        vector<string> ma(n);
        f(i,0,n) cin >> ma[i];
        int inf = 1e9;
        vi dp(1<<m,inf);
        dp[0] = 0;
        auto bit = [&](int nu,int pos)->bool{
                return ((nu>>pos)&1);
        };
        auto valid = [&] (int mask, int pos)->bool{
                f(i,0,m){
                        if(ma[pos][i] == '.' and !bit(mask,i))return false;
                }
                return true;
        };
        auto cont = [&] (int mask, int pos)->int{
                int co = 0;
                f(i,0,m){
                        if(ma[pos][i] == '#' and bit(mask,i))
                                co++;
                }
                return co;
        };
        auto sub_sq = [&](int mask1, int mask2)->bool{
                f(i,0,m-1){
                        int cur = bit(mask1,i) + bit(mask2,i) + bit(mask1,i+1) + bit(mask2,i+1);
                        if(cur == 0) return false;
                }
                return true;
        };

        f(i,0,n){
                vi n_dp(1<<m,inf);
                f(prev_mask,0,(1<<m))if(dp[prev_mask] != inf){
                        f(mask,0,(1<<m)){
                                if(!valid(mask,i))continue;
                                if(i != 0 and !sub_sq(prev_mask,mask))continue;
                                int trans = cont(mask,i);
                                n_dp[mask] = min(dp[prev_mask] + trans,n_dp[mask]);
                        }
                }
                swap(n_dp,dp);
        }
        int ans = inf;
        f(i,0,1<<m)ans = min(ans,dp[i]);
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



