#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Generador del Peor Caso: Un árbol 7-ario perfecto
    int t = 1;
    cout << t << "\n";
    
    vector<long long> a;
    // Creamos números en base mixta para engañar la poda del DFS
    for(int d0=0; d0<=6; d0++) {
        for(int d1=0; d1<=6; d1++) {
            for(int d2=0; d2<=6; d2++) {
                for(int d3=0; d3<=6; d3++) {
                    for(int d4=0; d4<=6; d4++) {
                        long long y = d0 + 42LL*d1 + 1764LL*d2 + 74088LL*d3 + 3111696LL*d4;
                        long long original_val = y * 6; // Para que cumplan mod 6
                        if(original_val > 0 && original_val <= 1000000000) {
                            a.push_back(original_val);
                        }
                    }
                }
            }
        }
    }
    
    // Limitamos a N = 100,000 (tamaño grande pero legal)
    int n = min(100000, (int)a.size());
    cout << n << "\n";
    for(int i=0; i<n; i++){
        cout << a[i] << (i==n-1 ? "" : " ");
    }
    cout << "\n";
    return 0;
}
