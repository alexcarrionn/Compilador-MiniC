/*lexico.1*/
/* DEFINICION DE MARCOS Y CODIGO C LITERAL y se predeclaran las funciones*/

%{
    #include "sintactico.tab.h"
    #include <stdio.h>
    #include <math.h> 
    #include <stdlib.h>
    extern  int errores; 
%}
/*no poner comentarios en las macros*/
D  [0-9]
L  [a-zA-Z_]
E  [^0-9a-zA-Z_+\-*/=;(),{} \t\n\r]+
escape \\\"|\\\\|\\[ntr]
/*OPCIONES DE FLEX*/
%option yylineno

/* Contexto de comentario*/

%x comentario
/*la x significa esq tenemos dos autonomas pero felx nos hace que estos se ejecuten de forma exclusiva (x) o solapados, simultaniamente (s)*/


%%

 /*aqui se ponen las expresiones regulares de los tokens, siempre con un espacio en blanco
 para poder ignorar los espacios en blanco lo que se hace es una ER para que las pueda encontrar todas
 y como queremos ignorarlos no retornamos nada, PRINT lo ponemos arriba del todo para que no se confunda con los 
 identificadores, aqui es muy importante el orden, si es capaz de ver varias cadenas va a ver la primera y otra regla de funcionamiento
 por ejemplo si tenemos un printear va a cogerlo todo como un identificador y coge el lexema mas largo, el punto 
 es cualquier cosa menos el \t...*/
["]([^"\n\\]|{escape})*["] { yylval.cadena = strdup(yytext); 
                            return STR; }   /*esto lo que quiere decir es "" y luego todo lo que haya sin que haya ninguna " suelta*/
"print"              { return PRIN;  }
"var"                { return VAR;   }
"if"                 { return IF;    }
"else"               { return ELSE;  }
"read"               { return READ;  }
"while"              { return WHILE; }
"const"              { return CONST; }
{L}({L}|{D})*        { if(yyleng <= 32){
                            yylval.cadena = strdup(yytext);
                            return ID;
                        }
                        else{
                          printf("Error en linea %d identificador no valido: %s\n", yylineno,yytext); 

                          errores++; 
                        }

                     }
"+"                  { return SUMA; }
"-"                  { return REST; }
"*"                  { return MUL; }
"/"                  { return DIVI; }
"="                  { return IGUAL; }
{D}+                 { long l = atol(yytext);
                        if(l <= pow(2,31)){
                          yylval.cadena = strdup(yytext);
                          return NUME;} 
                        else {
                          printf("Error en linea %d numero no valido: %s\n", yylineno,yytext);
                          errores++;}
                     }
";"                  { return PC; }
","                  { return COMA; }
"("                  { return PARI; }
")"                  { return PARD; }
"{"                  { return LLAI; }
"}"                  { return LLAD; }
[ \t\r\n]+           { }   
  /*para comentarios*/
"//".*               { } 
"/*"                 { BEGIN(comentario); }
<comentario>"*/"     { BEGIN(INITIAL); }
<comentario>.|\n     { }
 /*el punto sirve para cacturas de errores felx no aumenta la linea de yylineno lo tenemos que hacer nosotros, 
 tambien podemos poner una funcion y ponerla abajo, lo cambiamos por E para que salga en una sola linea */
["]([^"\n]|\\\")*    { printf("ERROR en línea %d: %s\n", yylineno, yytext);
                    errores++;
                     }  
{E}                  {printf("ERROR en línea %d: %s\n", yylineno, yytext);
                    errores++;
                     }

%%

 /*aqui va el programa principal yylex es la que genera flex y la pone en lex.yy.c es una funcion que 
 implementa el autoamata de las funciones y devulve el RESTA, SUMA... y eso va a la variable tok, el yytext
 es para poder ver que es lo que se encuentra */
