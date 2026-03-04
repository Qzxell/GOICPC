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
    int mg,mh;
    cin >> mg;
    bool grg[n+1][n+1];
    bool grh[n+1][n+1];
    int A[n+1][n+1];
    for (int i = 0; i < n+1; ++i) {
        for (int j = 0; j < n+1; ++j) {
            grg[i][j] = 0;
            grh[i][j] = 0;
            A[i][j]=0;
        }
    }

    for (int i = 0; i < mg; ++i) {
        int u,v;
        cin >> u >> v;
        grg[u][v] = 1;
        grg[v][u] = 1;
    }
    cin >> mh;
    for (int i = 0; i < mh; ++i) {
        int u,v;
        cin >> u >> v;
        grh[u][v] = 1;
        grh[v][u] = 1;
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = i+1 ; j <= n ; j++){
            cin >> A[i][j];
        }
    }

    vi arr;
    for (int i = 0; i < n; ++i) {
        arr.pb(i+1); 
    }

    ll ans = 1e18;
    do {
        ll sum = 0;
        for(int i = 1 ; i <= n ; i++) {
            for(int j = i+1 ; j <= n ; j++){
                if ( grg[arr[i-1]][arr[j-1]] != grh[i][j]) {
                    sum += A[i][j]; 
                }
            }
        }
        ans = min(ans,sum);
    } while (next_permutation(all(arr)));
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

