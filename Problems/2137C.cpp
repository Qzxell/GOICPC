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
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
        ll a,b;
        cin >> a >> b;
        if((a&1) and b%4 != 0 and b%2 == 0){
                cout << -1 << ln;
                return;
        }
        if((b&1) and a%2 == 0){
                cout << -1 << ln;
                return;
        }
        ll ans =( (a + b)%2 == 0 ? (a+b) : 0);
        if((a&1) and (b&1)){
                a *= b;
                b = 1;
                ans = max(ans,a + b);
        }else{
                a *= (b/2);
                b = 2;
                ans = max(ans,a + b);
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



