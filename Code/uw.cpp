#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
	string s = "1234";
	auto ver = [&](int num)->bool{
		string k = to_string(num);
		for(auto x : k){
			bool ok = 0;
			for(auto pr : s){
				if ( pr == x)
					ok = 1;
			}
			if(!ok)return false;
		}
		return true;

	};
	ll cn = 0;
	for(int i = 10; i < 100 ;i++){
		if(ver(i)){
			cn += i;
			cout << i << '\n';
		}
	}
	cout << cn << '\n';
}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}



