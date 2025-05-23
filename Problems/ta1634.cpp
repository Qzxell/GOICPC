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

const int ga = 101;
int n , x;
int V[ga];
const int fa = 1e6 + 1;
int memo[fa];

int fu(int nu){
    if (memo[nu] != 0) {
        return memo[nu] ;
    }
    if (nu == 0) {
       return 0; 
    } 
    int ret = 1e9;
    f(i,0,n){
        if (nu >= V[i]) {
            ret = min(ret,fu(nu-V[i]) + 1) ;
        }    
    }
    return memo[nu] = ret;
}

void so(int test){
    cin >> n >> x;
    f(i,0,n){
        cin >> V[i];
    }
    int ans = fu(x) ;
    ans = (ans == 1e9 ? -1 : ans);
    cout << ans;

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
