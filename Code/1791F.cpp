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

struct RangeFenwick {
    int n;
    vector<long long> bit1, bit2;

    RangeFenwick(int n) {
        this->n = n;
        bit1.assign(n+1, 0);
        bit2.assign(n+1, 0);
    }

    void add(vector<long long>& bit, int idx, long long val) {
        for (; idx <= n; idx += idx & -idx) bit[idx] += val;
    }

    // agrega val al rango [l..r]
    void range_update(int l, int r, long long val) {
        add(bit1, l, val);
        add(bit1, r+1, -val);
        add(bit2, l, val * (l-1));
        add(bit2, r+1, -val * r);
    }

    long long sum(vector<long long>& bit, int idx) {
        long long res = 0;
        for (; idx > 0; idx -= idx & -idx) res += bit[idx];
        return res;
    }

    long long prefix_sum(int idx) {
        return sum(bit1, idx) * idx - sum(bit2, idx);
    }

    // suma en [l..r]
    long long range_query(int l, int r) {
        return prefix_sum(r) - prefix_sum(l-1);
    }
};

void so(int test){
        int n,q;
        cin >> n >> q;
        vi v(n+1);
        f(i,1,n+1)cin >> v[i];
        RangeFenwick ft(n+1);
        f(i,0,q){
                int op,l,r,pos;
                cin >> op;
                if(op == 1){
                        cin >> l >> r;
                        ft.range_update(l,r,1);
                }else{
                        cin >> pos;
                        int cant = ft.range_query(pos,pos);
                        string ga = to_string(v[pos]);
                        int co = 0;
                        while(co < cant and sz(ga) != 1){
                                int nu = 0;
                                for (auto dig :ga) {
                                        nu += dig - '0';
                                }
                                ga = to_string(nu);
                                co++;
                        }
                        cout << ga << ln;
                }
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
