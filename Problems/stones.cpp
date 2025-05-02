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

int a[101];
int n,k;
const int K = 1e5 + 1;
vector<vi> dp(K,vi(2,0));
vector<vi> vis(K,vi(2,0));

bool rec(int stones, int who){
        if(vis[stones][who])return dp[stones][who];
        vis[stones][who] = 1;
        bool ret = false;
        f(i,0,n)if(stones >= a[i]){
                ret |= not(rec(stones - a[i],who^1));
        }
        return dp[stones][who] = ret;
}

void so(int test){
        cin >> n >> k;
        f(i,0,n)cin >> a[i];
        int ans = rec(k,0);
        cout << (ans ? "First" : "Second") << ln;
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
