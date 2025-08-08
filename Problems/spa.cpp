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
const int K = 20;  

int st[MAXN][K + 1]; 
int lg[MAXN];        
                    
void precompute_log(int N) {
    lg[1] = 0;
    for (int i = 2; i <= N; ++i)
        lg[i] = lg[i / 2] + 1;
}

void build(const vector<int>& A) {
    int N = sz(A);

    for (int i = 0; i < N; ++i)
        st[i][0] = A[i];

    for (int j = 1; (1 << j) <= N; ++j) {
        for (int i = 0; i + (1 << j) <= N; ++i) {
            st[i][j] = gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query(int L, int R) {
    int j = lg[R - L + 1];
    return gcd(st[L][j], st[R - (1 << j) + 1][j]);
}

void so(int test){
        int n,q;
        cin >> n >> q;
        vi v(n);
        f(i,0,n)cin >> v[i];

        for(int i = n-1; i > 0 ; i--){
                v[i] -= v[i-1];
        }
        v[0] = 0;

        build(v);

        f(i,0,q){
                int l,r;
                cin >> l >> r;
                if(l == r){
                        cout << 0 << ' ';
                }else{
                        r--;
                        cout <<  query(l,r) << ' ' ;
                }
        }
        cout << ln;
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
        precompute_log(MAXN-1);

	int tt = 1;
        cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
