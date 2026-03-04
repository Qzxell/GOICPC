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
    int n;
    cin >> n;
    vi v(n);
    ll su = 0;
    for (int i = 0 ; i < n ; i++){
        cin >> v[i]; 
        su += v[i];
    }
    sort(all(v));

    ll lo = 0 , lf ,mid; 
    lf = 1e16;
    auto fu = [&](ll add){
        int cont =0 ;
        for (int i = 0 ; i < n-1 ; i++){
            if (v[i]*2*1ll*n < su + add ) {
                cont++; 
            }else break;
        }
        return cont;
    };
    while(lo < lf ){
        mid = (lo+lf)/2;
        if (fu(mid) > n/2) {
            lf = mid; 
        }else lo = mid + 1;
    }
    if (fu(lo) > n/2) {
        cout << lo << ln; 
    }else cout << -1 << ln;

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
