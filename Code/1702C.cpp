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
    cin >> n >> k;
    vi v(n);
    for(int &x : v)cin >> x;
    map<int,pair<int,int>> ma;
    for(int i = 0 ; i < n; i++){
        if(ma.find(v[i]) == ma.end()){
            ma[v[i]].fi = i+1;
            ma[v[i]].se = i+1;
            continue;
        }
        ma[v[i]].fi = min(i+1 , ma[v[i]].fi);
        ma[v[i]].se = max(i+1 , ma[v[i]].se);
    }
    while(k--){
        int a,b;
        cin >> a >> b;
        if((ma.find(a) == ma.end()) or (ma.find(b) == ma.end())){
            cout << "NO\n";
            continue;
        }
        if(ma[a].fi <=  ma[b].se)cout << "YES\n";
        else cout << "NO\n";
    }

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
