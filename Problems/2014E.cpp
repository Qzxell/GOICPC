#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(){
    int n,m,h;
    cin >> n >> m>>h;
    vector<bool> horse(n+1,false);
    for (int i = 0 ; i < h ; i++){
        int x;
        cin >> x;
        horse[x]=1;
    }
    vector<ii> gr[n+1];

    for (int i = 0 ; i < m ; i++){
        int u,v,w;
        cin >> u >> v >> w;
        gr[u].pb({v,w});
        gr[v].pb({u,w});
    }
     
    auto dij = [&](int root){
	    priority_queue<tuple<int,int, bool>, vector<tuple<int,int,bool>>, greater<tuple<int,int,bool>>> pq;

        vii dist(n+1, {0,INT_MAX});//posible error con long long
        dist[root] = {horse[root],0};
        pq.push({0,root,horse[root]});

        while(!pq.empty()) {
            auto [d,u,caba] = pq.top();
            //cout <<"distance   nodo actual     caballo?" << ln;
            //cout << d << ' ' << u << ' ' << caba << ln;
            pq.pop();

            if (dist[u].fi == 0 and caba ) {
                int x = 1; 
            }else if (d != dist[u].se) {
                continue; 
            }

            for(auto & edge : gr[u]){
                int to = edge.fi;
                int wei = edge.se;
                bool hor = caba or horse[to];
                if (caba) {
                    wei /= 2; 
                }
                if (dist[u].se + wei < dist[to].se or (dist[to].fi == 0 and caba)) {
                    dist[to] = {caba,dist[u].se + wei}; 
                    pq.push({dist[to].se, to,hor});
                }
            }
        }
        return dist;
    };
    vii maria = dij(1);
    vii robin = dij(n);
    int ans = INT_MAX;
    for (int i = 1 ; i <= n ; i++){
        int cur = max(maria[i].se,robin[i].se) ;
        ans = min(ans,cur);
    }
    cout << ans << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--){
        so();
    }
    return 0;
}
