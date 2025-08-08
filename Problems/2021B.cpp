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
        int N = 2e7 + 5;
        vi dp(N);// meses minimos por anos
        int n,a;
        cin >> a >> n;
        int sq = sqrt(N);
        f(i,1,N){
                dp[i] = i;
        }
        f(i,1,sq+1){
                int cu = i*i;
                for(int j = cu; j < N; j += cu){
                        dp[j] = min(j/cu,dp[j]);
                }
        }
        ll ans =0 ;
        f(i,a,a+n){
                ans += dp[i];
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
