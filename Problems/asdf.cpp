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

const int N = 1e3 + 8;
ll dp[N][N];

void so(int test){
    int n;
    cin >> n;
    vector<string> v(n);
    f(i,0,n) cin >> v[i];
    const int mod = 1e9 + 7;

    f(i,0,n) f(j,0,n) dp[i][j] = 0;

    if (v[0][0] == '.') dp[0][0] = 1;

    f(i,0,n) f(j,0,n) if (v[i][j] == '.') {
        if (j+1 < n && v[i][j+1] != '*')
            dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % mod;
        if (i+1 < n && v[i+1][j] != '*')
            dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % mod;
    }

    cout << dp[n-1][n-1] << ln;
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


