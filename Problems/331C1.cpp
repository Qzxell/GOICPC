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

map<ll,int> dp;

ll rec(ll n){
        if(dp.count(n))return dp[n] ;
        if(n == 0)return 0;
        string s = to_string(n);
        int le = sz(s);
        ll ret = 1e17;
        f(i,0,le)if(s[i] != '0'){
                ret = min(ret,rec(n - (s[i] - '0')) + 1);
        }
        return dp[n] = ret;

}

void so(int test){
        ll n;
        cin >> n;
        ll ans = rec(n);
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
