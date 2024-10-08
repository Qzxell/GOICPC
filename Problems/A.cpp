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
    for (int i = 0; i < n; ++i) {
        cin >> v[i] ;
    }
    sort(v.begin(),v.end());
    int ans = 1e9 + 2;
    for (int i = 0; i < n; ++i) {
        if (i + k - 1 < n) {
            ans = min(ans,v[i+k-1] - v[i]); 
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

