#include <stdio.h> 
#include <string.h> 

/*Prototype*/
int palindroma(char * cadena, int inicio, int final); //Funcion para determinar si es palindroma
/* Args:
        cadena: un array de caracteres
        inicio: primer caracter del array
        final: ultimo caracter del array
    Returns:
        1=True si son iguales
        0=False si no son iguales
*/
int main(){
    //Definir variables
    char palabra[30];
    printf("Escribe tu palabra: ");
    scanf("%s",&palabra);

    //Definir inicio y final de la palabra 
    int size=strlen(palabra);
    int inicio=0;
    int final=size-1;

    //Calcular si e spalindroma
    int resultado=palindroma(palabra, 0, final);

    if (resultado) {
            printf("'%s' es palindroma\n", palabra);
        } else {
            printf("'%s' NO es palindroma\n", palabra);
    }
    
}
//Desarrollar funcion
int palindroma(char * cadena, int inicio, int final) {
    if (inicio>=final){ //Caso base, cuando es un solo caracter
        return 1;
    } else { //Sino, comparar primer y ultimo caracter
        if (cadena[inicio]==cadena[final]){
            return palindroma(cadena, inicio + 1, final - 1); //Seguir hacia adentro
        } else{ //Si no son iguales, entonces no es palindroma
            return 0;
        }
    } 
}



