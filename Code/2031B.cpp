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

    bool yes = 1;
    for( int i = 0 ; i < n ; i++){
        if (v[i] == i+1) {
            continue; 
        }else{
            if (i == n-1 and v[i] != i+1) {
                cout << "NO\n"; 
                return;
            }
            if ( i+1 < n and v[i+1] != i+1) {
                cout << "NO\n"; 
                return;
            }else if (i+1 < n and abs(v[i]-v[i+1]) == 1 and v[i+1] == i+1) {
                swap(v[i],v[i+1]);
                continue;
            }

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
