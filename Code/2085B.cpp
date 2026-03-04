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
        int n;
        cin >> n;
        vi v(n);
        vi po;
        f(i,0,n){
                cin >> v[i];
                if(!v[i])po.pb(i+1);
        }
        if(sz(po) == 0){
                cout << 1 << ln;
                cout << 1 << ' ' << n << ln;
        }else if(sz(po) == 1){
                cout << 2 << ln;
                if(po[0] > 1){
                        cout << po[0] -1 << ' ' << po[0] << ln;
                }else{
                        cout << po[0] << ' ' << po[0] + 1<<ln;
                }
                cout << 1 << ' ' << n-1 << ln;
        }else if(sz(po) == n){
                cout << 3 << ln;
                cout << 1 << ' ' << n - 2 << ln;
                cout << 2 << ' ' << 3 << ln;
                cout << 1 << ' ' << 2<<ln;
        }else{
                if(po[0] == 1 and po.back() == n){
                        cout << 3 << ln;
                        cout << 1 << ' ' << 2 << ln;
                        cout << 2 << ' ' << n- 1 << ln;
                        cout << 1 << ' ' << 2  << ln;
                        return;
                }
                cout << 2 << ln;
                cout << po[0] << ' ' << po.back() << ln;
                int dif = po.back() - po[0];
                cout << 1 << ' ' << n-dif << ln;
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
