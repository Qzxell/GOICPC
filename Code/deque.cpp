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

const int N = 3003;
ll a[N];
ll dp[N][N];

ll rec(int l,int r){
        if(dp[l][r] != -1) return dp[l][r];
        if(r - l + 1 < 4){
                if(l == r)return a[l];
                if(l+1 == r)return max(a[l],a[r]);
                if(l+2 == r){
                        return max(a[r] + min(a[l],a[l-1]),a[l] + min(a[r],a[r-1]));
                }
        }
        return dp[l][r] = max(min(rec(l,r-2),rec(l+1,r-1)) + a[r],
                   min(rec(l+2,r),rec(l+1,r-1)) + a[l]);

}

void so(int test){
        int n;
        cin >> n;
        ll sum = 0;
        f(i,0,n){
                cin >> a[i];
                sum += a[i];
        }
        f(i,0,n+1)f(j,0,n+1)dp[i][j] = -1;
        ll ans = rec(0,n-1);
        cout << ans - (sum-ans);
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
