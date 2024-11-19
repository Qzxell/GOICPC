#pragma GCC optimize ("Ofast,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int > vi;
typedef vector<ll > vl;
typedef vector<ii > vii;
#define pb push_back
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define all(v) (v).begin(), (v).end()
#define sz() size()
#define trace(...) fff(#__VA_ARGS__, __VA_ARGS__)
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353, inf = (1 << 30) - 1 + (1 << 30);
const ll infl = (1LL << 62) - 1 +(1LL << 62);
ll add(ll a, ll b){
    if(a + b >= mod){
        return a + b - mod;
    }
    return a + b;
}
ll rem(ll a, ll b){
    if( a <= b){
        return a - b + mod;
    }
    return a - b;
}
ll mul(ll a, ll b){
    return (ll) (a * b) % mod;
}
const ll N = 1e6 + 5;
int A[N], ans[N], u[N];
vi d[N];
int main(){
    fastio;
    f(i, 1, N) u[i] = -1; // MOwbius
    f(i, 2, N){
        if(!d[i].sz()){
            for(int j = i; j < N; j += i) u[j] *= -1;
            ll c = i*i;
            for(ll j = c; j < N; j += c) u[j] = 0;
        }
        for(int j = i; j < N; j += i) d[j].pb(i);
    }

    int n; cin >> n;
    f(i, 0, n) cin >> A[i];

    for(auto x: d[A[n - 1]]) ans[x] = 1;
    fer(i, 1, n - 1){
        int cont = 0;
        for(auto x: d[A[i]]) cont = add(cont, rem(u[x]*ans[x], 0));
        for(auto x: d[A[i]]) ans[x] = add(ans[x], cont);
    }
    int an = 0;
    for(auto x: d[A[0]]) an = add(an, rem(u[x]* ans[x], 0));
    cout << an <<'\n';
    return 0;
}

/*
#################################################################################################
#                                        You told me                                            #
#           At your absolute best, you still won't be good enough for the wrong person          #
#                   At your worst, you'll still be worth it to the right person                 #
#                           It was good while it lasted, good bye                               #
#    I believe I really loved you... to that point that I always wanted to hear your voice      #
#    But before my hand could reach you... you seem to be slowly disappearing from my sight     #
#################################################################################################
*/

