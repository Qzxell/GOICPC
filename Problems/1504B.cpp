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
    string a,b;
    cin >> a >> b;

    vi points;
    int cur = 0;
    f(i,0,n){
        cur += (a[i] == '1' ? 1 : -1);
        if (cur == 0) {
            points.pb(i) ;
        }
    }
    int l = 0;
    if (points.empty() and a != b) {
        cout << "NO\n";
        return;
    }
    if (points.empty() ) {
        cout << "YES\n";
        return;
    }
    for(int r : points){
        bool equ = 0;
        if (a[l] == b[l]) {
            equ = 1; 
        }
        f(i,l,r+1){
            int diga,digb;  
            diga = a[i] - '0';
            digb = b[i] - '0';
            if (equ and diga != digb) {
                cout << "NO\n";
                return;
            }
            if (!equ and diga == digb) {
                cout << "NO\n";
                return;
            }
        }
        l = r + 1;
    }
    f(i,points.back()+1,n){
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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
