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

const int N =1e3 + 1;

int dp[N][N];

void so(int test){
    string a,b,c;
    cin >> a >> b >> c;
    int ma = 1e9;
    f(i,0,sz(a)+1)
        f(j,0,sz(b)+1)
            dp[i][j] = ma;

    dp[0][0] = 0;
    for(int i = 0 ; i <= sz(a) ;i++){
        for(int j = 0 ; j <= sz(b) ;j++){
            if(j+1 <= sz(b)){
                int wasa1 = (c[i+j] != b[j] ? 1 : 0);
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + wasa1);
            }
            if(i+1 <= sz(a)){
                int wasa2 = (c[i+j] == a[i] ? 0 : 1);
                dp[i+1][j] = min(dp[i+1][j], dp[i][j] + wasa2);
            }
        }
    }
    cout << dp[sz(a)][sz(b)] << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
