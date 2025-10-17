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
#define point complex<long long>
#define x real()
#define y imag()

void so(int test){
        int n,k;
        cin >> n >> k;
        vi v(n);
        vi b(k);
        ll ans = 0;
        f(i,0,n){
                cin >> v[i];
                ans += v[i];
        }
        f(i,0,k)cin >> b[i];
        sort(rall(v));
        sort(all(b));
        int cur = 0;
        int ind = 0;
        while(cur < n){
                if(ind < k and cur + b[ind] - 1 < n){
                        ans -= v[cur + b[ind] - 1];
                        cur += b[ind];
                        ind++;
                }else{
                        cur ++;
                }
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



