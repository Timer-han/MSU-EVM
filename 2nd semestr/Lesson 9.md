# Битовые операции

Бит - минимальный набор информации

# 1 БАЙТ
```

.  ________    ________    ________    ________  
. /        \  /        \  /        \  /        \ 
.|   ____   ||   ____   ||   ____   ||   ____   |
.|   \  /   ||   \  /   ||   \  /   ||   \  /   |
. \   ||   /  \   ||   /  \   ||   /  \   ||   / 
.  \  ||  /    \  ||  /    \  ||  /    \  ||  /  
.   \_||_/      \_||_/      \_||_/      \_||_/   
.    |--|        |--|        |--|        |--|    
.    |--|        |--|        |--|        |--|    
.    
.  ________    ________    ________    ________  
. /        \  /        \  /        \  /        \ 
.|   ____   ||   ____   ||   ____   ||   ____   |
.|   \  /   ||   \  /   ||   \  /   ||   \  /   |
. \   ||   /  \   ||   /  \   ||   /  \   ||   / 
.  \  ||  /    \  ||  /    \  ||  /    \  ||  /  
.   \_||_/      \_||_/      \_||_/      \_||_/   
.    |--|        |--|        |--|        |--|    
.    |--|        |--|        |--|        |--|    
    
```
# побитовые операции
a = 11001011
b = 01101110
x = 00101110
x >> 1 = 00010111 = x / 2
x << 1 = 01011100 = x * 2
a | b = 11101111
a & b = 00100100
~a = 00110100
a ^ b = 10100101

x * 17 = x * (16 + 1) = x >> 4 + x

## Заменить 5 бит с конца на 1
a | (1 << 5)

## Заменить 4 бит на 0
a & (~(1 << 4))

## Заменить на противоположный 3 бит 
a ^ (1 << 3)

### Все битовые операции работают только с unsigned типом!!!

## Отрицательные числа
```

00000000
-
00000001
=
11111111
Это -1

11111111
-
00000001
=
11111110
Это -2
```
Все правила сохраняются:
x << 2 = x * 4
x >> 2 = x / 4