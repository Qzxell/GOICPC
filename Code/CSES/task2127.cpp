#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	int n,m;
	cin >> n >> m;
	vi v(n),pos(n);
	for(int i = 0 ; i < n; i ++){
		cin >> v[i]; v[i]--;
		pos[v[i]] = i;
	}
	for(int i = 0 ; i < m; i++){
		int a,b;
		cin >> a >> b;
		int na = v[a-1];
		int nb = v[b-1];
		swap(v[a],v[b]);
		swap(pos[na],pos[nb]);

	}
	return 0;
}
