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
        string s;
        cin >> s;
        vector<vi> m(26);
        int n = sz(s);
        f(i,0,sz(s)){
                m[s[i]-'a'].pb(i);
        }
        int inf = INT_MAX;
        vi dp(n+5,inf);
        dp[0] = 0;
        f(i,0,n)if(dp[i] != inf){
                // decicion i+1
                int juicio = i + 1;
                dp[juicio] = min(dp[juicio], dp[i] + 1);// ignored
                int pos = juicio - 1;
                int fi = upper_bound(all(m[s[pos]-'a']),pos) - m[s[pos]-'a'].begin();
                if(fi == sz(m[s[pos]-'a']))continue;
                int brig = m[s[pos]-'a'][fi] + 1;
                int dif = brig - juicio - 1;
                dp[brig] = min(dp[brig],dp[i] + dif);
        }
        cout << dp[n] << ln;
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



