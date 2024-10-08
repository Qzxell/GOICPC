#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define vb vector<bool>  
#define fi first
#define se second
using namespace std;

void so(){
    int n;
    cin >> n;
    vb aspa(n+1,0) ;
    vb aspb(n+1,0) ;
    string a,b;
    cin >> a >> b;
    string tempa = a;
    a = "0" + a;
    b = "0" + b;
    for(int i = 1 ; i <= n ; i++){
        bool m,n;
        m = (a[i] == '1' ? 1 : 0);
        n = (a[i-1] == '1' ? 1 : 0);
        aspa[i-1] = (m^n) ;
        m = (b[i] == '1' ? 1 : 0);
        n = (b[i-1] == '1' ? 1 : 0);
        aspb[i-1] = (m^n) ;
    }
    auto fa = [&](int x){
        aspa[x] = (aspa[x] ^ 1);
        aspa[x+1] = (aspa[x+1] ^ 1);
        aspb[0] = (aspb[0] ^1);
        aspb[x] = (aspb[x] ^1);
        aspb[x+1] = (aspb[x+1]^ 1);
    };
    for(int i = 1 ; i <= n ; i++){
        if (a[i] == '0') {
            fa(i-1);
        }    
    }
    for(int i = 1 ; i < n ; i++){
        aspb[i] = (aspb[i] ^ aspb[i-1]);
    }
    for(int i = 1 ; i < n ; i++){
        if (aspb[i] != aspb[i-1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    vii ans;
    for(int i = 0 ; i < n ; i++){
        if (tempa[i] == '0') {
            ans.pb({i+1, i+1}) ;
        } 
    }
    if (aspb[0] == 0) {
        ans.pb({1,n}); 
    }else{
        ans.pb({1,1});
        ans.pb({2,n});
    }
    cout << ans.size() << ln;
    for(auto x : ans){
        cout << x.fi << ' ' << x.se << ln; 
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
