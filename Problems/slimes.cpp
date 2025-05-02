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

const int N = 405;
vi v(N);
vector<ll> ps(N+2,0);
ll dp[N][N];

ll rec(int l ,int r){
        if ( l == r) return 0;
        if(dp[l][r]  != -1)return dp[l][r];
        ll ret = 1e15;
        for(int i = l; i <= r-1; i++){
                ret = min(ret, rec(l,i) + rec(i+1,r));
        }

        return dp[l][r] =  ps[r+1] - ps[l] + ret;
}

void so(int test){
        int n;
        cin >> n;
        f(i,0,n)cin >> v[i];

        f(i,0,n+3) f(j,0,n+3) dp[i][j] = -1;

        f(i,1,n+1)ps[i] = ps[i-1] + v[i-1];
        ll ans = rec(0,n-1);
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
