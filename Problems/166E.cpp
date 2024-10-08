#include<bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

const int mod = 1e9+7;
vector<vi> mul (vector<vi> a ,vector<vi> b ){
    vector<vi> ret(4,vector<int>(4));
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            ll x = 0; 
            for(int y = 0 ; y < 4 ; y++){
                x = ( x + a[i][y]*1ll*b[y][j] )%mod;
            }
            ret[i][j] = x;
        }
    }
    return ret;
}
vector<vi> bexpo(vector<vi> base , int exp){
    vector<vi> ret(4,vector<int>(4));
     for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if (i == j) {
                ret[i][j] = 1; 
            }else ret[i][j] = 0;
        }
    }
     while(exp > 0){
         if (exp &1) {    
             ret = mul(ret , base);
         }
         base = mul(base,base);
         exp >>= 1;
     }
     return ret;
}

void so(){
    int n ;
    cin >> n;
    vector<vi> ans(4,vector<int>(4));
     for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if (i == j) {
                ans[i][j] = 0; 
            }else ans[i][j] = 1;
        }
    }
    ans = bexpo(ans,n) ;
    cout << ans[0][0];
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

