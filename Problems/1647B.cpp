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
        int n,m;
        cin >> n >> m;
        vector<string> ma(n);
        f(i,0,n)cin >> ma[i];

        auto ga = [&](int l,int r)-> int{
                return (ma[l][r] == '1' ? 1 : 0);
        };
        f(i,0,n-1) f(j,0,m-1){
                int va = ga(i,j) + ga(i+1,j) + ga(i,j+1) + ga(i+1,j+1);
                if(va == 3){
                        cout << "NO" << ln;
                        return;
                }
        }
        cout << "YES" << ln;

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
