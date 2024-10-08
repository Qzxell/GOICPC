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
    for (int i = 0 ; i < n ; i++){
        cin >> v[i]; 
    }
    auto f = [&](int p){
        int res = 0;
        for (int i = 0 ; i < n ; i++){
            res += (v[i]-p)*(v[i]-p) ;
        }
        return res;
    };
    int ans = 1e9;
    for (int i = 1 ; i <= 100 ; i++){
        ans = min(ans,f(i)); 
    }
    cout << ans ;
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
