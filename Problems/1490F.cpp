#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vll vector<ll>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

void so(){
    int n;
    cin >> n;
    map<int,int> ma;
    vi fr;
    for(int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        ma[x] ++;
    }
    for(auto x : ma){
        fr.pb(x.se);
    }
    sort(fr.begin(),fr.end());
    ll ans = 1e18;
    int le = fr.size();
    vll ps(le+1,0);
    for(int i = 1 ; i < le + 1 ;i++){
        ps[i] = ps[i-1] + fr[i-1];
    }
    for(int i = 0 ; i < le ; i++){
        ll k = ps[le] - ps[i+1] - fr[i]*1ll*(le - i - 1); 
        k += ps[i];
        ans = min(ans,k);
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

