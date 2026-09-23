# Compilador MiniC → MIPS

Compilador para **MiniC**, un subconjunto reducido de C que trabaja solo con enteros, que traduce programas fuente a **ensamblador MIPS** listo para ejecutar en [MARS](https://dpetersanderson.github.io/) o SPIM.

Proyecto de la asignatura **Compiladores** (Grado en Ingeniería Informática, Universidad de Murcia), desarrollado con **Flex** para el análisis léxico y **Bison** para el análisis sintáctico, semántico y la generación de código.

## Fases del compilador

El compilador recorre las cuatro fases clásicas en una sola pasada:

1. **Análisis léxico** (`miniC.l`, Flex). Reconoce palabras reservadas, identificadores, números, cadenas con secuencias de escape (`\"`, `\\`, `\n`, `\t`, `\r`), operadores y comentarios de línea (`//`) y de bloque (`/* */`). Detecta identificadores de más de 32 caracteres, enteros fuera de rango (> 2³¹), cadenas sin cerrar y caracteres no válidos, recuperándose en modo pánico.
2. **Análisis sintáctico** (`sintactico.y`, Bison). Gramática LALR con precedencia y asociatividad de operadores, menos unario (`UMINUS`), el conflicto del `if/else` colgante resuelto con `%expect 1` y mensajes de error detallados (`parse.error verbose`). La recuperación de errores se hace a nivel de sentencia con la regla `error ;`.
3. **Análisis semántico** (`listaSimbolos.c/.h`). Una tabla de símbolos guarda variables, constantes y cadenas, y comprueba que ningún identificador se declare dos veces, que no se use sin declarar y que no se asigne ni se lea (`read`) sobre una constante.
4. **Generación de código** (`listaCodigo.c/.h`). Cada no terminal construye una lista de operaciones MIPS (`op`, `res`, `arg1`, `arg2`). Se reparten los registros temporales `$t0`–`$t9` bajo demanda y se generan etiquetas únicas (`$l1`, `$l2`, …) para los saltos. Solo se emite código si no ha habido ningún error en las fases anteriores.

## El lenguaje MiniC

Un programa es una función sin parámetros con declaraciones seguidas de sentencias:

```c
nombre() {
    const a = 0, b = 0;
    var c = 5 + 2 - 2;
    var i;

    print("c = ", c, "\n");
    read(i);
}
```

| Elemento | Soporte |
|---|---|
| Tipos | Enteros (`.word`) y cadenas literales (solo en `print`) |
| Declaraciones | `var` y `const`, con inicialización opcional y listas separadas por comas |
| Aritmética | `+`, `-`, `*`, `/`, menos unario y paréntesis |
| Relacionales | `<`, `>`, `<=`, `>=`, `==`, `!=` |
| Control de flujo | `if`, `if-else`, `while`, `do-while`, `for` |
| E/S | `print(expr/cadena, ...)` y `read(id, ...)` |
| Bloques | `{ ... }` |

Como en C, cualquier expresión puede usarse como condición: un valor distinto de cero es verdadero. El bucle `for` tiene la forma `for (asignación; condición; asignación) { ... }`.

## Estructura del repositorio

```
.
├── Memoria Compi.pdf        # Memoria del proyecto
└── trabajo/
    ├── miniC.l              # Especificación léxica (Flex)
    ├── sintactico.y         # Gramática, semántica y generación de código (Bison)
    ├── listaSimbolos.c/.h   # Tabla de símbolos
    ├── listaCodigo.c/.h     # Lista de código MIPS
    ├── main.c               # Punto de entrada
    ├── testLC.c             # Prueba de la lista de código
    ├── makefile
    ├── entrada.txt          # Programa MiniC de ejemplo
    └── codigomars.s         # Salida MIPS generada para el ejemplo
```

## Requisitos

GCC, Flex (con `libfl`) y Bison, además de MARS o SPIM para ejecutar el ensamblador generado. En Debian/Ubuntu:

```bash
sudo apt install gcc flex bison libfl-dev
```

## Compilación y uso

```bash
cd trabajo
make                 # genera el ejecutable miniC
make run             # compila entrada.txt y guarda el resultado en codigomars.s
make clean           # borra los ficheros generados
```

También se puede invocar directamente sobre cualquier fichero:

```bash
./miniC programa.txt > salida.s
```

Para ejecutar el ensamblador, abre `salida.s` en MARS y pulsa *Assemble* y *Run*, o usa SPIM:

```bash
spim -file salida.s
```

Los errores léxicos, sintácticos y semánticos se muestran indicando la línea; en ese caso no se genera código.

## Ejemplo

Para este fragmento de `entrada.txt`:

```c
prueba() {
    var e = 5;
    do {
        print("Bucle do-while", "\n");
        e = e - 1;
    } while (e != 0);
}
```

el compilador produce una sección `.data` con las variables (prefijadas con `_`) y las cadenas (`$strN`), y una sección `.text` con el código:

```asm
.data
	_e : .word 0
	$str0 : .asciiz "Bucle do-while"
	$str1 : .asciiz "\n"
.text
.globl main
 main: 
	li $t0,5
	sw $t0,_e
 $l1:
	li $v0,4
	la $a0,$str0
	syscall
	...
	lw $t0,_e
	li $t1,1
	sub $t0,$t0,$t1
	sw $t0,_e
	lw $t0,_e
	li $t1,0
	sne $t0,$t0,$t1
	beqz $t0,$l2
	j $l1
 $l2:
	li $v0 , 10
	syscall
```

El ejemplo completo, con `if-else` anidados, `while`, `do-while` y `for`, está en `trabajo/entrada.txt` y su salida en `trabajo/codigomars.s`.

## Limitaciones

Solo hay 10 registros temporales y no se reutilizan con spilling a memoria, así que expresiones muy anidadas pueden agotarlos (el compilador aborta con un mensaje). Las constantes se protegen frente a asignaciones en tiempo de compilación, pero todos los valores se almacenan como `.word` inicializados a 0 y se asignan en tiempo de ejecución. No hay funciones con parámetros, arrays ni operadores lógicos (`&&`, `||`, `!`).
