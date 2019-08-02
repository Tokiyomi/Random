# -*- coding: utf-8 -*-
"""
Created on Sat Jun  8 01:07:16 2019

@author: monic
"""

def main():
    
    #Get the string
    string=str(input("Give me a string: "))
    
    #Apply lower case
    minus=string.lower()
    
    #Convert the string into a list
    string_list= minus.split()
    
    #For each element into the list, remove special characters from the string
    for index in range(0,len(string_list)):
        element_list=[char for char in string_list[index] if char.isalnum()==True]
        
        #Create a new string
        new_string=''.join(element_list)
        
        #Change the original element for the filtred one
        string_list[index]=new_string
    
    #Create a new list where each word of the string_list is contained once
    not_repeated=[]
    for i in string_list:
        if i not in not_repeated:
            not_repeated.append(i)
    
    #Create a dictionary based on the frequency of each word in not_repeated contained in string_list
    tupla_list=[]
    dic={}
    for i in range(len(not_repeated)):
        tupla=(not_repeated[i],string_list.count(not_repeated[i]))
        tupla_list.append(tupla)
    dic= dict((key,value) for (key,value) in tupla_list)
    
    #Print the dictionary
    print(dic)
    
main()