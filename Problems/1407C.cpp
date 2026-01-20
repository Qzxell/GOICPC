#include<bits/stdc++.h>

using namespace std;

using ll = long long;

int qr(int l,int r){
        int ret;
        cout << "? " << l << " " << r << '\n';
        cin >> ret;
        return ret;
}
void so(){
        int n = 5;;
        //cin >> n;
        vector<int> v(n);
        for(int i =0  ; i < n ;i++)v[i] = i+1;
        int co = 0;
        do{
                co++;
                for(int i = 0 ; i < n - 1;i++){
                        cout << v[i+1]%v[i] << ' ';
                }
                cout << '\n';
                if(co == 9)break;
        }while(next_permutation(v.begin(),v.end()));
}


int main(){
        so();
        return 0;
}
