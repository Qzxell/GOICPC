#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
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
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

void so(int test){
        int n,m;
        cin >> n >> m;
        vi a(n);
        vi b(m);
        int inf = 1e9;
        vi T(n+1,inf);
        f(i,0,n){
                cin >> a[i];
                T[i+1] = inf--;
        }
        f(i,0,m)cin >> b[i];
        f(i,0,m){
                T[b[i]] = i;
        }
        ordered_set x;
        ll ans = 0;
        int lost = 0;
        int cant = 0;
        f(i,0,m){
                auto it =x.find(T[b[i]]);
                if(it != x.end()){
                        int ind = x.order_of_key(T[b[i]]);
                        ans += 2*ind + 1;
                        x.erase(it);
                        cant--;
                        continue;
                }
                for(int j = lost;j < n;j++){
                        if(a[j] == b[i]){
                                ans += 2*(cant) + 1;
                                lost = j + 1;
                                break;
                        }
                        x.insert(T[a[j]]);
                        cant++;
                }
        }
        cout << ans << ln;


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
