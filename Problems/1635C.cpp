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
        f(i,0,n)cin >> v[i];
        if(v[n-2] > v[n-1]){
                cout << -1 << ln;
                return;
        }
        if(v[n-1] < 0){
                if(is_sorted(all(v))){
                        cout << 0 << ln;
                }else{
                        cout << -1 << ln;
                }
                return;
        }
        cout << n -2 << ln;
        f(i,1,n-1){
                cout << i << ' ' << n-1 << ' ' << n << ln;
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
