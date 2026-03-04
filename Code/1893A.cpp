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

const int N = 2e5 + 5;
int b[N];
bool vis[N];

void so(int test){
	int n,k;
	cin >> n >> k;
	forn(i,n)cin >> b[i],vis[i] = 0;
	int ind = n - 1;
	forn(i,k){
		if(b[ind] > n){
			cout << "No\n";
			return;
		}
		if(vis[ind])break;
		vis[ind] = 1;
		ind -= b[ind];
		if(ind < 0 )ind += n;
	}
	cout << "Yes\n";
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
