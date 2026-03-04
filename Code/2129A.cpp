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

const int N = 6e3 + 5;
vii adj[N];
vi color(N,0);
vi ign(N,0);
int co = 0;

void dfs(int nod,int pat){
        color[nod] = 1;
        if(adj[nod].empty())return;

        for(auto [to,i]:adj[nod])if(to != pat){
                if(color[to] == 0){
                        dfs(to,nod);
                        continue;
                }
                ign[i] = 1;//cycle -> ignored
                co++;
        }

        color[nod] = 2;
}

void so(int test){
        int n;
        cin >> n;
        f(i,0,n){
                int u,v;
                cin >> u >> v;
                adj[u].pb({v,i});
                adj[v].pb({u,i});
        }
        co = 0;
        
        f(i,0,2*n + 1)if(color[i] == 0)dfs(i,-1);

        cout << n-co << ln;
        f(i,0,n){
                if(!ign[i])cout << i +1 << ' ';
        }
        cout << ln;
        f(i,0,2*n + 1){
                color[i] = 0;
                ign[i] = 0;
                adj[i].clear();
                co = 0;
        }
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



