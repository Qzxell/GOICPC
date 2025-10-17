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

const int N = 4e3 + 5;
vi deg(N,0);

void so(int test){
        int n,m;
        cin >> n >> m;
        set<ii> s;
        vii edg(m);
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                deg[u]++;
                deg[v]++;
                if(u > v)swap(u,v);
                s.insert({u,v});
                edg[i] = {u,v};
        }
        int ans = INT_MAX;
        f(i,0,m){
                f(j,i+1,m){
                        auto [a,b] = edg[i];
                        auto [u,v] = edg[j];
                        if(a != u and b != v and a != v and b != u)continue;
                        if(a == u){
                                if(b > v)swap(b,v);
                                ii fh = {b,v};
                                if(s.count(fh)){
                                        ans = min(ans,deg[a] + deg[b] + deg[v]-6);
                                }
                        }
                        if(a == v){
                                if(b > u)swap(b,u);
                                ii fh = {b,u};
                                if(s.count(fh)){
                                        ans = min(ans,deg[a] + deg[b] + deg[u]-6);
                                }
                        }
                        if(b == v){
                                if(a > u)swap(a,u);
                                ii fh = {a,u};
                                if(s.count(fh)){
                                        ans = min(ans,deg[b] + deg[a] + deg[u]-6);
                                }
                        }
                        if(b == u){
                                if(a > v)swap(a,v);
                                ii fh = {a,v};
                                if(s.count(fh)){
                                        ans = min(ans,deg[a] + deg[b] + deg[v]-6);
                                }
                        }
                }
        }
        if(ans == INT_MAX)ans = -1;
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



