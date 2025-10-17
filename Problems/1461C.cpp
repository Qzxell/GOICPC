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
        vi p(n);
        vi god(n,0);

        f(i,0,n){
                cin >> p[i];
                p[i]--;
        }

        for(int i = n-1;i >= 0;i--){
                if(p[i] == i)god[i] = 1;
                else {
                        break;
                }
        }

        vector<vector<double>> op(n);
        vector<bool> hav(n,0);

        f(i,0,m){
                int pos;
                double b;
                cin >> pos >> b;
                pos--;
                op[pos].pb(b);
                hav[pos] = 1;
        }
        double ans = 0;
        if(god[0]){
                ans = 1.0;
                cout << ans << ln;
                return;
        }
        vi vis(n,0);
        int mex = 0;
        double cur_ord = 1;
        f(i,0,n){
                vis[p[i]] = 1;
                while(vis[mex])mex++;
                if(mex != i+1 or !have[i]){
                        cur_ord = 0;
                        continue;
                }
                double cur = 0;
                double acu = cur_ord;

                for(auto pro : op[i]){
                        cur += pro;
                }

        }

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
        cout << fixed << setprecision(6);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
