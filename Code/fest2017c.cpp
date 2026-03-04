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

void so(int test){
        int h,w;
        cin >> h >> w;
        vi fre(26,0);
        vector<string> v(h);
        forn(i,h){
                cin >> v[i];
                forn(j,w){
                        fre[v[i][j] - 'a']++;
                }
        }
        int h_ = h/2,w_ = w/2;
        int cnt = h_*w_;
        forn(i,26){
                int gru = fre[i]/4;
                int uwu = min(gru,cnt);
                cnt -= uwu;
                fre[i] -= uwu*4;
        }
        if(cnt){
                cout << "No\n";
                return;
        }
        int im = (h&1) + (w&1);
        int co = 0;
        forn(i,26){
                if(fre[i]&1){
                        co++;
                        if(co > im){
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
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


