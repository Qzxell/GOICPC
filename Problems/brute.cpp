#include<bits/stdc++.h>
#include<bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
#define ll long long
#define ld long double
//#define int long long
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define pb(k) push_back(k)
#define inv(v) for(auto&it:v){cin>>it;}
#define sv(v, n) v = vector<int>(n);
#define rere return ret;
#define pa pair<int,int>
#define ini(dp) memset(dp,-1, sizeof(dp));
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define FLASH  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void MILO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

int dx[] = {-1, 0, 1, 0, -1, -1, 1, 1, 0};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1, 0};
vector<ll> v, pre;
ll dp[404][404];

ll go(int l, int r) {
    if (l >= r)return 0;
    ll &ret = dp[l][r];
    if (~ret)rere;
    ret = 1e18;
    for (int i = l; i < r; ++i) {
        ret = min(go(l, i) + go(i + 1, r) + pre[r] - pre[l - 1], ret);
    }
    rere;
}

void O_O() {
    int n;
    cin >> n;
    ini(dp);
    v = pre = vector<ll>(n + 6);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
        pre[i] += pre[i - 1] + v[i];
    }
    cout << go(1, n);
}

int32_t main() {
    int rep = 1;
//    cin >> rep;
    while (rep--) O_O();
    return 0;
}
