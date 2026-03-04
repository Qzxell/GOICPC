#include<bits/stdc++.h>

using namespace std;

void so(){
        int n,k,x;
        cin >> n >> k;
        vector<int> uwu(n+3,0);
        for(int i = 0 ; i < n ; i++){
                cin >> x;
                uwu[1]++;
                uwu[x/4 + 1]--;
                if(x%3 == 0){
                        uwu[x/3]++;
                        uwu[x/3 + 1]--;
                }
                if(x%2 == 0){
                        uwu[x/2]++;
                        uwu[x/2 + 1]--;
                }
                uwu[x]++;
                uwu[x+1]--;
        }
        for(int i = 1; i <= n + 1; i++)uwu[i] += uwu[i-1];
        //cout << "-=----===============\n";
        //for(int i = 1; i <= n + 1; i++)cout << uwu[i] << ' ';
        //cout << '\n';
        for(int i = n ; i >= 1; i--){
                if(uwu[i] >= n - k ){
                        cout << i << '\n';
                        return;
                }
        }
        assert(false);
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
