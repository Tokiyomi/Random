#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
/* INTEGER MATRIX CALCULATOR HEADER */

/* TEAM DATA 2A:
    CAROLINA GARMA
    LUIS ZAPATA
    ALAN PERAZA
    OSWALDO CHAN
    28/07/19
 */

void add(int32_t *array1, int32_t *array2,int row,int col, int row2, int col2){
    /* Function that computes the addition of two matrix
        ARGS:
            *array1: a pointer matrix of nxm 
            *array2: a pointer matrix of nxm
            row: #rows of array1
            col: #cols array1
            row2: #rows of array2
            col2: #cols of array2

        RETURNS:
            Prints an nxm matrix
     */
    printf("\nM1 + M2:\n");
    if (row==row2 && col==col2){ //evaluate if both matrix hve the same size
        int32_t *array3=NULL; //Define the resultant matrix
        int items= row*col; 
        array3=calloc(items,sizeof(int32_t)); //Compute the size of the new array
        for (int i=0; i<items;i++){
            *array3=array1[i] + array2[i]; //Sum the terms of the same index
            array3++; //+1 index
        }
        array3=array3-items; //re start the index in 0
        for(int a = 0; a < row; a++) {
            for (int b = 0; b < col; b++) {
                printf("%d ", *array3); //print resultant matrix
                array3++;
            }
            printf("\n");
        }
        array3=array3-items; //re start the index in 0
        free(array3); //space
    } else printf("\nYour matrix must have the same number of mxn\n"); //print a message
}

void sub(int32_t *array1, int32_t *array2,int row,int col, int row2, int col2){
    /* Function that computes the substraction of two matrix
        ARGS:
            *array1: a pointer matrix of nxm 
            *array2: a pointer matrix of nxm
            row: #rows of array1
            col: #cols array1
            row2: #rows of array2
            col2: #cols of array2

        RETURNS:
            Prints an nxm matrix
     */
    printf("\nM1 - M2:\n");
    if (row==row2 && col==col2){ //Evaluate if both matrix have the same size
        int32_t *array3=NULL; //Define the resultant matrix
        int items= row*col;
        array3=calloc(items,sizeof(int32_t)); //Compute the size of the resultant matrix
        for (int i=0; i<items;i++){
            *array3=array1[i] - array2[i]; //Subs the terms of the same index
            array3++; //+1 index
        }
        array3=array3-items; //index 0
        for(int a = 0; a < row; a++) {
            for (int b = 0; b < col; b++) {
                printf("%d ", *array3); //print the resultant matrix
                array3++;
            }
            printf("\n");
        }
        array3=array3-items; // index 0
        free(array3);
    } else printf("\nYour matrix must have the same number of mxn\n"); //print a message
}

void mult(int32_t *array1, int32_t *array2,int row,int col, int row2, int col2){
    /* Function that computes the multiplication of two matrix
        ARGS:
            *array1: a pointer matrix of axm MAX[10][10]
            *array2: a pointer matrix of mxb MAX[10][10]
            row: #rows of array1
            col: #cols array1
            row2: #rows of array2
            col2: #cols of array2

        RETURNS:
            Prints an axb matrix MAX[10][10]
     */
    const ROW=row;
    printf("\nM1*M2:\n");
    if (col==row2){ //Evaluate if the col of the matrix 1 is equal to the row of the matrix 2
        int32_t array1_aux[10][10]; //Create an auxiliar array for the array1
    
        for (int i=0; i<row;i++){
            for (int j=0; j<col; j++){
                array1_aux[i][j]=array1[j+i*col]; //Add the values from array1 to the aux_array
            }
        }
    
        int32_t array2_aux[10][10]; //Create an auxiliar array for the array1
    
        for (int i=0; i<row2;i++){
            for (int j=0; j<col2; j++){
                array2_aux[i][j]=array2[j+i*col2]; //Add the values from array2 to the aux_array2
            }
        }

        int32_t array3_aux[10][10]; //Create an array for the result
        for (int i=0; i<row;i++){
            for (int j=0; j<col2;j++){
                array3_aux[i][j]=0;
                for (int z=0; z<col; z++){
                    array3_aux[i][j]+= (array1_aux[i][z]*array2_aux[z][j]); //compute each term
                }
            }
        }
        for(int a = 0; a < row; a++) {
            for (int b = 0; b < col2; b++) {
                printf("%d ", array3_aux[a][b]); //print the resultant array
            }
            printf("\n");
        }
    } else printf("\nThe #column of M1 must be equal to the #rows of M2\n"); //print a message
     
} 

void trans(int32_t *array1, int row, int col){ 
    /* Function that computes the transpose of a matrix
        ARGS:
            *array1: a pointer matrix of nxm MAX[10][10]
            row: #rows of array1
            col: #cols array1

        RETURNS:
            Prints a mxn matrix MAX[10][10]
     */
    int32_t array1_aux[10][10]; //Open an aux array1 for the pointer
    printf("\nM1.T:\n");
    for (int i=0; i<row;i++){
        for (int j=0; j<col; j++){
            array1_aux[i][j]=array1[j+i*col]; //Add the values from array1 to the aux_array1
        }
    }
    for (int i=0; i<col;i++){ //now col=row
        for (int j=0; j<row; j++){ // now row=col
            printf("%d ", array1_aux[j][i]); //print the transpose matrix
        }
        printf("\n");
    }
}


void had(int32_t *array1, int32_t *array2,int row,int col, int row2, int col2){
    /* Function that computes the hadamard product of two matrix
        ARGS:
            *array1: a pointer matrix of nxm 
            *array2: a pointer matrix of nxm
            row: #rows of array1
            col: #cols array1
            row2: #rows of array2
            col2: #cols of array2

        RETURNS:
            Prints a nxm matrix 
     */
    printf("\nHadamard product:\n");
    if (row==row2 && col==col2){ //Evaluate if the matriz are of the same size
        int32_t *array3=NULL; //Define the resultant matrix
        int items= row*col;
        array3=calloc(items,sizeof(int32_t)); //Define the size of the resultant matrix
        for (int i=0; i<items;i++){
            *array3=array1[i]*array2[i]; //Compute the hadamart product a[i][j]*b[i][j]
            array3++; //index +1
        }
        array3=array3-items; //index 0
        for(int a = 0; a < row; a++) {
            for (int b = 0; b < col; b++) {
                printf("%d ", *array3); //print the resultant matrix
                array3++; //index +1
            }
            printf("\n");
        }
        array3=array3-items; //index 0
        free(array3);
    } else printf("\nYour matrix must have the same number of mxn\n"); //print a message
}

void out(int32_t *array1, int32_t *array2,int row,int col, int row2, int col2){
    /* Function that computes the outer product of two matrix
        ARGS:
            *array1: a pointer matrix of nx1
            *array2: a pointer matrix of 1xm
            row: #rows of array1
            col: #cols array1
            row2: #rows of array2
            col2: #cols of array2

        RETURNS:
            Prints a nxm matrix
     */
    printf("\nOuter product:\n");
    if (col==1 && row2==1){ //Evaluate if both matrix follow the condition nx1 and 1xm
        int32_t *array3=NULL; //Define the resultant matrix
        int items= row*col2;
        array3=calloc(items,sizeof(int32_t)); //Define the size of the resultant matrix
        for (int i=0; i<row;i++){
            for (int j=0; j<col2;j++){
                *array3=array1[i]*array2[j]; //Compute the outer product a[i][0]*b[0][j]
                array3++; //index+1
            }
        }
        array3=array3-items; //index = 0
        for(int a = 0; a < row; a++) {
            for (int b = 0; b < col2; b++) {
                printf("%d ", *array3); //print the resultant matrix
                array3++; //index +1
            }
            printf("\n");
        }
        array3=array3-items; //index = 0
        free(array3);
    } else printf("\nM1 must have 1 col and M2 must have 1 row\n"); //print a message
}

int det(int32_t *array1,int row,int col){ 
    /* Function that computes the determinant of a matrix MAX[3][3]
        ARGS:
            *array1: a pointer matrix of nxn
            row: #rows of array1
            col: #cols array1
    
        RETURNS:
            deter: an integer value which is the determinant
     */
	int deter, A,B,C,D,E,F;
    printf("\nDet M1:\n");
	if(row != col){ //Evaluate if it does not follow the condition for the inverse matrix
		printf("\nSorry, only works where col and row are equals \n");
	}
	
	else{
		if (row == 2){ //Determinant for a 2x2 matrix

            int32_t array1_aux[2][2]; //open a 2x2 aux_array
    
            for (int i=0; i<row;i++){
                for (int j=0; j<col; j++){
                    array1_aux[i][j]=array1[j+i*col]; //Add the values from the pointer to the aux
                }
            }

			deter = (array1_aux[0][0] * array1_aux[1][1]) - (array1_aux[0][1] * array1_aux[1][0]); //Compute the det
  			printf("%d \n", deter); //print the value
            return deter; //return the value
		}
		else{
			if(row == 3){ //Determinant for a 3x3 matrix
                int32_t array1_aux[3][3]; //Open a 3x3 aux_array
    
                for (int i=0; i<row;i++){
                    for (int j=0; j<col; j++){
                        array1_aux[i][j]=array1[j+i*col]; //Add the values from the pointer to the aux
                    }
                }
				//Compute the determinant
				A = array1_aux[0][0] * array1_aux[1][1] * array1_aux[2][2];
				B = array1_aux[0][1] * array1_aux[1][2] * array1_aux[2][0];
				C = array1_aux[1][0] * array1_aux[2][1] * array1_aux[0][2];
				  
				D = array1_aux[0][2] * array1_aux[1][1] * array1_aux[2][0];
			    E = array1_aux[1][2] * array1_aux[2][1] * array1_aux[0][0];
				F = array1_aux[0][1] * array1_aux[1][0] * array1_aux[2][2];
				  
				deter = A+B+C-D-E-F;
				printf("%d\n", deter); //print the value
                return deter; //return the value
			}
			else{
				//print a message if the dimmesions are over 3x3
				printf("\nSorry teacher. It only works with 2x2 and 3x3, but at least we did not look for the solution on stackoverflow \n");
			}
		}
	}
}

void inv(int32_t *array1, int row, int col){ 
    /* Function that computes the inverse of a matrix MAX[3][3]
        ARGS:
            *array1: a pointer matrix of nxn MAX[3][3]
            row: #rows of array1
            col: #cols array1

        RETURNS:
            Prints an inverse nxn matrix MAX[3][3]
     */
    int32_t array1_aux[3][3]; //open an aux_array MAX[3][3]
    float adjunta[3][3]; //Open an array for the "andjunta" MAX[3][3]
    for (int i=0; i<row;i++){
        for (int j=0; j<col; j++){
            array1_aux[i][j]=array1[j+i*col]; //Add the values from the pointer to the aux
        }
    }

    // Compute the determinant of the original matrix and transform it into a float variable
    float determinante = det(array1,row,col);    
    
    printf("\nInverse:\n");
    if(determinante == 0){
    	
    	printf("It does not have an inverse matrix or maybe your matrix is bigger than 3x3\n");
    }
    
    else{ //Compute the "adjunta"

    	if(col == 2){ //For a 2x2 matrix
    		adjunta[0][0] = array1_aux[1][1];
    		adjunta[0][1] = (-(array1_aux[1][0]));
    		adjunta[1][0] = (-(array1_aux[0][1]));
    		adjunta[1][1] = array1_aux[0][0];
	
    //Compute the transpose of the "adjunta" and divide it by the determinant
    for (int i=0; i<col;i++){
        for (int j=0; j<row; j++){
            float result= adjunta[j][i]/determinante; 
            printf("%.2f ", result); //print the inverse matrix
        }
        printf("\n");
    }
    			
    		}
    	
    	else{
    		if(col == 3){ //"adjunta" for a 3x3 matrix
    			adjunta[0][0] = array1_aux[1][1] * array1_aux[2][2] - array1_aux[1][2] * array1_aux[2][1];
    			adjunta[0][1] = -(array1_aux[1][0] * array1_aux[2][2] - array1_aux[1][2] * array1_aux[2][0]);
    			adjunta[0][2] = array1_aux[1][0] * array1_aux[2][1] - array1_aux[1][1] * array1_aux[2][0];
    			adjunta[1][0] = -(array1_aux[0][1] * array1_aux[2][2] - array1_aux[0][2] * array1_aux[2][1]);
    			adjunta[1][1] = array1_aux[0][0] * array1_aux[2][2] - array1_aux[0][2] * array1_aux[2][0];
    			adjunta[1][2] = -(array1_aux[0][0] * array1_aux[2][1] - array1_aux[0][2] * array1_aux[2][0]);
    			adjunta[2][0] = array1_aux[0][1] * array1_aux[1][2] - array1_aux[0][2] * array1_aux[1][1];
    			adjunta[2][1] = -(array1_aux[0][0] * array1_aux[1][2] - array1_aux[0][2] * array1_aux[1][0]);
    			adjunta[2][2] = array1_aux[0][0] * array1_aux[1][1] - array1_aux[0][1] * array1_aux[1][0];

                    //Compute the transpose of the "adjunta" and divide it by the determinant
    			    for (int i=0; i<col;i++){
				        for (int j=0; j<row; j++){
				            float result= adjunta[j][i]/determinante;
				            printf("%.2f ", result); //print the inverse matrix
				        }
				        printf("\n");
				    }
    			
    			
    			
    		}
    		
    	}
    		
    	
    	
    	
    	}
    	
}