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
#define point complex<long long>
#define re real()
#define im imag()

const int N = 100;
vii G[N];
vii edg(N);
vi color(N,0);

void dfs(int nod,int pat){
        color[nod] = 1;
        for(auto [x,id] : G[nod])if(x != pat){
                if(color[x] != 2) edg[id] = {nod,x};
                if(!color[x]){
                        dfs(x,nod);
                }
        }
        color[nod] = 2;
}

void so(int test){
        int n,m;
        cin >> n >> m;
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                G[u].pb({v,i});
                G[v].pb({u,i});
                edg[i] = {u,v};
        }
        f(i,1,n+1)sort(all(G[i]));
        dfs(1,-1);
        f(i,0,m){
                auto [a,b] = edg[i];
                cout << a << ' ' << b << ln;
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



