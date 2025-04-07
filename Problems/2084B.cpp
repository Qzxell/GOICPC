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
        vector<ll> v(n);
        f(i,0,n)cin >> v[i];
        sort(all(v));
        ll ga = v[0];
        ll gc = -1;
        f(i,1,n)if(v[i]%ga ==0){
                if(gc == -1)gc = v[i]/ga;
                else{
                        gc = gcd(gc,v[i]/ga);
                }
        }
        if(gc == 1){
                cout << "Yes" ;
        }else cout << "No";
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
