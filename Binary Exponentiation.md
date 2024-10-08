is calculate $a^n$ in $O(\log n)$ , the idea is :
$$
3^{13} = 3^{1101_2} =3^8 \cdot 3^4 \cdot 3^1 
$$
### La idea recursiva
$$
f(n) =
\begin{cases} 
1 & \text{si } n = 0 \\
(a^{\frac{n}{2}})^2  & \text{si } n > 0 \text{ and } n \text{ par}\\
(a^{\frac{n-1}{2}})^2\cdot a  & \text{si } n > 0 \text{ and } n \text{ impar}\\
 \end{cases}
$$
code :
```c++
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}
```
### Segundo enfoque

El segundo enfoque realiza la misma tarea sin recursión. Calcula todas las potencias en un bucle y multiplica las que tienen el bit correspondiente en $n$ . Aunque la complejidad de ambos enfoques es idéntica, este enfoque será más rápido en la práctica ya que no tenemos la sobrecarga de las llamadas recursivas.
code : 
```c++
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
```
