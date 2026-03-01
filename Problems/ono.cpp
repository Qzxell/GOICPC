#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

const ll INF = 1e17 + 9;
const int MAXN = 200005; 
const int MAXLOG = 20;

int n, q;
vi G[MAXN];
ll dp[MAXN];
int dp_p[MAXN][MAXLOG];
ll dp_acu[MAXN][MAXLOG];
int tin[MAXN], tou[MAXN], line[MAXN * 3];
int tim = 0;

ll add(ll a, ll b) {
    return min(INF, a + b);
}

void dfs(int nod, int pat) {
    bool ok = 0;
    line[tim] = nod;
    tin[nod] = tim++;
    for (auto x : G[nod]) {
        if (x != pat) {
            dp_p[x][0] = nod;
            dfs(x, nod);
            line[tim++] = nod;
            dp[nod] += dp[x];
            ok = 1;
        }
    }
    if (ok) dp[nod] += 4;
}

int get_res(int nod, int cur) {
    return line[tin[nod] + cur];
}

int solve_query(int nod, int k) {
    if (dp[nod] >= k) {
        return get_res(nod, k);
    }
    int cur = k;
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (dp_p[nod][i] != 0 && cur >= dp_acu[nod][i]) {
            cur -= dp_acu[nod][i];
            nod = dp_p[nod][i];
        }
    }
    return get_res(nod, cur);
}

void so(int test) {
    if (!(cin >> n >> q)) return;
    
    tim = 0;
    for (int i = 0; i <= n; i++) {
        G[i].clear();
        dp[i] = 0;
	fill(dp_p[i], dp_p[i] + MAXLOG, 0);
        //memset(dp_p[i], 0, sizeof(dp_p[i]));
        forn(j, MAXLOG) dp_acu[i][j] = INF;
    }

    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
	if(l == r and l == 0)continue;
        G[i].push_back(l);
        G[i].push_back(r);
    }

    dfs(1, 0);

    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            dp_p[i][j] = dp_p[dp_p[i][j - 1]][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        dp_acu[i][0] = add(1, dp[i]);
    }

    for (int j = 1; j < MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            int pa = dp_p[i][j - 1];
            if (pa != 0)
                dp_acu[i][j] = add(dp_acu[i][j - 1], dp_acu[pa][j - 1]);
            else
                dp_acu[i][j] = dp_acu[i][j - 1];
        }
    }

    forn(i, q) {
        int v, k;
        cin >> v >> k;
        cout << solve_query(v, k) << (i == q - 1 ? "" : " ");
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    int test = 1;
    while (tt--) so(test++);
    return 0;
}
