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
        int h,w;
        cin >> h >> w;
        string ma[h];
        ll dp[h][w];
        f(i,0,h)cin >> ma[i];
        f(i,0,h)f(j,0,w)dp[i][j] = -1;
        dp[0][0] = 1;
        int mod = 1e9 + 7;

        f(i,0,h){
                f(j,0,w)if(ma[i][j] != '#' and dp[i][j] != -1){
                        int n_x,n_y;
                        n_x = i + 1;
                        n_y = j + 1;
                        if(n_x < h and ma[n_x][j] != '#'){
                                if(dp[n_x][j] == -1)dp[n_x][j] = 0;
                                dp[n_x][j] += dp[i][j];
                                dp[n_x][j] %= mod;
                        }
                        if(n_y < w and ma[i][n_y] != '#'){
                                if(dp[i][n_y] == -1)dp[i][n_y] = 0;
                                dp[i][n_y] += dp[i][j];
                                dp[i][n_y] %= mod;
                        }
                }
        }
        cout << (dp[h-1][w-1] >= 0? dp[h-1][w-1] : 0 );
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
