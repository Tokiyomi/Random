# -*- coding: utf-8 -*-
"""
Created on Sun Jul 14 18:14:45 2019

@author: monic
"""


import turtle

turtle.shape("turtle")

def snow(lado, nivel): 
    """
    Funcion que traza un lado del triangulo base con sus respectivos triangulos
    Args:
        lado: medida del triagulo original
        nivel: número de niveles de triángulos 
    """
    if nivel==0: #Caso base: Cuando es solo un triángulo
        turtle.forward(lado)
        return
    else:
        lado=lado/3 #Cada tercera parte de lado, se crea un triangulo
        snow(lado, nivel-1) #Avanza recto un tercio de lado
        turtle.left(60) #Giro a la izquierda 60° (hacia arriba para trazar el otro triangulo)
        snow(lado,nivel-1) #Avanza recto un tercio de lado
        turtle.right(120) #Giro a la derecha 120° (para regresar)
        snow(lado,nivel-1) #Avanza recto un tercio de lado
        turtle.left(60) #Posiciona a la tortuga a como inició su recorrido en el triangulo anterior
        snow(lado,nivel-1) #Avanza el último tercio de lado para terminar


for lado in range(3): #Ya que la funcion grafica por cada lado del triangulo, se hace 3 veces.
    snow(200,4)
    turtle.right(120) #Girar para el próximo lado
    
turtle.exitonclick()
