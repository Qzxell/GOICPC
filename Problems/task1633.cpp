#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int ma= 1e6+1;
int memo[ma];
const int mod = 1e9 + 7;

ll dp(int n){
    if(n <= 0) return 0;
    if(memo[n] != 0)return memo[n];


    ll ans = ( n >= 1 and n <= 6 ? 1 : 0);
    f(i,1,7){
        ans = (ans + dp(n-i))%mod;
    }
    return memo[n] = ans;
}
void so(int test){
    int n;
    cin >> n;
    cout << dp(n);
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
