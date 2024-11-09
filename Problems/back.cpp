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

const int ga = 501;
int n , k; 
int V[ga];
bool memo[ga];
bool cost[ga];

void show(vi v) {
    f(i,0,sz(v))cout << v[i] << ' ';
    cout << ln;
}

void back (vi carr ,int nu ){
    if (nu == 0) {
        show(carr);
        return;
    }
    //if (memo[nu] != 0) {
        //return memo[nu]; 
    //}
    //bool ret = false;
    f(i,0,n){
        if (nu >= V[i] and cost[V[i]]) {
            cost[V[i]] = 0;
            carr.pb(V[i]);

            back(carr,nu-V[i]);

            carr.pop_back();
            cost[V[i]] = 1;
        }
    }
}

void so(int test){
    cin >> n >> k;
    f(i,0,n){
        cin >> V[i];
        cost[V[i]] = 1;
    }
    vi ga;
    back(ga,k);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    int test = 1;
    f(i,0,ga)cost[i] = 0;
    while (tt--){
        so(test++);
    }
    return 0;
}
