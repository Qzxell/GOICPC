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
	int n;
	cin >> n;
	string s;
	cin >> s;
	string a = s;
	sort(all(a));
	if(a[0] == a[n-1]){
		cout << 1 << '\n';
		return;
	}
	int co = 0;
	char prev = '-';
	vi uwu;
	forn(i,n){
		if(s[i] == prev){
			co++;
		}else{
			if(co > 0)uwu.push_back(co);
			co = 1;
		}
		prev = s[i];
	}
	uwu.push_back(co);
	sort(all(uwu));
	if(uwu.back() == 1){
		cout << sz(uwu) << '\n';
		return;
	}
	cout << sz(uwu) + 1 - (s[0] == s[n-1])<< '\n';

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

