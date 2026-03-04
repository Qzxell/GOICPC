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
        vi m(5005);
        f(i,0,n) {
                cin >> v[i];
                m[v[i]]++;
        }
        int gc = v[0];
        f(i,1,n)gc = gcd(gc,v[i]);
        if(m[gc]){
                cout << n - m[gc] << ln;
                return;
        }
        int ma = INT_MAX;
        int N = 5005;
        vi dp(N,ma);//dp[gcd] = min elementos
        dp[0] = 0;
        f(i,0,n){
                for(int j = N-1; j >=0 ; j--)if(dp[j] != ma){
                        dp[gcd(j,v[i])] = min(dp[gcd(j,v[i])],dp[j] + 1);
                }
        }
        cout << n + dp[gc] - 2 << ln;
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
