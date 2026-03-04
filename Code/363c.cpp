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
    int n,k;
    string s ;
    cin >> n >> k >> s ;
    vi frec(27,0);
    for(int i = 0;i < n;i++){
        frec[s[i] - 'a']++; 
    }
    ll posb = 0;
    for(int i = 0;i < 27;i++){
        posb += frec[i]/2;
    }
    int res = n - 2*k;
    int fac = 1;
    for(int i = 1;i <= n - k;i++){
        fac *= i; 
    }
    int ju = 1;
    for(int i = 0;i < k/2;i++){
        ju *= posb; 
        posb--;
    }
    if (k&1) {
        ju *= res; 
    }
    ll f = 1;
    for(int i = 0;i < n;i++){
        f*= (i+1); 
    }
    for(int i = 0;i < 27;i++){
        f /= max(1,frec[i]) ;
    }
    cout << f << ' ';
    ll ans = (n - k + 1)*1ll*ju*1ll*fac;
    cout <<ans ; 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while(tt--){
        so();
    }

    return 0;
}
