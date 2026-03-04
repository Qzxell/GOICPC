#include<bits/stdc++.h>

using namespace std;

#define ll long long

void so(){
        ll k,x;
        cin >> k >> x;
        ll r1 = (k*(k+1))/2 ;
        ll r2 = (k*(k-1))/2 ;
        ll su = r1 + r2;
        if(su <= x){
                cout << k+k-1 << '\n';
                return;
        }
        if(r1 >= x){
                int lo,lf,mid;
                lo = 1,lf = k;
                while(lo < lf){
                        mid = (1 +lo + lf)/2;
                        if(x - (mid*1ll*(mid-1))/2 > 0){
                                lo = mid;
                        }else lf = mid - 1;
                }
                cout << lo << '\n';
                return;
        }
        x -= r1;
        int lo,lf,mid;
        lo = 1,lf = k-1;
        while(lo < lf){
                mid = (lo + lf )/2;
                if(x - (r2 - (mid*1ll*(mid+1))/2) > 0 ){
                        lf = mid;
                }else lo = mid + 1;
        }
        cout << k - lo + k << '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--){
                so();
        }
        return 0;
}

