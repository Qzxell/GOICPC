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

const int MAXN = 2e5 + 5;
const int K = 20;  // log2(MAXN) + margen

int st[MAXN][K + 1]; // st[i][j] = máximo en A[i..i + 2^j - 1]
int lg[MAXN];        // log2 de cada número

void precompute_log(int N) {
    lg[1] = 0;
    for (int i = 2; i <= N; ++i)
        lg[i] = lg[i / 2] + 1;
}

void build_sparse_table(const vector<int>& A) {
    int N = A.size();
    precompute_log(N);

    for (int i = 0; i < N; ++i)
        st[i][0] = A[i];

    for (int j = 1; (1 << j) <= N; ++j) {
        for (int i = 0; i + (1 << j) <= N; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query_max(int L, int R) {
    int j = lg[R - L + 1];
    return max(st[L][j], st[R - (1 << j) + 1][j]);
}

map<int,vi> ind;

int fu(int l , int r){
        if(l > r)return 0;
        if(l == r)return 1;
        int ma = query_max(l,r);
        int in = l;
        int ret = 1;
        int co = 0;
        int ind_l,ind_r;
        ind_l = lower_bound(all(ind[ma]),l) - ind[ma].begin();
        ind_r = upper_bound(all(ind[ma]),r) - ind[ma].begin();
        for(int i = ind_l ; i < ind_r;i++){
                int loc = ind[ma][i];
                if(loc < l or loc > r)continue;
                ret = max(1 + fu(in,loc-1),ret);
                in = loc + 1;
                co++;
        }
        if(co){
                ret = max(1 + fu(in,r),ret);
        }
        return ret;
}

void so(int test){
        int n;
        cin >> n;
        vi v(n);
        f(i,0,n){
                cin >> v[i];
                ind[v[i]].pb(i);
        }
        build_sparse_table(v);
        int ans = fu(0,n-1);
        cout << ans << ln;
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
