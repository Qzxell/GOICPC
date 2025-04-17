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
        int n,m,d;
        cin >> n >> m;
        int inf = 1e9;
        vi dp(n+1,inf);// dp[value] := min cant
        dp[0] = 0;
        f(x,0,m){
                cin >> d;
                f(i,0,n+1)if(dp[i] != inf and i + d <= n){
                        dp[i+d] = min(dp[i+d], dp[i] + 1);
                }
        }
        cout << dp[n] << ln;

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
