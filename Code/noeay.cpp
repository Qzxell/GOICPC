#include<bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define f(i,a,b) for(int i = a ; i < b ; i++)
#define ll long long


void so(){
        int n,m,u,v;
        const int MOD = 1e9 + 7;
        cin >> n >> m;
        vector<vi> adj(n+1);
        vi deg(n+1,0);
        f(i,0,m){
                cin >> u >> v;
                adj[u].push_back(v);
                adj[v].push_back(u);
                deg[u]++;
                deg[v]++;
        }
        if(m != n-1){
                cout << 0 << '\n';
                return;
        }
        vi fac(n+1,1);
        vi flojos(n+1,0);

        f(i,1,n+1)fac[i] = (fac[i-1]*1ll*i)%MOD;

        f(i,1,n+1){
                int &au = flojos[i];
                int not_leaf = 0;
                for(auto x : adj[i]){
                        if(deg[x] == 1)au++;
                        else not_leaf++;
                }
                if(not_leaf > 2){
                        cout << "0\n";
                        return;
                }
        }
        ll ans = 1;
        queue<int> qu;
        vi niv(n+1,0);
        vi vis(n+1,0);
        int imp,pa;
        imp = pa = 0;
        auto bfs = [&](int nod){
                qu.push(nod);
                vis[nod] = 1;
                niv[nod] = 1;
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        int cur_niv = niv[fr];
                        if(cur_niv&1)imp++;
                        else pa++;
                        for(auto x : adj[fr])if(!vis[x]){
                                qu.push(x);
                                niv[x] = cur_niv + 1;
                                vis[x] = 1;
                        }
                }
        
        };
        bfs(1);
        f(i,1,n+1){
                ans = (ans * fac[flojos[i]])%MOD;
        }
        if(imp > 1 and pa > 1)ans = (ans*2)%MOD;
        cout << (ans*2)%MOD << '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
