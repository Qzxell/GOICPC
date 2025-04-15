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
        int n,W;	
        cin >> n>> W;

        int inf = 1e9;
        int N = 1e5 + 3;
        vi dp(N,inf);// dp of value with min weight
        dp[0] = 0;
        f(i,0,n){
                int v,w;
                cin >> v >> w;
                for(int j = N-1 ; j >= 0 ; j--)if(j + v < N and dp[j] != inf){
                        dp[j + v] = min(dp[j + v], dp[j] + w);
                }
        }
        for(int j = N-1 ; j >= 0 ; j--)if(dp[j] != inf and dp[j] <= W){
                cout << j << ln;
                return;
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
