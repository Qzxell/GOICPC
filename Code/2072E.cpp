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
        if( n ==0){
                cout << 0 << ln;
                return;
        }

        auto ga = [&](int nn){
                int pu = 0;
                f(i,1,500){
                        if((i*(i-1))/2 <= nn)pu = i;
                }
                return pu;
        };
        int pu = ga(n);
        int sobr = n - ( pu*(pu-1))/2;
        ii in = {-10000000,-10000000};
        vii ans(pu,in);
        f(i,1,pu){
                ans[i].se = ans[i-1].se + 1;
        }
        int au = 10000;
        int ch = 0;
        int aux = sobr;
        f(i,0,aux)if(sobr >= 1){
                int uwu = ga(sobr);
                sobr -=  ( uwu*(uwu-1))/2;
                f(j,1,uwu){
                        ans.pb({ans[i].fi + j*au + ch, ans[i].se});
                }
                        ch++;
        }
        cout << sz(ans) << ln;
        for(auto [a,b] : ans){
                cout << a << ' ' << b << ln;
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
