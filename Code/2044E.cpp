#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
    int k,l1,r1,l2,r2;
    cin >> k >> l1 >> r1 >> l2 >> r2 ;
    ll ans = 0;
    auto in = [](int x1, int y1 , int x2, int y2){
        return max(0,min(y1,y2) - max(x1,x2) + 1);
    };
    while(l2 <= r2){
        ans += in (l1,r1,l2,r2) ;
        l2 = (l2+k-1)/k;
        r2 = (r2)/k;
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
