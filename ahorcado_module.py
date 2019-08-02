# -*- coding: utf-8 -*-
"""
Created on Tue Jul  2 09:21:28 2019

@author: monic
"""

#Ahorcado functions
import random
    
#Welcome message
def welcome():
    """
    Prints a welcoming message, either recieves parameters nor returns something. Just prints
    
    """
    print("...Bienvenido, vamos a jugar ahorcado...")
    print("\nLas reglas son:\n\tIntroducir un caracter a la vez.\n\tDebe ser una letra del alfabeto.\n\tDe no cumplir alguna de estas reglas, se te restará 1 de vida.")
    
#Lista de palabras secretas
def secret_words():
    """
    Generates a secret words list. No parameters.
    
    Returns:
        A word list.
    
    """
    word_list = ["Awkward","Bagpipes","Banjo","Bungler","Croquet","Crypt","Dwarves","Fervid","Fishhook","Fjord","Gazebo","Gypsy","Haiku","Haphazard","Hyphen","Ivory","Jazzy","Jiffy","Jinx","Jukebox","Kayak","Kiosk","Klutz","Memento","Mystify","Numbskull","Ostracize","Oxygen","Pajama","Phlegm","Pixel","Polka","Quad","Quip","Rhythmic","Rogue","Sphinx","Squawk","Swivel","Toady","Twelfth","Unzip","Waxy","Wildebeest","Yacht","Zealous","Zigzag","Zippy","Zombie"]
    word_list=((' '.join(word_list)).lower()).split() #Poner todo a minúscula
    return word_list

#Choice a word from the secret words list
def random_word(secret_words):
    """
    Selects a random word from the secret words list
    
    Arg:
        secret_words: A list of words to be chosen
        
    Returns:
        palabra: A word string which will be the secret word
        
    """
    palabra= random.choice(secret_words)
    return palabra

#Print lista de asteriscos inicial
def init_asteriscos(palabra):
    """
    Prints a string of '*' with the same lenght of the secret word
    
    Arg:
        palabra: a word string from the secret words list
        
    Returns:
        lista: a list of '*' with the same length of palabra
    """
    lista=['*' for i in range(len(palabra))]
    print("\nTu palabra tiene {0} letras".format(len(palabra)))
    print(''.join(lista))
    return lista

#Print life_counter
def life_counter_status(life_counter):
    """
    Prints the current life counter status
    
    Arg:
        life_counter: an integer which represents your number of lives
        
    Returns:
        A printed life_counter status
    """
    if life_counter!=1:
        print("\nTienes {0} vidas".format(life_counter))
    else:
        print("\nTienes {0} vida".format(life_counter))
    

#Pedir una letra
def letter():
    """
    Gets a letter from the user.
    
    Returns:
        letra: an alphabetic character
    """
    #Pedir la letra
    letra=str(input("Escribe una letra: "))
    letra=letra.lower() #Pasarla a minuscula por cualquier cosa
    return letra

#Game
def game(life_counter, palabra, lista, letra):
    """
    It's the game stage, evaluates if the introduced character is in a correct format
    
    Args:
        life_counter: an integer which represents your current number of lifes
        palabra: a word string from the secret words list
        lista: a list of '*' with the same leght of palabra
        letra: a character from the user
        
    Returns:
        life_counter: an integer which represents the new current life after evaluating
        if the introduced letter was in a correct format
        
    """
    #Evaluar si efectivamente es un solo caracter alfabético
    if  len(letra)>1 or len(letra)==0:
        print("\t\nOJO. Introduciste más de un caracter o ninguno.\nDebes escribir un caracter a la vez. (-1 de vida)\n")
        life_counter=life_counter - 1
    elif letra.isalpha()==False:
        print("\t\nOJO. Introduciste un caracter que no pertenece al alfabeto. (-1 de vida)\n")
        life_counter=life_counter - 1
    elif letra not in palabra:
        print("Esa letra no está en la palabra. (-1 de vida)\n")
        life_counter=life_counter - 1
    else:
        print("¡Bien!") #Si acierta, imprime esto y no quita vida
        #Reemplazar los asteriscos por los caracteres ya hallados que esten en la palabra
        for index in range(len(palabra)):
            if letra==palabra[index]:
                lista[index]=letra
                
    print(''.join(lista)) #Imprimir el avance
    return life_counter

#Win or loss
def win(lista, palabra, descubiertas):
    """
    Asigns a boolean value of True if the user guess the secret word
    
    Args:
        lista: a list of '*'
        palabra: a word string from the secret words list
        descubiertas: a list of previewed discovered words if the user played before
    Returns:
        True: if the user guess before lossing all his lives
    """
    if '*' not in lista: #Si adivina antes de gastar sus oportunidades, gana
        print("\n\nHaz ganado, la palabra es: {0}\n¡Felicidades!".format(palabra))
        if palabra not in descubiertas:
            descubiertas.append(palabra) #Si es la primera vez que la descubre, añadirla a la lista
        return True #Si ya ganó, salir del loop
                
def loss(lista):
    """
    Prints a message if in "lista" remains '*'
    
    Args:
        lista: a list of '*'
        
    Returns:
        a printed message of defeat
    """
    if '*' in lista:
        print("\n\nPerdiste. :c")

#Palabras descubiertas
def descubiertas(lista_descubiertas, palabra):
    """
    Prints clues if the user have guessed the secret word before
    
    Args:
        lista_descubiertas: an empty or not guessed word list
        palabra: a word from the secret words list
        
    Returns:
        lista_descubiertas: the same list with a new, or any, word 
    """
    if palabra in lista_descubiertas:
           print("\n\t>>PISTA. Ya has adivinado antes esta palabra<<") #Si ya la descubrió anteriormente, darle una pista
    if len(lista_descubiertas)>0:
            print("\nTus palabras descubiertas hasta el momento son las siguientes:\n{0}".format(' '.join(lista_descubiertas)))
    return lista_descubiertas
        
#Despedida
def goodbye():
    """
    Asks to the user if he wants to keep playing
    
    Returns:
        True: if the user wants to keep playing
        False: if the user does not want to play any more
    """
    try:
        status=int(input("Jugar de nuevo?\t\nSI:presiona 1\t\nNO:presiona 0\n"))
        if status==1:
            return True
        elif status==0:
            print("\nHasta pronto...")
            return False
        else:
            print("No entendí tu respuesta, hazlo de nuevo:")
            return goodbye()
    except:
        print("No entendí tu respuesta, hazlo de nuevo:")
        return goodbye()
        

