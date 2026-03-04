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

int n,m;
vector<vector<char>>  owo;
vector<vector<char>> rec(int ord){
        if(ord == 1){
                return owo;
        }
        vector<vector<char>> lost = rec(ord-1);
        int le = sz(lost);
        string wa;
        f(i,0,le*n)wa += ' ';
        vector<vector<char>> ret ( le*n,vector<char>(le*n,' ') );
        f(i,0,le){
                f(j,0,le){
                        if(lost[i][j] == '.'){
                                f(u,0,n){
                                        f(o,0,n){
                                                ret[i*n + u][j*n +o] = owo[u][o];
                                        }
                                }
                        }else{
                                f(u,0,n){
                                        f(o,0,n){
                                                ret[i*n + u][j*n +o] = '*';
                                        }
                                }

                        }
                }
        }
        return ret;
}

void so(int test){
        cin >> n >> m;
        vector<vector<char>> v(n,vector<char>(n,' '));
        f(i,0,n){
                f(j,0,n){
                        cin >> v[i][j];
                }
        }
        owo = v;
        vector<vector<char>> ans = rec(m);
        f(i,0,sz(ans)){
                f(j,0,sz(ans[0])){
                        cout << ans[i][j];
                }
                cout << ln;
        }


}

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
