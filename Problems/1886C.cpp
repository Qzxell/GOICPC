#include<bits/stdc++.h>

using namespace std;

#define ll long long

void so(){
        string s;
        cin >> s;
        ll pos,aux;
        cin >> pos;

        aux = pos;
        int bloq = 1;
        int lon = s.size();
        while(aux > lon){
                aux -= lon;
                bloq++;
                lon--;
        }
        //cout << "================" << '\n';
        //cout << bloq << ' ' << aux << '\n';
        stack<char> st;
        int gru = 1,ind = 0;
        while(gru < bloq){
                if(ind >= s.size())break;
                if(st.empty()){
                        st.push(s[ind]);
                        ind++;
                        continue;
                }
                char cur = s[ind];
                char fr = st.top();
                if(fr > cur){
                        st.pop();
                        gru++;
                }else{
                        st.push(cur);
                        ind++;
                }
        }
        string wasa;
        for(int i = ind ; i < s.size();i++)st.push(s[i]);
        while(!st.empty()){
                wasa += st.top();
                st.pop();
        }
        reverse(wasa.begin(),wasa.end());
        //cout << wasa << '\n';
        cout << wasa[aux-1] ;
        //cout << '\n';
}

int main(){
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
