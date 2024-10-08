#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define eb emplace_back
#define ii pair<int,ll>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(){
    int n,m;
    cin >> n >> m;
    vii gr[n+1];
    for (int i = 0 ; i < m ; i++){
        int u,v,l; 
        cin >> u >> v >> l;
        gr[u].eb(v,l);
        gr[v].eb(u,l);
    }
    priority_queue<ii, vector<ii>, greater<ii>> pq;  
    ll maxx = 1e16;
    vector<ll> dist (n+1,maxx);
    pq.push({0,1});
    dist[1] = 0;
    while(!pq.empty()){
        auto [d,u] = pq.top();
        pq.pop();
        if (dist[u] < d ) {
            continue; 
        }
        for(auto [to,len] : gr[u]){
            if (0ll + dist[u] + len < dist[to]) {
                dist[to] = dist[u] + (1ll)*len; 
                pq.push({dist[to],to});
            }
        }
    }
    ll ans = dist[n];
    if (ans == maxx) {
        cout << -1 ;
        return;
    }
    int cur = n;
    vi uwu;
    uwu.eb(n);
    while(ans ){
        for(auto [to,len] : gr[cur]) {
            if (dist[to] == ans -len) {
                cur = to; 
                uwu.eb(to);
                ans -= len;
                break;
            }
        }
    }
    reverse(all(uwu));
    for(auto x:uwu)cout << x << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
