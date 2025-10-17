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
        int n,q;
        cin >> n>>q;
        vi v(n);
        vi ps(n+1,0);
        vi mx(n+1,0);
        f(i,0,n){
                cin >> v[i];
        }
        f(i,0,n-2){
                bool val = (v[i] > v[i+1] and v[i+1] > v[i+2]);
                ps[i+1] = ps[i] + (val);
                mx[i+1] = max(mx[i],v[i]);
        }
        f(i,0,q){
                int l,r;
                cin >> l >> r;
                if(r-l+1 < 3 ){
                        cout << "YES" << ln;
                        continue;
                }
                if(ps[r-2] - ps[l-1] or (mx[r-2] > v[r-2] and v[r-2] > v[r-1])){
                        cout << "NO" << ln;
                }else cout << "YES" << ln;
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



