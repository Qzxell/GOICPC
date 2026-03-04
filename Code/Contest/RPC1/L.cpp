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

void so(int test){
	int n,q;
	cin >> n >> q;
	vector<array<int,3>> condi;
	forn(i,q){
		int op;char x,y;
		cin >> op >> x >> y;
		condi.push_back({op,x-'A',y-'A'});
	}
	vector<int> person(n);
	iota(all(person),0);

	vector<int> position(n);
	int ans = 0;
	do{
		forn(i,n)
			position[person[i]] = i;
		bool ok = 1;
		for(auto [op,x,y] : condi){
			if(op == 1 and position[x] > position[y]){
				ok = 0;
				break;
			}
			if(op == 2 and position[x] < position[y]){
				ok = 0;
				break;
			}
			if(op == 3 and abs(position[x] - position[y]) == 1){
				ok = 0;
				break;
			}
		}
		ans += ok;
	}while(next_permutation(all(person)));
	cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}

