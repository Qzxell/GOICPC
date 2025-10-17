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

int n;
const int N = 2e5 + 5;
vi v(N);
vi vis(N,0);
vi dp(N,0);
map<int,vi> m;
int rec(int pos){
        if(pos >= n) return 0;
        if(vis[pos])return dp[pos];
        vis[pos] = 1;
        int num = v[pos];
        int ret = rec(pos+1);
        int lon = sz(m[num]);
        int ind = lower_bound(all(m[num]),pos) - m[num].begin();
        if(ind + num - 1 < lon){
                ret = max(ret,rec(m[num][ind+num-1]+1) + num);
        }
        return dp[pos] = ret;
}

void so(int test){
        cin >> n;
        f(i,0,n)vis[i] = 0;
        f(i,0,n)dp[i] = 0;
        m.clear();
        f(i,0,n){
                cin >> v[i];
                m[v[i]].pb(i);
        }
        int ans = rec(0);
        cout << ans  << ln;
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


