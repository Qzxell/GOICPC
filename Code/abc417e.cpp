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

const int N = 1005;
vi G[N];
int x,y;
vector<bool> reach(N,0);
vector<bool> used(N,0);
bool cyc = 0;

vi ans;

void clen(){
        f(i,0,N)G[i].clear();
        f(i,0,N)reach[i] = 0;
        f(i,0,N)used[i] = 0;
        cyc = 0;
}

void dfs(int nod){
        reach[nod] = 1;
        for (auto to :G[nod])if(!used[to] and !reach[to]) {
                dfs(to);
        }
        return;
}

void so(int test){
        int n,m;
        cin >> n >> m;
        cin >> x >> y;
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                G[u].pb(v);
                G[v].pb(u);
        }
        vi ans;
        while(x != y){
                ans.pb(x);
                used[x] = 1;
                f(i,1,n+1)reach[i] = 0;
                dfs(y);
                int mi = n+1;
                for (auto to :G[x]) {
                        if(reach[to])mi = min(mi,to);
                }
                x = mi;
                assert(mi != n+1);
        }
        ans.pb(y);
        for (auto nod :ans) {
                cout << nod << ' ';
        }
        cout << ln;
        clen();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
        cin >> tt;
	while (tt--){
		so(test++);
	}
	return 0;
}

