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

const int N = 2e5 + 5;
vi leder(N);
int pa(int no){
        if(leder[no] == no)
                return no;
        return leder[no] = pa(leder[no]);
}
void so(int test){
        int n;
        cin >> n;
        vi num[n+1];

        bool yes = 0;
        f(i,1,n+1){
                leder[i] = i;
                int a,b;
                cin >> a >> b;
                if(a==b)yes = 1;
                num[a].pb(i);
                num[b].pb(i);
        }
        if(yes ){
                cout << "NO" << ln;
                return;
        }
        vi adj[n+1];
        f(i,1,n+1){
                int u,v;
                u = num[i][0];v = num[i][1];
                adj[u].pb(v);
                adj[v].pb(u);
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
