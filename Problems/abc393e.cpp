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

const int N = 1e6 + 5;

void so(int test){
        int n,k;
        cin >> n >> k;
        vi v(n);
        vi cnt(N,0);
        vi mul(N,0);
        f(i,0,n){
                cin >> v[i];
                cnt[v[i]]++;
        }
        f(i,1,N){
                int acu = 0;
                for(int j = i ; j < N; j += i){
                        acu += cnt[j];
                }
                mul[i] = acu;
        }
        vi dp(N,1);
        f(i,0,N) if(mul[i] >= k){
                for(int j = i ; j < N ; j+= i){
                        dp[j] = max<ll>(i,dp[j]);
                }
        }
        for(auto x : v){
                cout << dp[x] << ln;
        }
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
