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
    sort(all(v));
    int i = 0 ;
    int j = n-1;
    while(i < j){
        if (v[i]*1ll*v[j] == n-2) {
            cout << v[i] << ' ' << v[j] << ln;
            return;
        }
        if (v[i]*1ll*v[j] < n-2) {
            i++; 
            continue;
        }
        if (v[i]*1ll*v[j] > n-2) {
            j--; 
            continue;
        }
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
