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

bool fu (int nu ){
    if (nu == 0) {
        return  memo[nu] = 1;    
    }
    if (memo[nu] != 0) {
        return memo[nu]; 
    }
    bool ret = false;
    f(i,0,n){
        if (nu >= V[i] and cost[V[i]]) {
            cost[V[i]] = 0;
            ret = (ret or fu(nu-V[i])) ;
            cost[V[i]] = 1;
        }
    }
    return memo[nu] = ret;

}

void so(int test){
    cin >> n >> k;
    f(i,0,n){
        cin >> V[i];
        cost[V[i]] = 1;
    }
    bool ga = fu(k);
    f(i,0,k+1){
        if (memo[i] ) {
            cout << i << ' ';
        }
    }
    cout << ln;
    f(i,0,k+1){
        cout << memo[i] << ' ';
    }
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
