#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int N = 1594328;
string s;
vector<vi> dp(N, vi(14, -1));  // Memoización para re
vector<vi> memo(N, vi(14, -1)); // Memoización para swa
vi pot(15);
int to;

int re(int lex, int ord) {
    if (!ord) return (s[lex] == '1' ? 1 : 0);
    if (dp[lex][ord] != -1) return dp[lex][ord];
    vi v(3, 0);
    int le = pot[ord];
    v[re(lex, ord-1)]++;
    v[re(lex + le/3, ord-1)]++;
    v[re(lex + 2*le/3, ord-1)]++;
    return dp[lex][ord] = max_element(all(v)) - v.begin();
}

int swa(int x, int ord) {
    if (!ord) return ((s[x] == '1' ? 1 : 0) == to ? 0 : 1);
    if (memo[x][ord] != -1) return memo[x][ord];  // Usar memoización
    
    int le = pot[ord];
    vi v(2, 0);
    int a = dp[x][ord-1], b = dp[x + le/3][ord-1], c = dp[x + 2*le/3][ord-1];
    v[a]++; v[b]++; v[c]++;
    
    if (max_element(all(v)) - v.begin() == to) 
        return memo[x][ord] = 0;
    
    vi costs;
    if (a != to) costs.pb(swa(x, ord-1));
    if (b != to) costs.pb(swa(x + le/3, ord-1));
    if (c != to) costs.pb(swa(x + 2*le/3, ord-1));
    
    sort(all(costs));
    int ans;
    if (v[to] == 0) 
        ans = (costs.size() >= 2 ? costs[0] + costs[1] : 1e9);
    else if (v[to] == 1) 
        ans = (costs.size() >= 1 ? costs[0] : 1e9);
    else 
        ans = 0;
    
    return memo[x][ord] = ans;
}

void so(int test) {
    int n;
    cin >> n;
    cin >> s;
    s = '0' + s;
    pot[0] = 1;
    f(i, 1, 14) pot[i] = pot[i-1] * 3;
    
    
    to = 1 - re(1, n);
    //int ans = swa(1, n);
    //cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    while (tt--) so(tt);
    return 0;
}
