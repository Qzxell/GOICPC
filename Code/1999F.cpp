#include<bits/stdc++.h>
#define ln '\n'
#define ll long long
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define vll vector<ll>  
#define fi first
#define se second
using namespace std;

const int mod = 1e9 + 7;
const int ga = 2e5 + 2;
vll fac(ga , 0);

ll fp(ll b, ll exp){
    ll rsl = 1;
    b = b%mod;
    while(exp > 0){
        if (exp % 2 == 1) {
            rsl = (rsl*b)%mod; 
        }
        exp = exp >> 1;
        b = (b*b)%mod;
    }
    return rsl;
}

ll inver(ll a){
    return fp(a,mod-2);
}

int comb(int n , int k){
    if (k > n or k < 0) {
        return 0; 
    }
    ll num = fac[n];
    ll den = (fac[k]*1ll*fac[n-k])%mod;
    return (num*1ll*inver(den))%mod;
}
void so(){
    int n,k;
    cin >> n >> k;
    int fre[2];
    fre[0]  = fre[1] = 0;
    for (int i = 0; i < n; ++i) {
        int y;cin >> y;
        fre[y]++;
    }
    ll ans = 0;
    for (int i = 0; i <= k/2; ++i) {
        ans = (ans + (comb(fre[1],k-i)%mod)*1ll*(comb(fre[0],i)%mod))%mod; 
    }
    cout << ans << ln;


}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    fac[0] = 1;
    fac[1] = 1;
    for (int i = 2; i < ga; ++i) {
        fac[i] = (fac[i-1]*1ll*i)%mod; 
    }
    while(tt--){
        so();
    }
    return 0;
}

