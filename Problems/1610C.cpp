#include<bits/stdc++.h>

using namespace std;

void so(){
        int n;
        cin >> n;
        int a[n],b[n];

        int cnt = 0;
        for(int i = 0; i < n ; i++){
                cin >> a[i] >> b[i];
        }
        int lo = 1, lf = n,mid;
        auto f = [&](int cant)->bool{
                int u = cant-1,v = 0;
                for(int i = 0 ; i < n ; i++){
                        if(a[i] >= u and b[i] >= v){
                                u--;v++;
                        }
                }
                return u < 0;
        };
        while(lo < lf){
                mid = (1+lo+ lf)/2;
                if(f(mid)){//vvvvvfff
                        lo = mid;
                }else{
                        lf = mid-1;
                }
        }
        cout << lo << '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
