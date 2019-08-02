# -*- coding: utf-8 -*-
"""
Created on Tue Jul  2 09:54:29 2019

@author: monic
"""

import ahorcado_module as mod

#Mensaje de bienvenida
mod.welcome()

#Definir True como status inicial
flag=True

#Inicializar palabras descubiertas
descubiertas=[]

#Inicializar lista de palabras secretas
secret_words=mod.secret_words()

#Empezar a jugar mientras el estatus sea 1=True
while flag==True:
    
    #vidas iniciales
    vidas=5
    #Palabra aleatoria
    palabra=mod.random_word(secret_words)
    
    #Imprimir si ya hay palabras descubiertas
    mod.descubiertas(descubiertas, palabra)
    
    #Imprimir lista de asteriscos
    asteriscos=mod.init_asteriscos(palabra)
    
    #Imprimir contador de vidas
    mod.life_counter_status(vidas)
    
    #Jugar mientras las vidas sean mayores a 0
    while vidas>0:
        
        #Pedir una letra al usuario
        letra=mod.letter()
        
        #Ver si está o no en la pabra, quitar o no 1 de vida
        vidas=mod.game(vidas, palabra, asteriscos,letra)
        
        mod.life_counter_status(vidas) #Imprimir cuantas vidas le quedan
        
        #Evaluar si ya desaparecieron o no todos los asteriscos de la lista
        if mod.win(asteriscos, palabra, descubiertas)==True:
            break

    #Si se salió del loop y no desaparecieron todos los asteriscos
    mod.loss(asteriscos)
        
    #Preguntar si quiere jugar de nuevo
    flag=mod.goodbye()
    

    
