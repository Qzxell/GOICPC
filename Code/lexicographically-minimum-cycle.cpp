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

const int N = 105;
vi G[N];
vi papa(N,0);
vi color(N,0);
vi cicl;

void mi(vi &cy){
        int lon = sz(cy);
        int ind = 0;
        f(i,1,lon){
                f(j,0,lon){
                        if(cy[(i+j)%lon] < cy[(ind + j)%lon]){
                                ind = i;
                                break;
                        }
                        if(cy[(i+j)%lon] > cy[(ind + j)%lon]){
                                break;
                        }
                }
        }
        rotate(cy.begin(),cy.begin() + ind,cy.end());
}
int comp(const vector<int>& a, const vector<int>& b) {
    int n = (int)a.size();
    int m = (int)b.size();
    int len = min(n, m);

    for (int i = 0; i < len; ++i) {
        if (a[i] < b[i]) return -1;
        if (a[i] > b[i]) return 1;
    }
    if (n < m) return -1;
    if (n > m) return 1; 
    return 0;           
}

map<ii,int> ma;
void dfs(int nod, int pat){
        color[nod] = 1;
        papa[nod] = pat;
        for(auto x :G[nod])if(x != pat){
                if(color[x] == 1){
                        //cycle
                        int cur = nod;
                        vi cy;
                        while(cur != x){
                                cy.pb(cur);
                                cur = papa[cur];
                        }
                        cy.pb(cur);

                        vi ga = cy;
                        mi(ga);
                        reverse(all(cy));
                        mi(cy);

                        if(comp(ga,cy) == -1)swap(ga,cy);
                        if(cicl.empty())swap(cicl,cy);
                        else{
                                if(comp(cy,cicl))swap(cy,cicl);
                        }

                }else if(color[x] == 0){
                        dfs(x,nod);
                }
        }
        color[nod] = 2;
}


void so(int test){
        int n,m;
        cin >> n >> m;
        bool yes = 0;
        int uu,vv;
        f(i,0,m){
                int u,v;
                cin >> u >> v;
                G[u].pb(v);
                G[v].pb(u);
                if(u > v)swap(u,v);ma[{u,v}]++;
                if(ma[{u,v}] > 1){
                        yes = 1;
                        uu = u;v= vv;
                }
        }
        if(yes){
                cout << "YES" << ln;
                cout << 2 << ln;
                cout << uu << ' ' << vv << ln;
                return;
        }
        f(i,1,n+1)if(!color[i])dfs(i,-1);
        if(sz(cicl) == 0){
                cout << "NO" << ln;
                return;
        }
        cout << "YES" << ln;
        cout << sz(cicl) << ln;
        for(auto x : cicl)cout << x<< ' ';
        cout << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
