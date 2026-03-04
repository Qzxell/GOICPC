---
rating: 
fecha_intento: 
estado: resuelto
---

## La Intuición (Explicado a un niño)


Para cada digito definimos 
$$ u_1 = l+..+r$$
$$ u_2 = r-l+1$$
>[!IMPORTANT] Mi primer error fue no considerar en el $u_2$ su exponente
$$Dig(j) = u_1.u_2^{j-1}.10^{j-1}$$
 $$
 F(lon) = \sum_{i=1}^{lon} Dig(i) = u_1 (\sum_{i=1}^{lon} (10.u_2 )^{j-1}) 
 $$

 $$
 F(lon + 1) = u_1 (\sum_{i=1}^{lon + 1} (10.u_2 )^{j-1}) 
 $$
 $$
 F(lon + 1) = u_1 (\sum_{i=1}^{lon} (10.u_2 )^{j-1} + (10.u_2)^{lon})) 
 $$
 $$
 F(i) = F(i-1) + u_1 (10.u_2)^{i-1}
 $$
 $$
 F(i+1) = F(i) + u_1 (10.u_2)^{i}
 $$

 >[!u] Mi matriz pasa a ser
 $$\begin{pmatrix}
F(i) & u_1(u_2.10)^{i-1} \\
F(i+1) & u_1(u_2.10)^i 
\end{pmatrix}
\cdot
\begin{pmatrix}
1 & 0 \\
u_2\cdot 10 & u_2\cdot 10 
\end{pmatrix} 
=
 \begin{pmatrix}
F(i+1) & u_1(u_2.10)^{i} \\
F(i+2) & u_1(u_2.10)^{i+1} 
\end{pmatrix}
$$

 >[!u] Mi Caso base 
 $$\begin{pmatrix}
F(1) & u_1 \\
F(2) & u_1.u_2.10 
\end{pmatrix}
\cdot
\begin{pmatrix}
1 & 0 \\
u_2\cdot 10 & u_2\cdot 10 
\end{pmatrix}^{k-1}
=
 \begin{pmatrix}
F(k) & u_1(u_2.10)^{k-1} \\
F(k+1) & u_1(u_2.10)^{k} 
\end{pmatrix}
$$

#### 2do error

MIERDAAAAAA!!

 >[!WARNING] Mi funcion esta mal
> $$Dig(j) = u_1.u_2^{j-1}.10^{j-1}$$
> - el $u_2^{j-1} :=$ significaba la cantidad por cada numero en este digito, **ERA CONSTANTE**, Porque?
> - En total hay $u_2^k$ numero que se forman entonces en cada digito habra $\dfrac{u_2^k }{ u_2}$
> - De forma que F pasa a ser :
> $$F(pos) = \sum_{i = 1}^{pos} deg(i) = u_1.u_2^{k-1}.\sum_{i=1}^{pos} 10^{i-1}$$


Finalmente tenemos 
$$ F(k) = u_1 . u_2^{k-1} . \dfrac{10^i}{9}$$

## Mi Bloqueo (¿Por qué no me sale?)

---
## El "Aja" (la idea clave)

**EN CADA DIGITO CUANTOS HAY DE CADA TIPO** si en total hay $b^k$

[[sub.cpp]]
#leetcode
