#!/usr/bin/python
import sys
from time import time

def binarySearch(Arr, Buscado):
	TamArr=len(Arr)
	L=0
	R= TamArr-1
	encontrado=0
	salida=0
	while (salida==0):
		m= (L+R)/2
		if(Arr[m]<Buscado):
			L=m+1       

		if(Arr[m]>Buscado):
			R= m-1     
		
		if(Arr[m]==Buscado):
			encontrado=1 
			salida=1
			print "Se encontro: 1"
		
	
		if(L>R):
			salida=1;
			print  "Se encontro: 0"
def selectionSort(arr):
    for i in range(len(arr)):
        menor=arr[i]
        temp=arr[i]
        for j in range(i+1,len(arr)):
            if arr[j]<menor:
                menor=arr[j]
                pos=j
        if arr[i]!=menor:
            arr[i]=menor
            arr[pos]=temp
        

filename = sys.argv[3]
arr=[]
with open(filename) as file:
    for line in file:
        for element in line.split():
            arr.append( int(element))
print arr

Buscado = int(sys.argv[2]) 


tiempo_inicial = time()
if(sys.argv[1]=="BS"):
	binarySearch(arr,Buscado)
if(sys.argv[1]=="SS"):	
	selectionSort(arr)
	print arr
tiempo_final = time() 

tiempo_ejecucion = (tiempo_final - tiempo_inicial)*1000	
print 'El tiempo de ejecucion fue:',tiempo_ejecucion #En segundos




