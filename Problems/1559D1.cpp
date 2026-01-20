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
        int n,m1,m2;
        cin >> n >> m1 >> m2;
        vi vis(n,0);
        vector<vi> G(n);
        forn(i,m1+m2){
                int u,v;
                cin >> u >> v;
                u--;v--;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        queue<int> qu;
        vi ans;
        auto bfs = [&](int nod){
                ans.push_back(nod);
                qu.push(nod);
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        for(auto x : G[fr])if(!vis[x]){
                                vis[x] = 1;
                                qu.push(x);
                        }
                }
        };
        forn(i,n)if(!vis[i])bfs(i);
        cout << sz(ans) - 1 <<'\n';
        forn(i,sz(ans)-1){
                cout << ans.back() + 1 << ' ' << ans[i] +1 << '\n';
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


