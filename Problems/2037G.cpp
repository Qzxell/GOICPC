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
    int n = 1e6 + 1;
    vi prime;
    vi primes(n+1,1);
    for(int i = 2; i <= n;i++){
        if(primes[i] and i*1ll*i <= n){
            prime.pb(i);
            for(int j = i*i; j <= n;j += i)
                primes[j] = 0;
        }
    }
    vi adj[n+1];
    int cur = -1;


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    //cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}