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

const int N = 1e6 + 5;
long long d[N];

void so(int test){
	int x;
	cin >> x;
	cout << d[x] << '\n';
}

void init(){
	for(int i = 1; i < N;i++){
		for(int j = i; j < N ; j += i){
			d[j]++;
		}
	}
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
	init();
        int test = 1;
	cin >> tt;
        while(tt--) so(test++);
        return 0;
}

