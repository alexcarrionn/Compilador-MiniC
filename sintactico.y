%{ //parte de las declaraciones, parte en C con includes

    #include <stdio.h> 
    #include <string.h>
    #include <stdlib.h>
    extern int yylex(); 
    extern int yylineno; 
    void yyerror(const char* msg); //es obligatorio hacerlo o implementarlo nosotros 
    int regs[10]; 
    void inicializar_regs(); 
    void asignar_reg(char *reg, int valor); 
    int leer_reg(char *reg); 
    void imprimir_reg();
    int errores = 0;  
%}

/*Tipo de dato de los valores semanticos*/
%union{
    int entero; 
    char *cadena;
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
%type <entero> expression
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



/*
E -> E + E | E - E | E 
    | E * E | E \ E
    |(E) | num |-E

*/

program : ID  "(" ")" "{" declarations statement_list "}"  {}
declarations : declarations VAR identifier_list PC         {}
             | declarations CONST identifier_list PC       {}
             | %empty
             ; 
identifier_list : identifier                               {}
                | identifier_list "," identifier           {}
                ;
identifier  : ID                                           {printf("%s\n", $1);}
            | ID  "=" expression                           {printf("%s\n", $1);}
            ;
statement_list  : statement_list statement                 {}
                | %empty                                   {}
                ;
statement : ID  "=" expression PC                          {printf("%s\n", $1);}
            | "{" statement_list "}"                       {}
            | IF "(" expression ")" statement ELSE statement {}
            | IF "(" expression ")" statement                {}
            | WHILE "(" expression ")" statement             {}
            | PRIN "(" print_list ")" PC                      {}
            | READ "(" read_list ")"                         {}
            ;
print_list : print_item                                      {}
            | print_list "," print_item                      {}
            ;
print_item : expression                                      {}
            | STR                                            {printf("%s\n", $1);}
            ;
read_list : ID                                               {printf("%s\n", $1);}
            | read_list "," ID                               {printf("%s\n", $3);}
            ;
expression : expression "+" expression                       {}
            | expression "-" expression                      {}
            | expression "*" expression                      {}
            | expression "/" expression                      {}
            | "-" expression  %prec UMINUS                      {}
            | "(" expression ")"                             {}
            | ID                                             {printf("%s\n", $1);}
            | NUME                                           {printf("%s\n", $1);}
            ;

//cuando pone el NUME va a poner el numero de yyval en la pila tamb para no pederlo
%%

void yyerror(const char* msg){
    printf("Error en línea %d: %s\n", yylineno, msg); 
}
void inicializar_regs(){
    memset(regs, 0, 10*sizeof(int)); 
}

void asignar_reg(char *reg, int valor){
    // reg es una cadena de la forma r\d
    int idx = atoi(&(reg[1])); 
    /*esto lo que hace es que &reg[1] es la primera posicion de la caden y luego llego a los digitos*/
    regs[idx] = valor; 

}
int leer_reg(char *reg){
     int idx = atoi(&(reg[1])); 
     return regs[idx]; 
}
void imprimir_reg(){
    for(int i = 0; i < 10; i++){
        printf("r%d=%d\n", i, regs[i]); 
    }
    printf("El numero de errores totales es de: %d\n", errores);

}