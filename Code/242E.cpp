#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

struct node{
	long long sum = 0;
	vector<int> mask;
	node(){
		mask.assign(22,0);
	}
	node(int num){
		sum = num;
		mask.assign(22,0);
		for(int i = 0 ; i < 22; i++)
			mask[i] += ((num >> i)&1);
	}
};

node T[4*N + 5];
int lz[4*N + 5];
int arr[N];
node e = node(0);


node comb(node a,node b){
	node c;
	c.sum = a.sum + b.sum;
	for(int i = 0 ; i < 22; i++)
		c.mask[i] = a.mask[i] + b.mask[i];
        return c;
}

void apply(int v,int val, int len){
        for(int i = 0 ; i < 22; i++) if((val>>i)&1){
		long long ori = T[v].mask[i];
		T[v].mask[i] -= len;
		T[v].mask[i] *= -1;
		long long fin = T[v].mask[i];
		T[v].sum -= ori*(1<<i);
		T[v].sum += fin*(1<<i);
        }
        lz[v] ^= val;
}

void push(int v,int l, int r){
        if(lz[v] == 0)return;
        int mid = (l + r)>> 1;
        int l_len = mid - l + 1;
        int r_len = r - mid;

        apply(2*v, lz[v], l_len);
        apply(2*v + 1 , lz[v], r_len);
        
        lz[v] = 0;
}

void build(int v, int l ,int r){
	if(l == r){
		node uwu(arr[r]);
		T[v] = uwu;
		return;
	}

        int mid = (l + r) >> 1;
        build(2*v, l, mid);
        build(2*v + 1, mid + 1, r);
        T[v] = comb(T[2*v] , T[2*v + 1]);
}

void updt(int l,int r,int val, int v, int l_c ,int r_c){
        if(r < l_c || l > r_c)return;
        if(l <= l_c && r_c <= r){
                apply(v,val,r_c - l_c + 1);
                return;
        }

        push(v,l_c, r_c);

        int mid = (l_c + r_c) >> 1;
        updt(l, r, val , 2*v + 0, l_c, mid);
        updt(l, r, val , 2*v + 1, mid + 1, r_c);
        T[v] = comb(T[2*v] , T[2*v + 1]);
}

node query(int l,int r, int v, int l_c ,int r_c){
        if(r < l_c || l > r_c)return e;
        if(l_c >= l && r_c <= r)
                return T[v];

        push(v, l_c ,r_c);

        int mid = (l_c + r_c) >> 1;
        node v1 = query(l, r , 2*v + 0, l_c, mid);
        node v2 = query(l, r , 2*v + 1, mid + 1, r_c);
        return comb(v1,v2);
}

void so(){
	int n;
	cin >> n;
	for(int i = 1 ; i <= n;i++)
		cin >> arr[i];
	build(1,1,n);
	int q;
	cin >> q;
	for(int i = 0; i < q;i++){
		int op,l,r,x;
		cin >> op;
		if( op == 1){
			cin >> l>> r;
			long long ans = query(l,r, 1, 1, n).sum;
			cout << ans << '\n';
		}else{
			cin >> l >> r >> x;
			updt(l,r,x, 1, 1, n);
		}
	}

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
	so();
        return 0;
}
