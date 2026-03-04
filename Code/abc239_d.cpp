#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        int n,m;
        cin >> n >> m;
        int inf = (1<<30);
        vector<int> v(n+1,inf);
        int led = -1;
        int mi = 0;
        forn(i,m){
                int x;
                cin >> x;
                if(v[x] == inf){
                        v[x] = 1;
                }else{
                        v[x]++;
                }
                if(v[x] == mi){
                        led = min(led,x);
                }else if(v[x] > mi){
                        mi = v[x];
                        led = x;
                }
                cout << led << '\n';
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


