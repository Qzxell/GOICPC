#include<bits/stdc++.h>

using namespace std;

using ii = pair<int,int> ;
using ll = long long;

const int N = 1e5 + 5;
vector<vector<int>> G(N);

int li[N][2];
ll dp[N][2];
int vis[N][2];

ll fun(int nod,int st,int pa){
        if(vis[nod][st])return dp[nod][st];
        vis[nod][st] = 1;
        ll ret = 0;
        for(auto x : G[nod])if(x != pa){
                ll v1 = fun(x,0,nod) + abs(li[nod][st] - li[x][0]);
                ll v2 = fun(x,1,nod) + abs(li[nod][st] - li[x][1]);
                ret += max(v1,v2);
        }
        return dp[nod][st] = ret;
}

void so(){
        int n,u,v;
        cin >> n;
        for(int i = 0 ; i < n;i++)
                for(int j = 0 ; j < 2 ;j++)
                        vis[i][j] = dp[i][j] = 0;
        for(int i = 0 ; i < n;i++)G[i].clear();
        for(int i = 0 ; i < n;i++)cin >> li[i][0] >> li[i][1];
        for(int i = 0 ; i < n-1;i++){
                cin >> u >> v;
                u--;v--;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        ll ans = max(fun(0,0,-1),fun(0,1,-1));
        cout << ans << '\n';
}

int main(){
        //ios::sync_with_stdio(false);
        //cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
