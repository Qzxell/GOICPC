#include <bits/stdc++.h>
#define ini                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define inic ios_base::sync_with_stdio(false);
#define inic2 cin.tie(NULL);
#define inic3 cout.tie(NULL);
#define endl '\n'
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef __int128 int128;
#define loop(i, k, n) for (ll i = k; i <= n; i++)
#define loopi(i, k, n) for (ll i = k; i >= n; i--)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
#define repi(i, n) for (ll i = n; i >= 0; i--)
#define repi1(i, n) for (ll i = n; i >= 1; i--)
#define repc(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define pb push_back
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define all(v) v.begin(), v.end()
using namespace std;
const ll MX = 5e5 + 5;
const ll MOD = 998244353;
const ll INF = 1e18;
const ll LOG = 30;
const ll ND = 1.4 * LOG * MX; // Para puntual, 1.4 -> 0.7
const ll NEUT = 0;
const ll NEUT_LAZY = 0;
const long double INF_DOUBLE = 1e18 / 1.0;
const long double EPS = 1e-8;
const long double PI = acos(-1.0);
string rgb = "RGB";
int main() {
    ini;
    int t;
    cin >> t;
    while (t--) {
        vector<int> f(3);
        for (int i = 0; i < 3; i++) cin >> f[i];
        string s = "";
        while (true) {
            int n = s.size();
            int id = -1;
            for (int i = 0; i < 3; i++) {
                char c = rgb[i];
                if (n - 1 >= 0 && s[n - 1] == c) continue;
                if (n - 3 >= 0 && s[n - 3] == c) continue;
                if (!f[i]) continue;
                if (id == -1 || f[id] < f[i] || (f[id] == f[i] && n - 2 >= 0 && s[n - 2] == c))
                    id = i;
            }
            if (id == -1) break;
            s += rgb[id];
            f[id]--;
        }
        cout << (int)s.size() << endl;
    }
    return 0;
}
