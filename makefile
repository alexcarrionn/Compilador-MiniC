miniC : main.c lex.yy.c sintactico.tab.c
	gcc main.c lex.yy.c sintactico.tab.c -lfl -o miniC

#para poder llamar a BISON 
sintactico.tab.h sintactico.tab.c : sintactico.y 
	bison -d -v sintactico.y 


lex.yy.c : lexico.l sintactico.tab.h 
	flex lexico.l

clean : 
	rm -f miniC sintactico.tab.* lex.yy.c 

run : miniC entrada.txt 
	./miniC entrada.txt