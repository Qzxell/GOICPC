#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        ll a,b;
        cin >> a >> b;
        ll cnt = b- a + 1;
        ll ans = 0;
        forn(i,50){
                if(i == 0){
                        ll uwu = (b+1)/2 - a/2;
                        ans = (uwu&1);
                        continue;
                }
                ll d1 = 0, d2 = 0;
                if((a>>i)&1){
                        d1 = (1ll<<(i+1)) - (a & ((1ll<<(i+1))-1)) ;
                }
                if(d1 >= cnt){
                        ans |= ((cnt&1ll)<<i);
                        continue;
                }
                if((b>>i)&1){
                        d2 = (b&((1ll<<(i+1))-1)) - (1ll<<i) + 1;
                }
                if(d2 >= cnt){
                        ans |= ((cnt&1ll)<<i);
                        continue;
                }
                if(d1 + d2 <= cnt){
                        ans |= (((d1+d2)&1ll)<<i);
                }else{
                        if(d1 == d2){
                                ans |= ((d1&1ll)<<i);
                        }else{
                                assert(false);
                        }
                }
        }
        cout << ans ;
}


int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


