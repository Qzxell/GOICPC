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
    int n,k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0 ; i < n ; i++){
        cin >> v[i]; 
    }
    int cur = 0;
    int ans  = 0;
    for (int i = 0 ; i < n ; i++){
        if (v[i] >= k) {
            cur += v[i]; 
        }else if (v[i] == 0 and cur > 0) {
            cur--;
            ans ++;
        }
    }
    cout <<ans << ln; 
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
