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

void so(int test){
        int l,r;
        cin >> l >> r;
        vi vis(r-l+2,0);
        vi pot(r-l+2,0);
        for(int i = r; i>= l ;i--){
                if(vis[i-l])continue;
                int bi = __lg(i);
                int nu = (1<<(bi+1)) - 1;
                int num = nu - i;
                if(num >= l){
                        pot[i-l] = bi;
                        pot[num-l] = bi;
                        vis[i-l] = 1;
                        vis[num-l] = 1;
                        continue;
                }
                vis[i-l] = 1;
                pot[i-l] = -1;
        }
        ll ans = 0;
        vi res;
        f(i,0,r-l+1){
                int num = i + l;
                if(pot[i] == -1){
                        res.pb(num);
                        ans += num;
                        continue;
                }
                ans += (((1<<(pot[i]+1)) - 1 - num)|num);
                res.pb((1<<(pot[i]+1)) - 1 - num);
        }
        cout << ans << ln;
        for (auto x :res) {
                cout << x << ' ';
        }
        cout << ln;


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
