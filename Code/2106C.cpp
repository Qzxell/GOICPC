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
        int n,k;
        cin >> n >> k;
        vi a(n),b(n);
        f(i,0,n)cin >> a[i];
        f(i,0,n)cin >> b[i];

        int value = -1;
        f(i,0,n){
                if(b[i] != -1){
                        if(value == -1){
                                value = a[i] + b[i];
                        }else{
                                if(value != a[i] + b[i]){
                                        cout << 0 << ln;
                                        return;
                                }
                        }
                }
        }
        if(value != -1){
                f(i,0,n){
                        if(b[i] != -1)continue;
                        if(value - a[i] > k or value - a[i] < 0){
                                cout << 0 << ln;
                                return;
                        }
                }
                cout << 1 << ln;
                return;
        }
        int ma = 0;
        int mi = 1e9;
        f(i,0,n){
                ma= max(ma,a[i]);
                mi = min(mi,a[i]);
        }
        cout << max(k+mi - (ma) + 1,0) << ln;


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
