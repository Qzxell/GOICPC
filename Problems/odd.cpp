#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second


void so(){
    vector<ll> num;
    for(ll i = 1; i < 32 ; i++){
        ll x = (1ll<<i);
        if((x-1)%3 == 0 and ((x-1)/3 ) % 2==1)num.pb(x);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    while (tt--){
        so();
    }
    return 0;
}
