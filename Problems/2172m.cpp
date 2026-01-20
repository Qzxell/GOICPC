#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        int n,m,k;
        cin >> n >> m >> k;
        vector<vector<int>> G(n);
        vector<int> t(n),dis(n,-1),dp(k+1,0);
        forn(i,n)cin >> t[i];
        forn(i,m){
                int u,v;
                cin >> u >> v;
                u--;v--;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        queue<int> qu;
        qu.push(0);
        dis[0] = 0;
        while(!qu.empty()){
                int fr = qu.front();qu.pop();
                for(auto x : G[fr])if(dis[x] == -1){
                        dis[x] = dis[fr] + 1;
                        dp[t[x]] = max(dp[t[x]],dis[x]);
                        qu.push(x);
                }
        }
        forsn(i,1,k+1){
                cout << dp[i] << ' ';
        }
        cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


