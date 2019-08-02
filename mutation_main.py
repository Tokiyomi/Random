# -*- coding: utf-8 -*-
"""
Created on Sun Jun 30 19:00:38 2019

@author: monic
"""
#Mutation algorithm using functions
import mutacion #Import functions

#Define parameters
target="universidad politecnica de yucatan"
population=10000
treshold_mutation=0.10
treshold_worst=0.80
treshold_parent= 0.10
letters=" abcdefghijklmnñopqrstuvwxyz"

#Define the initial population
poblacion=mutacion.init_population(population, target, letters)
#Start the generation counter in zero
generation=0

#Start the mutation process
while [len(target), target] not in poblacion:
    poblacion=mutacion.fitness(poblacion,target) #Scoring population
    poblacion=mutacion.ordering(poblacion) #Ordering population (the best above)
    poblacion=mutacion.elimination(poblacion,population,treshold_worst) #Eliminate the worst (empty list)
    #Select the parents from the best of the best and make children with them
    poblacion=mutacion.crossover(poblacion, population, treshold_worst, treshold_parent)
    #Some of the children will have some mutation
    poblacion=mutacion.mutation(poblacion, treshold_mutation, treshold_worst, population, letters)
    #We have created the n-th generation
    generation+=1

#The loop will finish when there were at least one mutation equal to the target
#When this happens, print the best 10 of the final population
print("The best 10 mutations were:\n",poblacion[:10])
#Print the number of generations that it takes to the mutation reach the target 
print("\nIt took {0} generations reaching the target".format(generation)) 