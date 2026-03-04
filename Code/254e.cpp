#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        int n,m;
        cin >> n >> m;
        vector<vector<int>> G(n);
        vector<int> dis(n,-1);
        forn(i,m){
                int u,v;
                cin >> u >> v;
                u--;v--;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        int q;
        cin >> q;
        forn(i,q){
                int nod,k;
                cin >> nod >> k;
                nod--;
                int ans = nod+1;
                queue<int> qu,aux;

                dis[nod] = 0;
                qu.push(nod);
                aux.push(nod);
                while(!qu.empty()){
                        int fr = qu.front();qu.pop();
                        for(auto x : G[fr])if(dis[x] ==-1){
                                if(dis[fr] + 1 <= k){
                                        ans += x + 1;
                                        dis[x] = dis[fr] + 1;
                                        aux.push(x);
                                        qu.push(x);
                                }
                        }
                }
                while(!aux.empty()){
                        int fr = aux.front();aux.pop();
                        dis[fr] = -1;
                }
                cout << ans << '\n';

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


