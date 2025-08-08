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
        vi v(n);
        vi vis(n,0);
        vi dp(n,0);
        f(i,0,n)cin >> v[i];
        int ans = 0;
        for(int i = n -1; i >=0 ; i--){
                int in = i;
                int scor = 0;
                while(in <n ){
                        if(vis[in]){
                                scor += dp[in];
                                break;
                        }
                        vis[in] = 1;
                        scor += v[in];
                        in += v[in];
                }
                ans = max(ans,scor);
                dp[i] = scor;
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
