%{ //parte de las declaraciones, parte en C con includes
    #define _GNU_SOURCE
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <stdbool.h>
    //parte de los simbolos
    #include "listaSimbolos.h"
    #include "listaCodigo.h"
    Lista l; 
    Tipo t; 
    void insertarID(char *id , Tipo t, int v); 
    void imprimeLs();
    void buscarId(char *id, int variable); 
    //tabla de registros libres 
    char registrosLibres[10]; 
    //metodo inicializar registros
    void inicializaReg(); 
    //Te va a devolver el $tX
    char *obtenerReg(); 
    void liberarReg(char *reg); 

    char *concatena(char *s1,char *s2);
    bool analisis_ok(); 
     void imprimirLC(ListaC codigo); 
    //aqui la parte de los strings
    void insertarSTR(char *id); 
    int val_str;
    //Generador de etiquetas de salto
    int contador_etiq = 1; 
    char *nuevaEtiqueta(); 


    extern int yylex(); 
    extern int yylineno; 
    void yyerror(const char* msg); //es obligatorio hacerlo o implementarlo nosotros 
    
    int errores = 0;  
%}



/*Tipo de dato de los valores semanticos*/
%union{
    ListaC codigo; 
    char *cadena;
}

//Incluir en tab.h la definicion de listaC
%code requires {
#include "listaCodigo.h"
}

//parte de los tokens por cada token se hace un codigo que es un macro de C, y luego aparece un token 
//para cada uno de ellos
%token <cadena> ID "id"
%token VAR "var"
%token CONST "const"
%token PRIN "print"
%token IF "if"
%token ELSE "else"
%token READ "read"
%token WHILE "while"
%token SUMA "+"
%token REST "-"
%token COMA ","
%token MUL  "*"
%token DIVI "/"
%token PARI "("
%token PARD ")"
%token LLAI "{"
%token LLAD "}"
%token <cadena>NUME "numero" //aqui pone una cadena
%token PC ";"
%token <cadena>STR "string"
%token IGUAL "="


/*Tipo de datos de los no terminales*/
%type <codigo> expression statement statement_list
%type <codigo> print_item print_list read_list
%type <codigo> identifier identifier_list declarations


%expect 1  //sirve porque el if / else es ambiguo

%define parse.error verbose //para decirle a bison que los errores tienen que ser detallados 

/*Precedencia y asociatividada de operadores
* %left 
* %right 
* %nonassoc
Aumenta precedencia en líneas sucesivas
*/
%left "+" "-"
%left "*" "/"
%precedence UMINUS
%%

program :                                                    {  l = creaLS(); 
                                                                inicializaReg();
                                                             }
            ID  "(" ")" "{" declarations statement_list "}"  {  if (analisis_ok){
                                                                imprimeLs();
                                                                concatenaLC($6, $7); 
                                                                imprimirLC($6);
                                                                liberaLC($7);
                                                                liberaLC($6);  } 
                                                                liberaLS(l);
                                                             }              //ENSEÑARLO AL PROFE
declarations : declarations VAR {t = VARIABLE; } identifier_list PC         {if(analisis_ok()){
                                                                                $$ = $1; 
                                                                                concatenaLC($$, $4); 
                                                                                liberaLC($4);            
                                                                            }
                                                                            }
             | declarations CONST {t = CONSTANTE; } identifier_list PC       {if(analisis_ok()){
                                                                                $$ = $1; 
                                                                                concatenaLC($$, $4); 
                                                                                liberaLC($4);            
                                                                            }
                                                                            }
             | %empty {if(analisis_ok())
                            $$ = creaLC(); }
             ; 
identifier_list : identifier                               {if(analisis_ok())
                                                                $$ = $1;}
                | identifier_list "," identifier           {if(analisis_ok()){
                                                                $$=$1; 
                                                                concatenaLC($$,$3); 
                                                                liberaLC($3); 
                                                            }}
                ;
identifier  : ID                                           {insertarID($1,t,0);
                                                            if(analisis_ok()){
                                                                $$ = creaLC();
                                                            }}
            | ID  "=" expression                           {insertarID($1,t,0);
                                                                if(analisis_ok()){
                                                                    $$ = $3; 
                                                                    Operacion oper; 
                                                                    oper.op = "sw"; 
                                                                    oper.res = recuperaResLC($3); 
                                                                    oper.arg1 = concatena("_", $1);
                                                                    oper.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper);
                                                                    liberarReg(oper.res); 
                                                                }}
            ;
statement_list  : statement_list statement                 { if(analisis_ok){
                                                                $$ = $1; 
                                                                concatenaLC($$, $2); 
                                                            }
                                                            }
                | %empty                                   {if(analisis_ok)
                                                                $$ = creaLC(); }
                ;
statement   : ID  "=" expression PC                          {buscarId($1, 1);
                                                                //pruebas
                                                                if(analisis_ok()){
                                                                    $$ = $3; 
                                                                    Operacion oper; 
                                                                    oper.op = "sw"; 
                                                                    oper.res = recuperaResLC($3); 
                                                                    oper.arg1 = concatena("_", $1);
                                                                    oper.arg2 = NULL;
                                                                    insertaLC($$, finalLC($$), oper);
                                                                    liberarReg(oper.res); 
                                                                }}
            | "{" statement_list "}"                         {$$= $2;}
            | IF "(" expression ")" statement ELSE statement { //ENSEÑASERLO AL PROFE
                                                            if(analisis_ok()){
                                                               char *etiqueta  = nuevaEtiqueta();
                                                               char *etiqueta2 = nuevaEtiqueta(); 
                                                               $$ = $3; 
                                                               Operacion oper; 
                                                               oper.op = "beqz"; 
                                                               oper.res = recuperaResLC($3); 
                                                               oper.arg1 = etiqueta; 
                                                               oper.arg2 = NULL;
                                                               insertaLC($$, finalLC($$), oper); 
                                                               liberarReg(oper.res);
                                                               //sentecia del if 
                                                               concatenaLC($$, $5); 
                                                               liberaLC($5);
                                                               oper.op = "etiq"; //para poner que es una etiqueta
                                                               oper.res = etiqueta; 
                                                               oper.arg1 = NULL; 
                                                               oper.arg2 = NULL;
                                                               insertaLC($$, finalLC($$), oper);  
                                                                //sentencia del else
                                                                oper.op = "etiq";
                                                                oper.res = etiqueta2;
                                                                oper.arg1 = NULL;
                                                                oper.arg2 = NULL;
                                                                insertaLC($$, finalLC($$), oper);
                                                                concatenaLC($$, $7);
                                                                liberaLC($7);
                                                                /*oper.op = "etiq";
                                                                oper.res = etiqueta2;
                                                                oper.arg1 = NULL;
                                                                oper.arg2 = NULL;
                                                                insertaLC($$, finalLC($$), oper);*/
                                                                
                                                               }
                                                                }
                                                                
            | IF "(" expression ")" statement                { if(analisis_ok()){
                                                               char *etiqueta  = nuevaEtiqueta();
                                                               $$ = $3; 
                                                               Operacion oper; 
                                                               oper.op = "beqz"; 
                                                               oper.res = recuperaResLC($3); 
                                                               oper.arg1 = etiqueta; 
                                                               oper.arg2 = NULL;
                                                               insertaLC($$, finalLC($$), oper); 
                                                               liberarReg(oper.res);
                                                               //sentecia del if 
                                                               concatenaLC($$, $5); 
                                                               liberaLC($5);
                                                               oper.op = "etiq"; //para poner que es una etiqueta
                                                               oper.res = etiqueta; 
                                                               oper.arg1 = NULL; 
                                                               oper.arg2 = NULL;
                                                               insertaLC($$, finalLC($$), oper);  
                                                               }
                                                                }
                                                                //ENSEÑASERLO AL PROFE
            | WHILE "(" expression ")" statement             {if(analisis_ok()){
                                                                char *etiqueta = nuevaEtiqueta(); 
                                                                char *etiqueta2 = nuevaEtiqueta(); 
                                                                $$ = $3; 
                                                                Operacion oper; 
                                                                oper.op = "etiq"; 
                                                                oper.res = etiqueta; 
                                                                oper.arg1 = NULL; 
                                                                oper.arg2 = NULL; 
                                                                insertaLC($$, finalLC($$), oper); 
                                                                oper.op = "beqz"; 
                                                                oper.res = recuperaResLC($3); 
                                                                oper.arg1 = etiqueta2; 
                                                                oper.arg2 = NULL; 
                                                                insertaLC($$, finalLC($$), oper); 
                                                                liberarReg(oper.res); 
                                                                concatenaLC($$, $5); 
                                                                liberaLC($5); 
                                                                oper.op = "j"; 
                                                                oper.res = etiqueta; 
                                                                oper.arg1 = oper.arg2 = NULL; 
                                                                insertaLC($$, finalLC($$), oper); 
                                                                oper.op = "etiq"; 
                                                                oper.res = etiqueta2; 
                                                                oper.arg1 = oper.arg2 = NULL; 
                                                                insertaLC($$, finalLC($$), oper); 
                                                            }    
                                                            }
            | PRIN "(" print_list ")" PC                      { $$ = $3; }
            | READ "(" read_list ")"                         { $$ = $3; }
            /*|FOR "(" ID "=" NUM ":" NUM ")"    {}*/
            | error PC                                          {/*por hacer*/}
            ;
print_list : print_item                                      { $$ = $1;}
            | print_list "," print_item                      {
                                                                $$ = $1; 
                                                                concatenaLC($$, $3); 
                                                                liberaLC($3); 
                                                                }
            ;
/*
expr_rel    : expression "<" expression {$$=$1; 
                                            concatenaLC($$,$3); 
                                            slt $t0, $t0, $t1;}
            |expression ">" expression {}
            |expression "==" expression {}
            |expression "!=" expression {}
            |expression "<=" expression {}
            |expression ">=" expression  {}
            ; 
            y poner en cada uno de las expresiones que lo quieran en ves de expression*/

print_item : expression                                      {
                                                                if(analisis_ok()){
                                                                    $$= $1; 
                                                                    Operacion oper; 
                                                                    oper.op = "li"; 
                                                                    oper.res = "$v0"; 
                                                                    oper.arg1 = "1"; 
                                                                    oper.arg2 = NULL; 
                                                                    insertaLC($$, finalLC($$), oper); 
                                                                    oper.op = "move"; 
                                                                    oper.res = "$a0";
                                                                    oper.arg1 = recuperaResLC($1); 
                                                                    oper.arg2  =NULL;
                                                                    insertaLC($$, finalLC($$), oper); 
                                                                    
                                                                    liberarReg(oper.arg1); 

                                                                    oper.op = "syscall"; 
                                                                    oper.res = oper.arg1 = oper.arg2 = NULL; 
                                                                    insertaLC($$,finalLC($$), oper); 

                                                                    
                                                                }}
            | STR                                            {insertarSTR($1);
                                                                if(analisis_ok()){
                                                                    $$= creaLC(); 
                                                                    Operacion oper; 
                                                                    oper.op = "li"; 
                                                                    oper.res = "$v0"; 
                                                                    oper.arg1 = "4"; 
                                                                    oper.arg2 = NULL; 
                                                                    insertaLC($$, finalLC($$), oper); 
                                                                    oper.op = "la"; 
                                                                    oper.res = "$a0";
                                                                    char *str; 
                                                                    asprintf(&str,"$str%d",val_str-1); 
                                                                    oper.arg1 = str; 
                                                                    oper.arg2  =NULL;
                                                                    insertaLC($$, finalLC($$), oper); 
                                                                    
                                                                    oper.op = "syscall"; 
                                                                    oper.res = oper.arg1 = oper.arg2 = NULL; 
                                                                    insertaLC($$,finalLC($$), oper); 
                                                                }}
            ;
read_list : ID                                               {buscarId($1, 1);}
            | read_list "," ID                               {buscarId($3, 1);}
            ;
expression :  expression "+" expression                       { if(analisis_ok){
                                                                 $$ = $1; concatenaLC($$,$3); 
                                                                Operacion oper; oper.op = "add"; 
                                                                oper.res = recuperaResLC($1);
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC($3);
                                                                insertaLC($$,finalLC($$),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC($3);}
                                                                }
            | expression "-" expression                      { if(analisis_ok){
                                                                 $$ = $1; concatenaLC($$,$3); 
                                                                Operacion oper; oper.op = "resta"; 
                                                                oper.res = recuperaResLC($1);
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC($3);
                                                                insertaLC($$,finalLC($$),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC($3);}}
            | expression "*" expression                      {if(analisis_ok){
                                                                 $$ = $1; concatenaLC($$,$3); 
                                                                Operacion oper; oper.op = "mul"; 
                                                                oper.res = recuperaResLC($1);
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC($3);
                                                                insertaLC($$,finalLC($$),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC($3);}}
            | expression "/" expression                      {if(analisis_ok){
                                                                 $$ = $1; concatenaLC($$,$3); 
                                                                Operacion oper; oper.op = "div"; 
                                                                oper.res = recuperaResLC($1);
                                                                oper.arg1 = oper.res;  
                                                                oper.arg2 = recuperaResLC($3);
                                                                insertaLC($$,finalLC($$),oper); 
                                                                liberarReg(oper.arg2);
                                                                liberaLC($3);}}
            | "-" expression  %prec UMINUS                      {
                                                                    if(analisis_ok()){
                                                                        $$ = $2;
                                                                        Operacion op; 
                                                                        op.op = "neg";
                                                                        op.res = recuperaResLC($2);
                                                                        op.arg1 = recuperaResLC($2);
                                                                        op.arg2 = NULL; 
                                                                        insertaLC($$, finalLC($$),op);  
                                                                    }
                                                                }
            | "(" expression ")"                             { $$ = $2; }
            | ID                                             {  if(analisis_ok()){
                                                                buscarId($1, 0);
                                                                $$ = creaLC();
                                                                Operacion oper;
                                                                oper.op = "lw";
                                                                oper.res = obtenerReg();
                                                                oper.arg1 = concatena("_",$1);
                                                                oper.arg2 = NULL;
                                                                insertaLC($$,finalLC($$),oper);
                                                                guardaResLC($$, oper.res); }}

            | NUME                                           {  if(analisis_ok()){
                                                                $$ = creaLC(); 
                                                                Operacion operacion; 
                                                                operacion.op = "li"; 
                                                                operacion.res = obtenerReg(); 
                                                                operacion.arg1 = $1; 
                                                                operacion.arg2 = NULL; 
                                                                insertaLC($$,finalLC($$),operacion);
                                                                guardaResLC($$, operacion.res); }
                                                             }
            ;
/*$$ es lo que se queda arriba de la pila*/
//cuando pone el NUME va a poner el numero de yyval en la pila tamb para no pederlo
%%

void yyerror(const char* msg){
    printf("Error en línea %d: %s\n", yylineno, msg); 
}
 
void insertarID(char *id, Tipo t, int v) {
    PosicionLista p = buscaLS(l,id);
if (p == finalLS(l)) {
    //para el string se usa esto , tipo cadena, valor numero que incrementa y el nombre $1
    Simbolo aux;
    aux.nombre = id;
    aux.tipo = t;
    aux.valor=v; 
    insertaLS(l,finalLS(l),aux);}
else{
    printf("Error: %s ya esta declado en la linea %d\n", id, yylineno); 
    errores++;
}
}


void imprimeLs(){
  printf(".data\n");
  PosicionLista p = inicioLS(l);
  while (p != finalLS(l)) {
    Simbolo aux = recuperaLS(l,p);
    if(aux.tipo == VARIABLE || aux.tipo == CONSTANTE)
         printf("\t_%s : .word %d\n",aux.nombre,aux.valor);
    else 
        printf("\t$str%d : .asciiz %s\n",aux.valor,aux.nombre);   
    p = siguienteLS(l,p);
  }
}

void buscarId(char *id, int variable){
PosicionLista p = buscaLS(l,id);
if (p != finalLS(l)) {
    if (variable == 1){
        Simbolo aux = recuperaLS(l,p);  
        if(aux.tipo != VARIABLE){
            errores++; 
            printf("Error: %s es constante en la linea %d\n", id, yylineno); 
        }
    }
}else{
    errores++; 
    printf("Error: %s no declarado en la linea %d\n", id, yylineno); 
}

}

//String

void insertarSTR(char *id){
    //para el string se usa esto , tipo cadena, valor numero que incrementa y el nombre $1
    Simbolo aux;
    aux.nombre = id;
    aux.tipo = CADENA;
    aux.valor= val_str++; 
    insertaLS(l,finalLS(l),aux);
}

    void inicializaReg(){
        for (int i = 0; i<10; i++){
            registrosLibres[i]=0; 
        }
    }
    //Te va a devolver el $tX
    char *obtenerReg(){
         for (int i = 0; i<10; i++){
            if(registrosLibres[i] == 0){
                registrosLibres[i] = 1; 
                char *reg; 
                asprintf(&reg, "$t%d", i) ;//le digo la posicion de memoria del puntero, se genera en memoria dinamica
                return reg; 
            }
        }
        printf("Error: los registros ya se han llenado todos! \n");
        exit(1);  
    } 
    void liberarReg(char *reg){
        int indice = atoi(&(reg[2])); //pasa de un caracter a entero
        registrosLibres[indice]=0;  
    }

    bool analisis_ok(){
        return errores==0; 
    }

    char *concatena(char *s1,char *s2){
        char *aux; 
        asprintf(&aux, "%s%s", s1, s2); 
        return aux;  
    }

    //Imprimir la lista del codigo 
    void imprimirLC(ListaC codigo1){
        printf(".text\n.globl main\n main: \n"); 
        Operacion oper; 
        PosicionListaC p = inicioLC(codigo1);
         while (p != finalLC(codigo1)) {
            oper = recuperaLC(codigo1,p);
            if(!strcmp(oper.op, "etiq")){
                printf(" %s",oper.res);
            }else{
            printf("\t%s",oper.op);
            if (oper.res) printf(" %s",oper.res);
                if (oper.arg1) printf(",%s",oper.arg1);
                    if (oper.arg2) printf(",%s",oper.arg2);
            }

                     printf("\n");
                    p = siguienteLC(codigo1,p);
        }
        printf("\tli $v0 , 10\n\tsyscall\n"); 
    }


    char *nuevaEtiqueta() {
        char *aux;
        asprintf(&aux,"$l%d:",contador_etiq++);
        return aux;
    }