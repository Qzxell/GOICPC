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
        vi cnt(n+1,0);
        vi pos[n+1];
        vi v(n);
        f(i,0,n){
                cin >> v[i];
                cnt[v[i]]++;
                pos[v[i]].pb(i);
        }
        if(n % k){
                cout << 0 << ln;
                return;
        }
        f(i,1,n+1){
                if(cnt[i]%k){
                        cout << 0 << ln;
                        return;
                }
        }
        vi dp(n+1,0);
        f(i,0,n){
                int x = v[i];
                int ele = cnt[x]/k;
                int ind = lower_bound(all(pos[x]),i) - pos[x].begin();
                int max_pos;
                max_pos = (ind+ele < sz(pos[x]) ? pos[x][ind + ele] - 1 : n-1);
                dp[i] = max_pos;
        }
        for(int i = n -1 ; i > 0;i--){
                if(dp[i-1] >= i){
                        dp[i-1] = min(dp[i-1],dp[i]);
                }
        }
        ll ans = 0;
        f(i,0,n){
                ans += (dp[i] - i + 1);
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



