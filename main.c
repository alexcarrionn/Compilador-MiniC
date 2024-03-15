#include <stdio.h>
extern int yyparse();  //Analizador sintactico de BISON 
extern FILE *yyin;

int main (int argc, char *argv[]){

    if(argc !=2 ){
        printf("Uso: %s entrada.txt\n", argv[0]); 
        return 1; 
    }

    FILE *fin= fopen(argv[1], "r"); 
    if (fin == NULL){
        printf("El archivo %s no existe o no se puede abrir\n", argv[1]); 
        return 2; 
    }

    yyin=fin; 

    int res = yyparse();
    printf("Resultado yyparse: %d\n",res); 
    fclose(fin); 
}