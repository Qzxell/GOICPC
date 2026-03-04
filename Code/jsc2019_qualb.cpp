#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

const int mod = 1e9 + 7;
int ad(int a, int b){
        return (a+0ll+b)%mod;
}
int mul(int a, int b){
        return a*1ll*b%mod;
}

void so(int test){
        int n,k;
        cin >> n >> k;
        int a[n];
        int tam = 2001;
        vector<int> fre(tam,0);
        forn(i,n)cin >> a[i],fre[a[i]]++;

        ll ans = 0;
        forn(i,n)
        forsn(j,i+1,n)
        {
                int co = 0;
                if(a[i] > a[j]){
                        co++;
                }
                ans = ad(ans,mul(co,k));
        }
        int acu = 0;
        ll uwu = (((k-1)*1ll*k)/2)%mod;
        for(int i = tam-1 ; i >= 0; i--){
                ans = ad(ans,mul(mul(fre[i],acu),uwu));
                acu += fre[i];
        }
        cout << ans << '\n';

}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


