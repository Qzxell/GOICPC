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
        int n,q;
        cin >> n >> q;
        vector<vi> T(n);vi dis(n,0);
        const int N = __lg(n) + 2;
        vector<vi> dp(n,vi(N,0));
        forn(i,n-1){
                int a,b;
                cin >> a >> b;
                a--;b--;
                T[a].push_back(b);
                T[b].push_back(a);
        }
        auto dfs = [&](auto && self, int nod, int pat)-> void{
                for(auto x : T[nod])if(x != pat){
                        dp[x][0] = nod;
                        dis[x] = dis[nod] + 1;
                        self(self,x,nod);
                }
        };
        dfs(dfs,0,0);
        forsn(i,1,N){
                forn(j,n){
                        dp[j][i] = dp[dp[j][i-1]][i-1];
                }
        }
        auto lca = [&](int nd_a,int nd_b)->int{
                if(dis[nd_a] < dis[nd_b])swap(nd_a,nd_b);
                dforn(i,N)if(dis[nd_a] - (1<<i) >= dis[nd_b]){
                        nd_a = dp[nd_a][i];
                }
                if(nd_a == nd_b)return nd_a;
                dforn(i,N)if(dp[nd_a][i] != dp[nd_b][i]){
                        nd_a = dp[nd_a][i];
                        nd_b = dp[nd_b][i];
                }
                return dp[nd_a][0];
        };
        forn(i,q){
                int a,b;
                cin >> a >> b;
                a--;b--;
                int uwu = lca(a,b);
                if(uwu == a or uwu == b)cout << abs(dis[a] - dis[b]) << '\n';
                else cout << dis[a] + dis[b] - 2*dis[uwu] << '\n';
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
