#include "bits/stdc++.h"
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif

using ll = long long;
using ld = long double;
#define sz(v) ((int)((v).size()))
const int mod = 1e9 + 7;
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2 << '\n';
        return 0;
    }
    int dp[n + 1][3][3];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i != j && j != 1) dp[2][i][j] = 1;
        }
    }
    for (int i = 3; i <= n; i++) {
        for (int a = 0; a <= 2; a++) {
            for (int b = 0; b <= 2; b++) {
                for (int c = 0; c <= 2; c++) {
                    if (a != b && b != c) {
                        if (b == 1) {
                            if ((a == 0 && c == 2) || (c == 0 && a == 2)) {
                                dp[i][a][b] += dp[i - 1][b][c];
                                dp[i][a][b] %= mod;
                            }
                            continue;
                        }
                        else {
                            dp[i][a][b] += dp[i - 1][b][c];
                            dp[i][a][b] %= mod;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 2; j++) {
            if (i != j && i != 1) {
                ans += dp[n][i][j];
                ans %= mod;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
