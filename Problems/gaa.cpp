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

bool fu (int sum_dispo, int pos ){
    if(memo[sum_dispo][pos] != -1) return memo[sum_dispo][pos];

    if(sum_dispo == 0) {
        ans[k-sum_dispo] = 1;
        cout << sum_dispo << ' ' << pos <<' ' << 1 << ln;
        return  memo[sum_dispo][pos] = true; 
    }
    if( pos < 0 ) return 0;


    bool ret = false || fu(sum_dispo, pos-1);

    if(V[pos-1] <= sum_dispo ) ret =( ret || fu(sum_dispo - V[pos-1], pos - 1));

    if(ret) ans[ k - sum_dispo] = 1;

    cout << sum_dispo << ' ' << pos <<' ' << ret << ln;
    return memo[sum_dispo][pos] = ret;
}

void so(int test){
    cin >> n >> k;
    f(i,0,n){
        cin >> V[i];
    }
    bool ha = fu(k,n);
    f(i,0,k+1) if (ans[i]){
        cout <<  i << ' ';
    }
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
