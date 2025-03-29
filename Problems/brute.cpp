#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define double long double
#define int long long
using pii = pair<ll, ll>;
using i128 = __int128_t;

using ar3 = array<int, 3>;
#define fi first
#define se second
// std::mt19937 rnd{std::chrono::steady_clock::now().time_since_epoch().count()};
const int N = 1e7 + 10;
const int M = 1e4;
const int mod = 1e9 + 7;
const int inf = (1ll << 60) + 1;
const double pi = acos(-1.0);
const double eps = 1e-12;
const int B = sqrt(N);


void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    int cnt = n / 2;
    int i = n, j = cnt;
    int res = 0;
    while (j > 0 && i >= n / 2 + 1)
    {
        while (j > 0 && a[j] * 2 > a[i]) --j;
        if (j > 0)
        {
            --i;
            --j;
            res++;
        }
    }
    cout << res << '\n';
}

signed main()
{    
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << fixed << setprecision(10);
    int t = 1;
    // cin >> t;  
    while (t--)
    {
        solve();
    }
    return 0;
}


// 树的路径：dp (每个点作为端点或者中间点)
// 二维数点：离散化 + 有序固定一维，数据结构(Fenwick)处理第二维
// 数位dp的核心：1.高位限制 2. 数位关系

// 110001100
// 000001111
// 689589940713840351
// 
