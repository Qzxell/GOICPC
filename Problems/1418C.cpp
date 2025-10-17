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

void so(int test){
        int n;
        cin >> n;
        int inf = INT_MAX;
        vector<int> v(n);
        vi dp(n+5,inf);
        for (int &val : v) {
                cin >> val;
        }
        dp[0] = 0;
        f(i,0,n)if(dp[i] != inf){
                dp[i + 2] = min(dp[i+2],dp[i] + (v[i] == 1));
                dp[i + 3] = min(dp[i+3],dp[i] + (v[i] == 1));
                if(i+1 < n){
                        dp[i + 3] = min(dp[i+3],dp[i] + (v[i] == 1) + ( v[i+1] == 1));
                        dp[i + 4] = min(dp[i+4],dp[i] + (v[i] == 1) + (v[i+1] == 1));
                }
        }
        cout << min({dp[n],dp[n+1],dp[n+2]}) << ln;
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



