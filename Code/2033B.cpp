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
    int m[n][n];
    f(i,0,n){
        f(j,0,n){
            cin >> m[i][j];
        }
    }

    ll ans = 0;

    f(i,0,n){
        int mi = 0;
        // 0 , 1
        int x = 0, y = i;
        f(j,0,n){
            if (x+j >= n or y +j  >= n) {
                continue;
            }
            mi = min(mi,m[x+j][y+j]);
        }
        ans += -mi;
    }
    f(i,1,n){
        int mi = 0;
        // 0 , 1
        int x = i, y = 0;
        f(j,0,n){
            if (x+j >= n or y +j >= n) {
                continue;
            }
            mi = min(mi,m[x+j][y+j]);
        }
        ans += -mi;
    }
    cout << ans << ln;
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
