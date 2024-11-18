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
    bool fa = 1;
    f(i,1,n)if(v[i] != v[i-1])fa = 0;
    if (fa) {
        cout << 0 << ln; 
        return;
    }


    bool ga = 1;
    ll c = -1,m = 0;
    ll dif = -1;
    f(i,1,n){
        if (v[i-1] == v[i]) {
            cout << -1 << ln;
            return;
        }
        if (v[i-1] < v[i]) {
            if (c == -1) {
                c = v[i] - v[i-1] ;
            }else if(v[i] - v[i-1] != c){
                cout << -1 << ln;
                return;
            }
        }else{
            if (dif == -1) {
                dif = v[i-1] - v[i] ;
            }else if ( dif != v[i-1] - v[i]){
                cout << -1 << ln;
                return;
            }
        }
    }
    if (c != -1 and dif != -1) {
        if (c + dif <= *max_element(all(v))) {
            cout << -1 << ln;
            return;
        }
        cout << c + dif << ' ' << c << ln; 
    }else{
        cout << 0 << ln;
        return;
    }

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
