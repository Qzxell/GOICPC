#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
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

const int MOD = 1e9 + 7;
template<typename T>
T binpow(T a, T b) {
        T ans = 1;
        while (b) {
                if (b & 1) {
                        ans = 1LL * ans * a % MOD;
                }
                a = 1LL * a * a % MOD;
                b >>= 1;
        }
        return ans;
}
void so(int test){
        ll l,r,k;
        cin >> l >> r >> k;
        cout << (binpow((9/k)+1,r) - binpow((9/k)+1,l) + MOD)%MOD << ln;
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



