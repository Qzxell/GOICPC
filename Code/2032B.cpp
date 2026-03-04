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
    int n,k;
    cin >> n >> k;
    if ((k&1) == 0) {
        cout << 3 << ln; 
        cout << 1 <<' ' <<  k  <<' '<< k+1 << ln ;
    }else {
        if (k == 1 and n == 1) {
            cout <<1 << ln;
            cout << 1 << ln;
            return;
        }
        if (k == n or k == 1) {
            cout << -1 << ln;
            return;
        }
        cout <<5 << ln;
        cout <<1 << ' '<< k-1  << ' ' << k << ' ' << k+1 <<' ' << k+2 << ln;
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
