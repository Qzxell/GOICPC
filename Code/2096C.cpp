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
        vector<vi> ma(n+1,vi(n+1,-1));
        vi a(n+1),b(n+1);
        f(i,1,n+1)f(j,1,n+1)cin >> ma[i][j];
        f(i,1,n+1)cin >> a[i];
        f(i,1,n+1)cin >> b[i];

        ll inf = (1ll<<60);
        vector<vector<ll>> dp(n+1,vector<ll>(2,inf));

        auto res = [&]() -> ll{
                ll ret = inf;
                f(i,1,n+1){
                        f(j,0,2) f(k,0,2){
                                bool ok = 1;
                                f(l,1,n+1){
                                        if(ma[i-1][l] + j == ma[i][l] + k){
                                                ok = 0;
                                                break;
                                        }
                                }
                                if(!ok)continue;
                                dp[i][k] = min<ll>(dp[i][k], dp[i-1][j] + (k?a[i]:0));
                        }
                }
                ret = min({ret,dp[n][0],dp[n][1]});
                if(ret == inf){
                        return -1;
                }
                return ret;
        };
        auto rot = [&](){
                f(i,1,n+1){
                        f(j,1,i+1){
                                swap(ma[i][j],ma[j][i]);
                        }
                }
                swap(a,b);
        };
        auto clean = [&](){
                f(i,1,n+1){
                        dp[i][0] = inf;
                        dp[i][1] = inf;
                }
                dp[0][1] = 0;
                dp[0][0] = 0;
        };
        clean();
        ll ans = 0;
        ll r1 = res();
        if(r1 == -1){
                cout << -1 << ln;
                return;
        }
        ans += r1;
        rot();
        clean();
        clean();
        ll r2 = res();
        if(r2 == -1){
                cout << -1 << ln;
                return;
        }
        ans += r2;
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

