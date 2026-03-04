#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
const int INF = 1e9; // Un valor muy grande

int merge_and_find(vi& arr, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    vi L(n1), R(n2);

    for(int i=0; i<n1; i++) L[i] = arr[l + i];
    for(int j=0; j<n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = l;
    int local_min = INF;

    while (i < n1 && j < n2) {
        // Aquí ocurre la magia: comparamos elementos de ambos lados
        
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else{
                local_min = min(local_min, abs(L[i] - R[j]));
                arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
    
    return local_min;
}

int solve(vi& arr, int l, int r) {
    if (l >= r) return INF;

    int mid = l + (r - l) / 2;
    
    // Capturamos los mínimos de las profundidades
    int min_left = solve(arr, l, mid);
    int min_right = solve(arr, mid + 1, r);
    
    // Capturamos el mínimo de la combinación
    int min_merge = merge_and_find(arr, l, mid, r);

    return min(min(min_left, min_right), min_merge);
}

void so() {
    int n;
    if(!(cin >> n)) return;
    vi v(n);
    for(int i=0; i<n; i++) cin >> v[i]; // ¡Crucial! Leer los datos
    
    cout << solve(v, 0, n-1) << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while(tt--) so();
    return 0;
}
