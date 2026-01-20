#include<bits/stdc++.h>

using namespace std;

void so(){
        int n;
        cin >> n;
        vector<int> pa,tre,ot;
        for(int i = 1; i <= n ;i++){
                if(i % 2 == 0){
                        pa.push_back(i);
                }else if(i % 3 == 0){
                        tre.push_back(i);
                }else{
                        ot.push_back(i);
                }
        }
        int a,b;
        while(!ot.empty()){
                int fr = ot.back();ot.pop_back();
                if(pa.size() >= 2){
                        a = pa.back();pa.pop_back();
                        b = pa.back();pa.pop_back();
                        cout << a << ' ' << b << ' ' << fr << ' ';
                        continue;
                }
                if(tre.size() >= 2){
                        a = tre.back();tre.pop_back();
                        b = tre.back();tre.pop_back();
                        cout << a << ' ' << b << ' ' << fr << ' ';
                        continue;
                }
                cout << fr << ' ';
        }
        for(auto x : pa)cout << x << ' ';
        for(auto x : tre)cout << x << ' ';
        cout << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
