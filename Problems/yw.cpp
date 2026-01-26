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
        vi v(n);
        forn(i,n)v[i] = i + 1;
        do{
                bool yes = 1;
                forn(i,n-1){
                        bool ok = 0;
                        forsn(j,i,n){
                                if((v[j]^(i+1)) == v[i]){
                                        ok = 1;
                                        break;
                                }
                        }
                        if(!ok){
                                yes = 0;
                                break;
                        }
                }
                if(yes){
                        forn(i,n)cout << v[i] << ' ';
                        cout << '\n';
                }
        }while(next_permutation(all(v)));
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
