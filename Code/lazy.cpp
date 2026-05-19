#include<bits/stdc++.h>

using namespace std;

#define ll long long

struct segtree{
	int n;
	vector<ll> T;
	vector<int> lazy;
	segtree (int nu){
		n = nu;
		T.resize(4*n);
		lazy.resize(4*n);
	}
	void compose(int v, int aum){
		lazy[v] += aum;
	}
	void apply(int v,int modi ,int l, int r){
		T[v] += modi * 1ll * (r - l + 1);
	}
	void push(int v,int l, int r){
		if(lazy[v] == 0)return;

		int mid = (l + r) >> 1;
		apply(2*v , l , mid);
		apply(2*v + 1, mid + 1 , r);

		compose(v * 2 , lazy[v]);
		compose(v * 2 + 1, lazy[v]);

		lazy[v] = 0;
	}
	// updt

	void updt(int l ,int r , int modi , int nod, int l_c, int r_c){
		if(l_c > r || r_c < l)return;
		if(l <= l_c && r_c <= r){
			lazy[nod] += modi;
			apply(nod,l_c,r_c);
			return;
		}

		push(nod, l_c , r_c);

		int mid = (l_c + r_c)/2;
		updt(l,r, modi, 2*nod , l_c, mid);
		updt(l,r, modi, 2*nod + 1, mid + 1, r_c);

		T[nod] = T[nod * 2] + T[nod * 2 + 1];
	}

	void updt(int l,int r,int modi){
		updt(l,r,modi, 1, 1,n);
	}

	// query
	ll query(int pos, int nod, int l_c, int r_c){
		if(l_c > pos || r_c < pos)return 0;
		if(l_c == pos && r_c == pos)
			return T[nod];

		int mid = (l_c + r_c)/2;
		push(nod, l_c, r_c);
		ll ret = 0;

		ret += query(pos, 2*nod, l_c , mid);
		ret += query(pos, 2*nod + 1, mid + 1 , r_c);
		return ret;
	}
	ll query(int pos){
		return query(pos,1,1,n);
	}
};


void so(){
	int n,q;
	cin >> n >> q;
	segtree st(n);
	for(int i = 0 ; i < q; i++){
		int op,l,r,va,pos;
		cin >> op;
		if( op == 1){//add
			cin >> l >> r >> va;
			l++;
			st.updt(l,r,va);
			//st.debug();
		}else{
			cin >> pos;
			pos++;
			cout << st.query(pos) << '\n';
		}
	}
}

int main(){
	so();
	return 0;
}

