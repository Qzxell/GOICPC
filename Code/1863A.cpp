#include<bits/stdc++.h>

using namespace std;

void so(){
        int n,a,q;
        cin >> n >> a >> q;
        string s;
        cin >> s;
        if(a == n){
                cout << "YES\n";
                return;
        }
        int temp = a;
        int del = 0;
        for(int i = 0 ; i < q;i++){
                if(s[i] == '-'){
                        del++;
                }else{
                        temp++;
                        if(del > 0){
                                del--;
                        }else{
                                a++;
                        }
                }
        }
        if(a == n){
                cout << "YES\n";
                return;
        }
        if(temp >= n){
                cout << "MAYBE\n";
                return;
        }
        cout << "NO\n";
}
int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
