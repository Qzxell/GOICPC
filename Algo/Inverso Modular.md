
Se tiene como modulo a un numero primo p:
$$
x^{-1}\mod p = Inv(x) = binpow(x,p-2)
$$
Si tengo $Inv(x!)$ Puedo hallar $Inv((x+1)!)$ ?

$$
x! \cdot x!^{-1} = 1 \mod p
$$
Si multiplico $x+1$ en ambos lados
$$
(x+1)! \cdot x!^{-1} = x+1 \mod p
$$
De modo que multiplicando $Inv(x+1)$ en ambos lados te queda
$$
(x+1)!\cdot x!^{-1} \cdot Inv(x+1) = 1 \mod p $$
Entonces
> [!IMPORTANT]
> $$ (x+1)!^{-1} = x!^{-1}\cdot Inv(x+1)$$

## Como tengo $Inv(x)$ con precalculaciones pasadas

$$
p = \lfloor p/i \rfloor \cdot i + (p \mod i)
$$
Queda 
$$
0 \mod p =  \lfloor p/i \rfloor \cdot i + r
$$
$$
r =  -\lfloor p/i \rfloor \cdot i
$$
$$1 \mod p = r^{-1} \cdot -\lfloor p/i \rfloor \cdot i$$$$i^{-1} \mod p = r^{-1} \cdot -\lfloor p/i \rfloor $$