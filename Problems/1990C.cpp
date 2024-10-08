#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n;
    cin >> n;
    vi v(n);
    vector<bool> vis(n+1,0);
    ll ans = 0;
    int mad = 0;
    for(int i = 0;i < n;i++){
        cin >> v[i] ;
        ans += v[i];
        if (vis[v[i]] and v[i] > mad) {
            mad = v[i]  ;
        }
        vis[v[i]] = 1;
        v[i] = mad;
    }
    v.pb(v[n-1] + 1);
    int c = 1;
    vii pre;
    for(int i = 0;i < n;i++){
        if (v[i] == v[i+1]) {
            c++; 
        }else {
            int le = (int)pre.size();
            if (c == 1) {
                ans+= v[i] ;
            }
            if (c == 1 and le >0) {
               pre[le-1].se ++; 
               continue;
            }
            pre.pb({v[i],c});
            c = 1;
        }
    }
    reverse(pre.begin(),pre.end());
    int cur = 0;
    int crry = 0;
    for(auto x : pre){
        int seg = x.se;
        ans += x.fi*cur*seg + x.fi * (seg*1ll*(seg+1))/2 ;
        cur += seg ;
        //cout << x.fi << ' ' << x.se << ';';
    }

    cout << ans << ln;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }

    return 0;
}
