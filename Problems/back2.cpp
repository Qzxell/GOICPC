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
int memo[ga][ga];
int ans[ga];

void show(vi v) {
    f(i,0,sz(v))cout << v[i] << ' ';
    cout << ln;
}

void bac (vi carry, int remain_sum,  int pos ){
    if(pos < 0){
        return;
    }
    if(remain_sum == 0) show(carry);
    
    if(V[pos] <= remain_sum) {
        carry.pb(V[pos]);
        bac(carry, remain_sum - V[pos] , pos-1);
        carry.pop_back();
    }
    bac(carry, remain_sum , pos-1);
}

void so(int test){
    cin >> n >> k;
    f(i,0,n){
        cin >> V[i];
    }
    vi gaa;
    bac(gaa, k , n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 1;
    int test = 1;
    f(i,0,ga)
        f(j,0,ga)
            memo[i][j] = -1;

    while (tt--){
        so(test++);
    }
    return 0;
}
