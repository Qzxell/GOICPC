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

void so(int test){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vi ans;
	for(auto x : s){
		if(x == '0' or x == '1')continue;
		if(x == '4'){
			ans.push_back(2);
			ans.push_back(2);
			ans.push_back(3);
			continue;
		}
		if(x == '9'){
			ans.push_back(7);
			ans.push_back(2);
			ans.push_back(3);
			ans.push_back(3);
			continue;
		}
		if(x == '6'){
			ans.push_back(5);
			ans.push_back(3);
			continue;
		}
		if(x == '8'){
			ans.push_back(2);
			ans.push_back(2);
			ans.push_back(2);
			ans.push_back(7);
			continue;
		}
		ans.push_back(x-'0');
	}
	sort(rall(ans));
	for(auto x : ans){
		cout << x ;
	}
	cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}
