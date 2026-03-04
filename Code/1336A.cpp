#include<bits/stdc++.h>

using namespace std;

using ll = long long ;

int n,u,v,k;
const int N =2e5 + 5;
vector<int> G[N];
vector<int> val(N,0);
vector<int> sz(N,0);
vector<int> dis(N,0);

int co = 0;
int dfs(int nod,int p){
        int ret = 1;
        for(auto x : G[nod])if(x != p){
                dis[x] = dis[nod] + 1;
                ret += dfs(x,nod);
        }
        return sz[nod] = ret;
}

void so(){
        cin >> n >> k;
        for(int i = 0 ; i < n-1 ; i++){
                cin >> u >> v;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        dis[1] = 0;
        dfs(1,-1);
        for(int i = 1 ; i <= n;i++){
                val[i] = dis[i] - sz[i] +1;
        }
        sort(val.begin()+1,val.begin()+n+1);
        reverse(val.begin()+1,val.begin()+n+1);
        ll ans = 0;
        for(int i = 1 ; i <= k;i++)ans+= val[i];
        cout << ans << '\n';

}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        so();
        return 0;
}
