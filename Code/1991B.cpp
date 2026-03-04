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
    vi ans(n,0);
    vi b(n-1);
    f(i,0,n-1){
        int x;
        cin >> b[i];
        x = b[i];
        ans[i] |= x;
        ans[i+1] |= x;
    }
    auto gee = [&](int ga,int i ){
        return (bool)((ga>>i)&1);
    };
    for(int i = 1; i < n -2 ;i++){
        for(int j = 0; j < 30 ;j++)if(!gee(b[i],j)){
            if (gee(b[i-1],j) and gee(b[i+1],j)) {
                cout << -1 << ln;
                return;
            }
        }
    }
    for(int x : ans) cout << x << ' ';
    cout << ln;
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
