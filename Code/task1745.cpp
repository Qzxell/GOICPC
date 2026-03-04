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
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

int n;
const int N = 102;
int v[N];
const int k = 1e5 + 3;
bool dp[N][k];

void so(int test){
    cin >> n;
    //memset(dp, 0 , sizeof(dp));

    for(int i = 1; i <= n ; i++) cin >> v[i];

    for(int i = 0; i <= n ; i++){
        for(int j = 0 ; j < k ; j++){
            if (j == 0) {
                dp[i][j] = 1;
            } 
            dp[i+1][j] |= dp[i][j];
            if(j + v[i+1] < k) dp[i+1][j+v[i+1]] |= dp[i][j];
        }
    }
    vi ans;
    for(int i = 1; i < k ; i++){
        for(int j = 1 ; j <= n ; j++){
            if (dp[j][i]) {
                ans.pb(i) ;
                break;
            }
        }
    }
    cout << sz(ans) << ln;
    for(int i : ans) cout << i << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
