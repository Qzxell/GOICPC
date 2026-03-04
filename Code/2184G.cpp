#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct ST {
    int n;
    vector<ll> t;
    ll NEUT = LLONG_MAX; // 0 para SUM, INF para MIN, -INF para MAX

    ll oper(ll a, ll b) {
        return min(a,b); // Cambiar logica: min, max, gcd, etc.
    }

    ST(int sz) {
        n = sz;
        t.assign(4 * n, NEUT);
    }

    ST(const vector<ll>& a) {
        n = a.size();
        t.assign(4 * n, NEUT);
        init(1, 0, n - 1, a);
    }

    void init(int node, int l, int r, const vector<ll>& a) {
        if (l == r) {
            t[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        init(2 * node, l, mid, a);
        init(2 * node + 1, mid + 1, r, a);
        t[node] = oper(t[2 * node], t[2 * node + 1]);
    }

    void update(int p, ll val) {
        update(1, 0, n - 1, p, val);
    }

    void update(int node, int l, int r, int p, ll val) {
        if (l == r) {
            t[node] = val; // Ojo: a veces es t[node] += val
            return;
        }
        int mid = (l + r) / 2;
        if (p <= mid) update(2 * node, l, mid, p, val);
        else update(2 * node + 1, mid + 1, r, p, val);
        t[node] = oper(t[2 * node], t[2 * node + 1]);
    }

    ll query(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }

    ll query(int node, int l, int r, int i, int j) {
        if (l > j || r < i) return NEUT;
        if (l >= i && r <= j) return t[node];
        int mid = (l + r) / 2;
        return oper(query(2 * node, l, mid, i, j), query(2 * node + 1, mid + 1, r, i, j));
    }
};

void so(int test){
        int n,q;
        cin >> n >> q;
        vl v(n);
        forn(i,n)cin >> v[i];
        ST st(v);
        forn(i,q){
                int ty,l,r,pos,x;
                cin >> ty;
                if(ty == 1){
                        cin >> pos >> x;
                        pos--;
                        st.update(pos,x);
                }else{
                        cin >> l >> r;
                        l--;r--;
                        int lo = l, lf = r,mid,task,dis;
                        while(lo < lf){
                                mid = (lo+1+lf)/2;
                                task = st.query(l,mid);
                                dis = mid - l ;
                                if(task >= dis){
                                        lo = mid;
                                }else{
                                        lf = mid-1;
                                }
                        }
                        cout << (st.query(l,lo) <= lo - l? 1 : 0 ) << '\n';
                }

        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


