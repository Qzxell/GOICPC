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


vi sq;
void so(){
    int n;
    cin >> n;
    auto x = lower_bound(all(sq),n-1) ;
    int ra = *x;
    int sh = n-1;
    vi ans(n);
    for(int i = n-1 ; i >=0 ;i--){
        if (ra - i == n) {
            sh = i;
            break; 
        }
        ans[i] = ra - i;
    }
    auto y = lower_bound(all(sq),sh) ;
    ra = *y;
    for(int i = sh ; i >= 0;i--){
        ans[i] = ra - i;
    }
    for(auto x:ans)cout << x << ' ';
    cout << ln;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0 ; i < 100000; i++){
        if (i*i > 1e5) {
            sq.pb(i*i);
            break; 
        }
        sq.pb(i*i);
    }
    int tt = 1;
    cin >> tt;
    while (tt--){
        so();
    }
    return 0;
}
