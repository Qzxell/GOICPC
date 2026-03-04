#include<bits/stdc++.h>
using namespace std;

void so(){
    int n;
    cin >> n;
    int ans = n/4 + (n%4 > 0 ?  1 : 0);
    cout << ans << '\n';
}
int main(){
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}
