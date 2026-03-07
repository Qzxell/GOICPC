#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int,int>;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)
#define vi vector<int>

//#palomar

void so(int test){
	int n;
	cin >> n;
	vector<int> v(n),fre(n+1,0);
	forn(i,n)
		cin >> v[i],fre[v[i]]++;
	int lo = 0, lf = n + 5, mid;

	priority_queue<ii> s,aux;
	int id = 0; 
	forn(i,n+1)if(fre[i])
		s.push({fre[i],id++});

	auto f = [&](int mid)->bool{
		aux = s;
		vi pos(n+1,-1);//position of if
		queue<ii> ban;//fre,id
		forn(i,n){
			while(!ban.empty()){
				auto [cn,id] = ban.front();
				if(i - pos[id] - 1 >= mid){
					ban.pop();
					aux.push({cn,id});
				}else break;
			}
			if(!aux.empty()){
				auto [cn,id] = aux.top();
				aux.pop();
				pos[id] = i;
				if(cn > 1)
					ban.push({cn-1,id});
			}else return false;
		}
		return true;
	};

	while(lf - lo > 1){
		mid = (lo + lf)/2;
		if(f(mid))lo = mid;
		else lf = mid;
	}
	cout << lo << '\n';
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



