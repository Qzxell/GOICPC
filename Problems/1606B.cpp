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

void so(int test){
    ll n,k;
    cin >> n>> k;
    ll owo = 1;
    int c = 1;
    ll ans = 0;
    if (n == 1 ) {
        cout << 0 << ln;
        return;
    }
    while(owo <= k){
        c++;
        owo <<= 1;
        ans ++;
        if (owo >= n) {
            owo = n;
            break; 
        }
    }
    ans += (n - owo + k -1)/k;
    cout << ans << ln;
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
