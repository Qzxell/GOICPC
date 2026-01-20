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
        int n,c;
        cin >> n >> c;

        vi v(n);
        vi fre(c+1,0);
        vi ps(c+1,1);
        forn(i,n)cin >> v[i],fre[v[i]] = 1;
        forsn(i,1,c+1)
                ps[i] = ps[i-1] + fre[i];

        forsn(i,1,c+1)if(fre[i]){
                for(int j = 1 ; j*1ll*i <= c ; ++j){
                        if(ps[min((j+1)*i - 1,c)] - ps[i*j-1] > 0 and fre[j] == 0){
                                cout << "No\n";
                                return;
                        }
                }
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


