#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)

#define vi vector<int>
#define vl vector<ll>
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz(v) (int)(v).size()

struct node{
	ll pr;
	ll sf;
	ll seg;
	ll sum;
};

const ll INF = 1e18;

struct segtree{
	int tam;
	vector<node> T ;
	node NEUTRO = {-INF, -INF, -INF, 0};
	segtree(vi &v){
		tam = v.size();
		T.resize(4*tam + 5, NEUTRO);
		build(v, 1 , 1, tam);
	}
	node merge(node a, node b){
		node ret;
		ret.pr = max(a.pr, b.pr + a.sum);
		ret.sf = max(b.sf, a.sf + b.sum);
		ret.sum = a.sum + b.sum;
		ret.seg = max({a.seg,b.seg, a.sf + b.pr});
		return ret;
	}
	void build(vi &v,int nod , int l, int r){
		if(l == r){
			ll val = v[l-1];
			T[nod] = {val,val,val,v[l-1]};
			return;
		}
		int mid = (l + r)/2;
		build(v, 2*nod, l , mid);
		build(v, 2*nod + 1, mid + 1 , r);
		T[nod] = merge(T[2*nod], T[2*nod + 1]);
	}
	node query(int l, int r, int nod , int l_c, int r_c){
		if(l > r_c || r < l_c) return NEUTRO;
		if( r_c <= r && l <= l_c)return T[nod];
		int mid = (l_c + r_c) /2;
		node mi1 = query(l,r , 2*nod , l_c, mid);
		node mi2 = query(l,r , 2*nod + 1, mid + 1, r_c);
		return merge(mi1, mi2);
	}
	void updt(int pos, int val, int nod , int l_c, int r_c){
		if(pos < l_c || pos > r_c)return;
		if(l_c == r_c) {
			ll x = val;
			T[nod] = {x,x,x,x};
			return;
		}
		int mid = (l_c + r_c) /2;
		updt(pos, val, 2*nod , l_c, mid);
		updt(pos, val, 2*nod + 1, mid + 1, r_c);
		T[nod] = merge(T[2*nod], T[2*nod + 1]);
	}
	node query(int l, int r){
		return query(l, r, 1 , 1, tam);
	}
	void updt(int pos, int val){
		updt(pos, val, 1 , 1, tam);
	}

};

void so(int test){
	int n,q;
	cin >> n;
	vi v(n);
	forn(i,n)
		cin >> v[i];
	segtree ST(v);// 1 -index
	cin >> q;
	forn(i,q){
		int l,r;
		cin >> l >> r;
		cout << ST.query(l,r).seg << '\n';
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

