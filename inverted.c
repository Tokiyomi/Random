#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

/*prototype*/
char reversed(char * cadena,int size,int i);

int main(){
    //Definir variables
    char cadena[30];
    int size;
    printf("Escribe una palabra: ");
    scanf("%s", &cadena);
    
    size=strlen(cadena);

    printf("%s", cadena2);
    return 0;
}

char reversed(char*cadena,int size, int i){
    if (size==1){
        return cadena;
    } else{
        char aux[30];
        if (size>=0);{
            aux[i]=cadena[size-1];
            i++;
        } return (cadena,size-1,i);
    }   
}