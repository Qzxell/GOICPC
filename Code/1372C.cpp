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
    f(i,0,n)cin >> v[i];
    vector<bool> ga(n,0);
    int lo = 0;
    int lf = n-1;
    while(lo < n){
        if(v[lo] == lo+1)lo++;
        else break;
    }
    while(lf >= 0){
        if(v[lf] == lf+1)lf--;
        else break;
    }
    int lon = lf - lo +1;
    int c = 0;
    for(int i = lo ; i <= lf ; i++){
        if(v[i] == i+1)c++;
    }

    if(c==lon or lon <= 0){
        cout << 0 << ln;
    }else if(c == 0) {
        cout << 1 << ln;
    } else cout << 2 << ln;

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
