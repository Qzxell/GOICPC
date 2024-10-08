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
    int ans1 = 0;
    for (int i = 0 ; i < n ; i++){
        cin >> v[i]; 
        ans1 = max(ans1,v[i]);
    }
    if (n&1) {
        int ans = 0;
        int cur =0;
        int ma = 0;
        for (int i = 0 ; i < n ; i+= 2){
            cur++;
            ma = max(ma,v[i]);
        }
        cur += ma;
        ans = max(cur , ans);
        cur = 0, ma = 0;
        for (int i = 1 ; i < n ; i+= 2){
            cur++;
            ma = max(ma,v[i]);
        }
        cur += ma;
        ans = max(cur , ans);
        cout << ans << ln;
    }else{
        cout << n/2 + ans1 << ln;
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
