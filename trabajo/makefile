miniC : main.c lex.yy.c sintactico.tab.c listaSimbolos.c listaCodigo.c
	gcc -g main.c lex.yy.c sintactico.tab.c listaSimbolos.c listaCodigo.c -lfl -o miniC

#para poder llamar a BISON 
sintactico.tab.h sintactico.tab.c : sintactico.y 
	bison -d -v sintactico.y 

lex.yy.c : miniC.l sintactico.tab.h 
	flex miniC.l

clean : 
	rm -f miniC sintactico.tab.* lex.yy.c 

run : miniC entrada.txt 
	./miniC entrada.txt > codigomars.s