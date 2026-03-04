#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "aaba";
    int n,k;
    cin >> n >> k;
    cin >> s;
    sort(s.begin(),s.end());
    int ans = 0;
    do {
        bool cont = 1;
        for (int i = 0; i <= n - k; ++i) {
            bool pali = 1;
            for (int j = 0;j < k/2; ++j) {
                if (s[i+j] != s[i + k-1 -j]) {
                    pali = 0; 
                    break;
                }     
            } 
            if (pali) {
                cont = 0;
                break;
            }
        }  
        if (cont) {
           ans++; 
        }
    } while (next_permutation(s.begin(),s.end()));
    cout << ans ;

    return 0;
}


