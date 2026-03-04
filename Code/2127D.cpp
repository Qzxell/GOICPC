#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define ll long long


void so(){
        int n,m;
        int u,v;
        const int MOD = 1e9 + 7;
        cin >> n >> m;
        vector<vi> adj(n+1);
        vi color(n+1,-1);
        vi deg(n+1,0);
        f(i,0,m){
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
                deg[u]++;
                deg[v]++;
        }
        f(i,1,n+1){
                int not_leaf = 0;
                for(auto x : adj[i]){
                        if(deg[x] != 1)not_leaf++;
                }
                if(not_leaf > 2){
                        cout << "0\n";
                        return;
                }
        }
        queue<int> qu;
        qu.push(1);
        color[1] = 0;
        vi cont(2,0);
        while(!qu.empty()){
                int fr = qu.front();qu.pop();
                int col = color[fr];
                cont[col]++;
                for(int x : adj[fr]){
                        if(color[x] != -1){
                                if(color[x] != col^1){
                                        cout << 0 << '\n';
                                        return;
                                }
                                continue;
                        }
                        qu.push(x);
                        color[x] = col^1;
                }
        }
        bool cic = 0;
        vi cul(n+1,0);
        auto dfs = [&] (auto& self, int u, int p) -> void {
                cul[u] = 1;
                for (int v : adj[u]) {
                        if (cul[v] == 2) continue;
                        if (cul[v] == 1 && v != p) {
                                cic = 1;
                                return;
                        }
                        if (!cul[v]) self(self, v, u);
                }
                cul[u] = 2;
        };

        dfs(dfs, 1, -1);
        if(cic){
                cout << 0 << '\n';
                return;
        }

        vi fac(n+1,1);
        vi flojos(n+1,0);

        f(i,1,n+1)fac[i] = (fac[i-1]*1ll*i)%MOD;

        f(i,1,n+1){
                int &au = flojos[i];
                for(auto x : adj[i])if(deg[x] == 1)au++;
        }
        ll ans = 1;
        f(i,1,n+1){
                ans = (ans * fac[flojos[i]])%MOD;
        }
        if(cont[0] > 1 and cont[1] > 1)ans = (ans*2)%MOD;
        cout << (ans*2)%MOD << '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
