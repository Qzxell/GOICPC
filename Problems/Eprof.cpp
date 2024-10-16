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
    string s;
    cin >> s;
    int le = sz(s);
    for (int i = 1 ; i < le ; i++){
        if(s[i] == s[i-1] and s[i] == 'O'){
            cout << "INVALID";
            return;
        }
    }
    if(not(s[le-1] == 'O' and s[le-2] == 'E')){
        cout << "INVALID";
        return;
    }
    vector<ll> num;
    for(ll i = 3; i < 60 ; i++){
        ll x = (1ll<<i);
        if((x-1)%3 == 0 and ((x-1)/3 ) % 2==1)num.pb(x);
    }
    reverse(all(s));
    ll ansd = 1e18;
    for(ll x : num){
        ll ans = x; 
        for(int i= 0; i < le ;i ++){
            if(s[i] == 'E'){
                ans *= 2;
                continue;
            }
            if ( s[i] == 'O' and (ans-1) %3 == 0 and ((ans-1)/3)%2 == 1){
                ans = (ans -1)/3;
            }else {
                ans = 1e18;
                break;
            }
        }
        ansd = min(ans,ansd);
    }

    if(ansd != 1e18){
        cout << ansd ;
    }else {
        cout << "INVALID";
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
