#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

void so(int test){
        int n,m;
        cin >> n >> m;
        const int N = __lg(n) +2;
        vector<vi> T(n+1),dp(n+1,vi(N,0));
        vi dis(n+1,0);
        forn(i,n-1){
                int a,b;
                cin >> a >> b;
                T[a].push_back(b);
                T[b].push_back(a);
        }
        auto dfs = [&](auto && self, int nod, int pat)-> void{
                for(auto x : T[nod])if(x != pat){
                        dis[x] = dis[nod] + 1;
                        dp[x][0] = nod;
                        self(self,x,nod);
                }
        };
        dfs(dfs,1,0);
        forsn(j,1,N)
                forsn(i,1,n+1)
                        dp[i][j] = dp[dp[i][j-1]][j-1];

        vl val(n+1,0);
        auto lca = [&](int a, int b)->int{
                if(dis[a] < dis[b])
                        swap(a,b);
                dforn(i,N)if(dis[a] - (1<<i) >= dis[b]){
                        a = dp[a][i];
                }
                if(a == b)return a;
                dforn(i,N)if(dp[a][i] != dp[b][i]){
                        a = dp[a][i];
                        b = dp[b][i];
                }
                return dp[a][0];
        };
        forn(i,m){
                int u,v;
                cin >> u >> v;
                int pap = lca(u,v);
                val[u]++;
                val[v]++;
                val[pap]--;
                val[dp[pap][0]]--;
        }
        auto dfs2 = [&](auto && self, int nod, int pat)-> ll{
                for(auto x : T[nod])if(x != pat){
                        val[nod] += self(self,x,nod);
                }
                return val[nod];
        };
        dfs2(dfs2,1,0);
        forsn(i,1,n+1)cout << val[i] << ' ';
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
