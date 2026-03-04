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
    int n;
    cin >> n;
    vi v(n);
    ll su = 0;
    f(i,0,n){
        cin >> v[i];
        su += v[i];
    }
    auto  fu  = [](int x) {
        int c =0 ;
        ll te = x;
        while(x){
            c++;
            x>>=1;
        }
        if(te - (1ll<<(c-1)) > (1ll<<(c)) - te) return c;
        else return c-1;
    };
    ll sum = 0;
    f(i,0,n){
        ll k = fu(v[i]);
        k = (1ll<<k);
        if(k > 1e9) k >>= 1;
        sum += abs(1ll*v[i] - k);
        cout << k  << ' ';
    }
    cout << ln;
    //cout << sum << ' ' << su;
    //cout <<"####################" <<ln;
    

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
