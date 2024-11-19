
# problem

- por cada query te dan una terna que representa un rango y un k, tienes que responder

# fenwik tree

- para cada i hasta donde se nesecita guardar un valor? -> para cada i del vector guardamos una suma acumulada hacia atras, desde i- g(i) hasta i, este g(i) = es la potencia del bit menos significativo prendido

g(i) = i & (i-1)

sea x positivo

bitset (-x) = ~bitset(x-1)

entonces g(i) = i & (i-1)

- updatear desde l hasta r
- calcular la suma desde l hasta r

```cpp
const int ga = 1e5+1;
vector<int> ft(ga, 0);
void update(int pos,int add){ //sumo a[pos] += add
  for(++pos;pos<ga;pos+=pos&-pos){
    ft[pos] += add ;
  }
}
int sum(int pos){ //retorna la suma de a[0:pos]
  int ans=0;
  for(++pos;pos>0;pos&=pos-1) ans+=ft[pos];
  return ans;
}

```

## subproblema: hallar el vector despues de k updates desde un l hasta un r

- prefix sum del inverso del prefix sum de s = s .

si se modifica el i del inverso del prefix sum se modificara para todo el vector desde i hasta n.

- https://www.spoj.com/problems/KQUERY/