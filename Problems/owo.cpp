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
#define ln '\n'
template<typename t> void fff(const char* x, t&& val1) { cout<<x<< " : "<<val1<<"\n";}
template<typename t1, typename... t2> void fff(const char* x, t1&& val1, t2&&... val2){
    const char* xd=strchr(x+1, ',');
    cout.write(x, xd-x)<<" : "<<val1<<" | ";
    fff(xd+1, val2...);
}
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7, inf = (1 << 30) - 1 + (1 << 30);
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
const ll N = 5e5 + 5;
int A[N], ma[N], ans[N], n;
vi adj[N];
bool vist[N];
void dfs(int a){
    vist[a] = 1;
    ans[a] = ma[a];
    for(auto v: adj[a]){
        if(!vist[v]) dfs(v);
        ans[a] = max(ans[a], ans[v]);
    }
}
int main(){
    fastio;
    int t; cin >> t; 
    int cont = 1;
    while(t--){ 
        cin >> n;
        cout << "test " << cont++ << ln;
        vii aux;
        f(i, 1, n + 1) cin >> A[i], aux.pb({A[i], i});
        sort(all(aux),[&](auto a, auto b){
                if(a.ff == b.ff) return a.ss < b.ss;
                return a.ff < b.ff;
                });
        int cur = 0;
        for(auto [val, in]: aux){
            cur = max(cur, in);
            adj[in].pb(cur);
        }
        for(int i = 0 ; i < n ; i++){
            if (adj[i].empty()) {
                continue; 
            }
            cout << "P " << i <<":" << ln;
            for(int k : adj[i]){
                cout << k << ' ';
            }
            cout << ln;
        }

        int in = 1;
        f(i, 1, n + 1){
            if(A[i] > ma[i - 1]){
                ma[i] = A[i];
                in = i;
            }else ma[i] = ma[i - 1];
            adj[i].pb(in);
        }
        f(i, 1, n + 1){
            if(!vist[i]) dfs(i);
            cout << ans[i] <<' ';
        }
        cout <<'\n';
        f(i, 1, n + 1){
            vist[i] = 0, ans[i] = 0;
            vi ().swap(adj[i]);
        }
    }
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

