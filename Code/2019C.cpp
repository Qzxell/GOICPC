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
    int n , k;
    cin >> n >> k;
    vi v(n);
    vector<ll> ps(n+1,0);
    for (int i = 0 ; i < n ; i++){
        cin >> v[i]; 
    }
    sort(all(v));
    for (int i = 0 ; i < n ; i++){
        ps[i+1] += ps[i] + v[i];
    }
    vi div;
    for (int i = 1 ; i <= (int)sqrt(n) ; i++){
        if (n%i==0) {
            div.pb(i); 
            if( i != n/i) div.pb(n/i);
        }
    }
    sort(div.rbegin(),div.rend());
    
    for (int i = 0 ; i < sz(div) ; i++){
        ll acu = 0;
        for (int j = div[i]-1 ; j < n ; j+= div[i]){
            acu += (v[j]*3 - ps[j] + ps[j-div[i]]);
        }
        if (acu <= k) {
            cout << div[i] << ln;
            return;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--){
        so();
    }
    return 0;
}
