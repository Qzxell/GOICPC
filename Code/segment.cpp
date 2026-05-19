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
	int fi_m;
	int se_m;
	int cn_one;
	int cn_se;
};

const ll INF = 1e18;

struct segtree{
	int tam;
	vector<node> T ;
	node NEUTRO = {-1,-1,0,0};
	segtree(vi &v){
		tam = sz(v);
		T.resize(4*tam + 5, NEUTRO);
		build(v, 1 , 1, tam);
	}
	node merge(node a, node b){
		node ret;
		vii gru;
		gru.push_back({a.fi_m,a.cn_one});
		gru.push_back({a.se_m,a.cn_se});
		gru.push_back({b.fi_m,b.cn_one});
		gru.push_back({b.se_m,b.cn_se});
		sort(all(gru));
		reverse(all(gru));
		if(gru[0].fi != gru[1].fi){
			ret.fi_m = gru[0].fi;
			ret.cn_one = gru[0].se;
			if(gru[1].fi != gru[2].fi){
				ret.se_m = gru[1].fi;
				ret.cn_se = gru[1].se;
			}else{
				ret.se_m = gru[1].fi;
				ret.cn_se = gru[1].se + gru[2].se;
			}
		}else{
			ret.fi_m = gru[0].fi;
			ret.cn_one = gru[0].se + gru[1].se;
			if(gru[2].fi != gru[3].fi){
				ret.se_m = gru[2].fi;
				ret.cn_se = gru[2].se;
			}else{
				ret.se_m = gru[2].fi;
				ret.cn_se = gru[2].se + gru[3].se;
			}
		}
		return ret;
	}

	void build(vi &v,int nod , int l, int r){
		if(l == r){
			T[nod] = {v[l-1],-1,1,0};
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
			T[nod] = {val,-1,1,0};
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
	cin >> n >> q;
	vi v(n);
	forn(i,n)
		cin >> v[i];
	segtree st(v);
	forn(i,q){
		int op, l,  r, p, x;
		cin >> op;
		if(op == 1){
			cin >> p >> x;
			st.updt(p,x);
		}else{
			cin >> l >> r;
			cout << st.query(l,r).cn_se << '\n';
		}
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
