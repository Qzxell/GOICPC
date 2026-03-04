#include<bits/stdc++.h>
#define fi first
#define ii pair<int,int>
#define se second

using namespace std;

void so(){
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    vector<pair<int,int>> fre(31,{0,0});
    for(int j = 0;j < 31;j++){
        fre[j].second = j; 
    }

    for(int i = 0 ; i < n; i++){
        cin >> v[i];
        for(int j = 0;j < 31;j++){
            if ((v[i]>>j) & 1) {
                fre[j].first++; 
            } 
        }
    }

    reverse(fre.begin(),fre.end());
    long long ans = 0;
    for(int i = 0;i < 31;i++){
        if (n - fre[i].fi <= k) {
            ans += (1ll << fre[i].se) ;
            k -= (n - fre[i].fi);
       } 
    }
    cout << ans << '\n';

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}
