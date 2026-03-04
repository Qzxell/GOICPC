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
        cin >> n >> m ;
        vi a(n),b(m);
        f(i,0,n)cin >> a[i];
        f(i,0,m)cin >> b[i];
        vi s(m,-1),p(m,-1);
        auto fin = [&](int l,int r,int ind_qu){
                for(int i = l ; i <= r; i++){
                        if(a[i] >= b[ind_qu])return i;
                }
                return -1;
        };
        auto fin2 = [&](int l,int r,int ind_qu){
                for(int i = r ; i >= l; i--){
                        if(a[i] >= b[ind_qu])return i;
                }
                return -1;
        };
        int lost = 0;
        f(i,0,m){
                int ind_fi = fin(lost,n-1,i);
                if(ind_fi == -1){
                        break;
                }
                s[i] = ind_fi;
                lost = ind_fi + 1;
        }
        lost = n-1;
        for(int i = m-1; i >= 0; i--){
                int ind_fi = fin2(0,lost,i);
                if(ind_fi == -1){
                        break;
                }
                p[i] = ind_fi;
                lost = ind_fi - 1;
        }
        int ans = 1e9 + 2;

        if(p[0] >= 0 or s[m-1] >= 0 ){
                cout << 0 << ln;
                return;
        }
        if(m == 1){
                ans = b[0];
        }
        if(1 < m and p[1] != -1){
                ans = b[0];
        }
        if(m-2 >= 0 and s[m-2] != -1){
                ans = min(b[m-1],ans);
        }
        f(i,1,m-1){
                if(s[i-1] != -1 and p[i+1] != -1 and s[i-1] < p[i+1]){
                        ans = min (ans,b[i]);
                }
        }
        cout << (ans != 1e9 + 2 ? ans : -1 ) << ln;
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
