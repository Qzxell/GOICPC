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
    ll a,s,l,r; 
    cin >> a >> s >>l >> r;
    ll sq = sqrt(s);
    vector<ll> div;
    for(int i = 2; i <= sq;i++){
        if(s % i == 0){
            if(s == i*i) div.pb(i);
            else{
                div.pb(i);
                div.pb(s/i);
            }
        }
    }
    div.pb(s);
    sort(all(div));
    for( ll n : div){
        if((n-1)&1)continue;
        ll x = s/n;
        ll alp = (n-1)/2;
        ll max = a % r
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
