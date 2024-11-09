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

void so(int test){
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; ++i) cin >> v[i];
    bool dp[n + 1][k + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int s1 = 0; s1 <= k; ++s1) {
            for (int s2 = 0; s2 <= k; ++s2) {
                dp[i][s1][s2] = dp[i - 1][s1][s2];
                if (s1 >= v[i]) dp[i][s1][s2] |= dp[i - 1][s1 - v[i]][s2];
                if (s2 >= v[i]) dp[i][s1][s2] |= dp[i - 1][s1][s2 - v[i]];
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= k; ++i) {
        if (dp[n][i][k - i]) ans.emplace_back(i);
    }
    cout << ans.size() << "\n";
    for (int e : ans) cout << e << " ";
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
