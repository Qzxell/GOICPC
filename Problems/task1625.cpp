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
        vector<vi> T(n);
        const int N = __lg(n) + 1;
        vector<vi> dp(n,vi(N,-2));
        vi dis(n,0);
        forsn(i,1,n){
                int a;
                cin >> a;
                a--;
                T[a].push_back(i);
                dp[i][0] = a;
        }
        queue<int> qu;
        vi vis(n,0);
        auto bfs = [&](int nod){
                qu.push(nod);
               while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        for(auto x : T[fr])if(!vis[x]){
                                vis[x] = 1;
                                qu.push(x);
                                dis[x] = dis[fr] + 1;
                        }
                }
        };
        bfs(0);
        forsn(i,1,N){
                forn(j,n){
                        if(dp[j][i-1] == -2)continue;
                        dp[j][i] = dp[dp[j][i-1]][i-1];
                }
        }
        forn(i,q){
                int x,y ;
                cin >> x >> y;
                x--;y--;
                if(dis[y] > dis[x])swap(x,y);
                dforn(j,N){
                        if((dp[x][j] == -2 ? -1 : dis[dp[x][j]] )>= dis[y]){
                                x = dp[x][j];
                        }
                }
                if(x == y){
                        cout << x + 1<< '\n';
                        continue;
                }
                dforn(j,N){
                        if(dp[x][j] != dp[y][j]){
                                x = dp[x][j];
                                y = dp[y][j];
                        }
                }
                cout << dp[x][0] + 1 << '\n';
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
