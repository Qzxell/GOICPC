#include<bits/stdc++.h>

using namespace std;

#define ii pair<int,int>

const int N = 100;
vector<ii> G[N];
int color[N];
int dis[N];

unsigned long long ans = 1;

void dfs(int u,int pat = -1){
        color[u] = 1;
        for(auto [x,id] : G[u])if(x != pat){
                if(!color[x]){
                        dis[x] = dis[u] + 1;
                        dfs(x,u);
                        continue;
                }
                if(color[x] == 1){
                        int lon = dis[u] - dis[x] + 1;
                        ans *= lon;
                }
        }
        color[u] = 2;
}

void so(int test){
        int n,m,u,v;
        cin >> n >> m;
        ans = 1;
        for(int i = 0 ; i <= n ;i++){
                G[i].clear();
                dis[i] = 1;
                color[i] = 0;
        }
        for(int i = 0 ; i < m ;i++){
                cin >> u >> v;
                G[u].emplace_back(v,i);
                G[v].emplace_back(u,i);
        }
        dfs(1);
        cout << "Case " << test << ": " <<ans << '\n';
}

int main(){
        int tt;
        cin >> tt;
        int test = 1;
        while(tt--)so(test++);
        return 0;
}
