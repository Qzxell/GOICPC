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

const int N = 1e5 + 5;
vi color(N,-1);
vi comp(N,0);
vi p(N);
vi d(N);
int n;

int col = 0;
void dfs(int nod){
        if(color[nod] != -1)return;
        color[nod] = col;
        comp[col]++;
        dfs(p[nod]);
}

void so(int test){
        cin >> n;
        f(i,0,n)color[i] = -1;
        col = 0;
        f(i,0,n)cin >> p[i],p[i]--;
        f(i,0,n)cin >> d[i],d[i]--;
        f(i,0,n){
                dfs(i);
                col++;
        }
        int cur = 0;
        f(i,0,n){
                int cur_col = color[d[i]];
                cur += comp[cur_col];
                cout << cur << ' ';
                comp[cur_col] = 0;
        }
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


