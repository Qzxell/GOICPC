#include<bits/stdc++.h>

using namespace std;

const int N = 1005;
vector<vector<int>> G(N);
int p[N];
int level[N];
int dis[N];
int deg[N];

void so(){
        for(int i = 0 ; i < N; i++){
                dis[i] = 0;
                level[i] = 0;
                p[i] = 0;
                deg[i] = 0;
                G[i].clear();
        }
        int n,k;
        cin >> n >> k;
        for(int i = 2; i <= n ;i++){
                cin >> p[i];
                G[p[i]].push_back(i);
                deg[i]++;
                deg[p[i]]++;
        }
        queue<int> qu;
        auto bfs = [&](int nod){
                qu.push(nod);
                dis[nod] = 1;
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        level[dis[fr]]++;
                        for(auto x : G[fr]){
                                qu.push(x);
                                dis[x] = dis[fr] + 1;
                        }
                }
        
        };
        bfs(1);
        auto fun = [&](int lon)->bool{
                vector<int> dp(n+1,0);
                dp[0] = 1;
                int tot = 0;
                for(int i = 1; i <= lon ;i++){
                        int x = level[i];
                        tot += x;
                        for(int j = n ; j >=0 ; j--)if(dp[j]){
                                if(j + x <= n)dp[j + x] = 1;
                        }
                }
                for(int i = 0 ; i <= n; i++){
                        if(i <= k and dp[i] and tot-i <= n-k)return true;
                        if(i <= n-k and dp[i] and tot-i <= k)return true;
                }
                return false;
        };
        int lo = 1, lf = n,mid;
        for(int i = 2; i <= n ;i++)if(deg[i] == 1){
                lf = min(lf,dis[i]);
        }
        while(lo < lf){
                mid = (lo+1+lf)/2;
                if(fun(mid)){
                        lo = mid;
                }else{
                        lf = mid - 1;
                }
        }
        cout << lo << '\n';
}

int main(){
        int tt = 1;
        cin >> tt;
        while(tt--)so();
        return 0;
}
