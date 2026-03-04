#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;
const int ga = 2e5 + 2;
vi a(ga);
map<int,int> frecb;
map<int,int> freca;

void so(){
    frecb.clear();
    freca.clear();
    int n,m,k;
    cin >> n >> m >> k;
    ll inte = 0;
    set<int> b;

    for(int i = 0;i < n;i++){
        cin >> a[i] ;
        if(i < m) freca[a[i]]++;
    }
    for(int i = 0;i < m;i++){
        int x; cin >> x;
        frecb[x]++;
        b.insert(x);
    }
    ll cur = 0;
    for(auto x : b){
        cur += min(freca[x],frecb[x]) ;
    }
    int ans =0 ;
    if (cur >= k) {
        ans ++;
    }
    for(int i = 0 ; i < n-m;i++){
        cur -= min(freca[a[i]],frecb[a[i]]) ;
        freca[a[i]]--;
        cur += min(freca[a[i]],frecb[a[i]]) ;

        int x = i + m ;
        cur -= min(freca[a[x]],frecb[a[x]]) ;
        freca[a[x]]++;
        cur += min(freca[a[x]],frecb[a[x]]) ;
        if (cur >= k) {
            ans ++;
        }
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
