"""
tarea1
kevin yavari yoshioka
"""


#punto 1

def verificarDiagonales(matriz):
    ans = True
    m = 0
    d = -1
    while m < len(matriz) and ans == True:
        if matriz[m][m] == matriz[m][d]:
            m += 1
            d -= 1
        else:
            ans = False
    return ans 

#punto 2

def esCapicua(listaCapicua):
    ans = True
    if len(listaCapicua) % 2 == 0:
        i = 0
        contador = 0
        x = 0
        while i < (len(listaCapicua)//2) and ans == True:
            x -= 1
            if listaCapicua[i] == listaCapicua[x]:
                i += 1
            else:
                ans = False
    else:
        ans = False
    return ans

#punto 3

#a)
def diferenciaListas(lista1,lista2):
    lista3 = []
    for i in range(len(lista1)):
        m = 0
        x = False   
        if lista1[i] in lista2:
            while m < len(lista2) and x == False:
                if lista1[i] == lista2[m]:
                    x = True
                    lista2.pop(m)
                else:
                    m += 1
        else:
            lista3.append(lista1[i])
    return lista3

#b)
def leerImprimir():
    x = int(input())
    f = []
    for i in range(x):
        lista1 = []
        lista2 = []
        d = input()
        s = input()
        d = d.split(" ")
        s = s.split(" ")
        for i in range(1,len(d)):
            lista1.append(int(d[i]))
        for i in range(1,len(s)):
            lista2.append(int(s[i]))
        lista3 = diferenciaListas(lista1,lista2)
        for i in range(len(lista3)-1):
            print("%d, "%(lista3[i]), end="")
        print(lista3[-1])
        

#punto 4

def esPrimo(i):
    x = False
    if i == 2 or i == 3 or i == 5 or i == 7:
        x = True
    else:
        if i%2 == 0 or i%3 == 0 or i%5 == 0 or i%7 == 0:
            x = False
        else:
            x = True
    return x

def sumarDigitos(l):
    contador = 0
    i = l
    while i > 0:
        contador += 1
        i = i//10
    k = 0
    x = 10
    z = 1
    for i in range(contador):
        k += (l % x)// z
        x *= 10
        z *= 10
    f = esPrimo(k)
    return f

def mostrarPrimos(n):
    print("Números primos entre 1 y %d:"%(n))
    x = True
    lista = []
    for i in range(2,n):
        x = esPrimo(i)
        if x == True:
            lista.append(i)
    for s in range(len(lista)-1):
        print("--> %d,"%(lista[s]))
    print("--> %d"%(lista[s+1]))
    print("")
    print("Números entre 1 y %d con suma de dígitos con valor primo:"%(n))
    lista2 = []
    for i in range(len(lista)):
        c = True
        c = sumarDigitos(lista[i])
        if c == True:
            lista2.append(lista[i])
    for j in range(len(lista2)-1):
        print("%d, "%(lista2[j]),end="")
    print(lista2[j+1])
            
#punto 5          

def sumarValoresMatriz(disp,lista):
    k = 0
    for i in range(len(lista)):
        if lista[i][0] in disp:
            m = 0
            flag = True
            while m < len(disp[lista[i][0]]) and flag == True:
                if lista[i][1] == disp[lista[i][0]][m][0]:
                    k += disp[lista[i][0]][m][1]
                    flag = False
                m +=1
    return k
                









    
