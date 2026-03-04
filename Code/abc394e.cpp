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

const int N = 502;
vector<vector<vi>> dp(N,vector<vi>(N,vi(N,505)));
vector<vector<vi>> vis(N,vector<vi>(N,vi(N,0)));
int n,k;
string s;
int solve(int l,int r,int lon){
        if(l < 0 or r >= n)return 0;
        if(vis[l][r][lon])return dp[l][r][lon];
        int ret = 0;
        ret = min(ret,solve(l-1,r+1,lon));
        ret = min(ret,solve(l,r+1,lon));
        ret = min(ret,solve(l-1,r,lon));
        ret = min(ret,solve(l-1,r+1,lon + (l == r ? 1 : 2)) + (s[l] != s[r]));
        vis[l][r][lon] = 1;
        return dp[l][r][lon] = ret;
}

void so(int test){
        cin >> n >> k;
        cin >> s;
        int ans = n;
        f(i,0,n){
                f(j,0,n){
                }
        }
        f(i,0,n+1){
                f(j,0,n){
                        f(l,0,n){
                                cout << dp[j][l][i] << ' ';
                        }
                        cout << ln;
                }
                cout << ln;
        }
        f(i,k,n+1){
                f(j,0,n) f(l,j,n){
                        ans = min(ans,dp[j][l][i]);
                }
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
