#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<long long>  ;
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

bool yes = 1;
void so(int test){
        int n;
        if(!(cin >> n)){
                yes = 0;
                return;
        }
        vi dp(n+3,0);
        dp[0] = 1;
        f(i,0,n+1){
                dp[i+1] = dp[i] + dp[i+1];
                dp[i+2] = dp[i+2] + dp[i]*1ll*2;
        }
        cout << dp[n] << ln;
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);

        int tt = 1;
        int test = 1;
        while (yes){
                so(test++);
        }
        return 0;
}



