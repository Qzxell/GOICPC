#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n,k;
    cin >> n>> k;
    vii v(n);
    vi ans(k+1,0);
    for(int i = 0;i <n;i++){
        int x ; cin >> x;
        v[i] = {x,i};
    }
    sort(v.begin(),v.end());
    int mi = 1e9 , ma = 0;
    for(int i = n - 1; i >= 0 ; i--){
        if (i == n-1) {
            mi = v[i].se;
            ma = v[i].se;
            ans[v[i].fi] = 2;
            continue;
        } 
        if (mi <= v[i].se and v[i].se <= ma) {
            ans[v[i].fi] = 2*(ma - mi+1); 
        }else ans[v[i].fi] = 2*max(abs(mi-v[i].se) + 1 , abs(ma-v[i].se) + 1);
        mi = min(mi,v[i].se);
        ma = max(ma,v[i].se);
    }
    for(int i = 1;i <= k;i++){
        cout << ans[i] << ' '; 
    }
    cout << ln;
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
