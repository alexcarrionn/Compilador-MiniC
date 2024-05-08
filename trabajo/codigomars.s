.data
	_a : .word 0
	_b : .word 0
	_c : .word 0
	_dos : .word 0
	_e : .word 0
	_i : .word 0
	$str0 : .asciiz "Inicio del programa\n"
	$str1 : .asciiz "a"
	$str2 : .asciiz "\n"
	$str3 : .asciiz "No a y b\n"
	$str4 : .asciiz "c = "
	$str5 : .asciiz "\n"
	$str6 : .asciiz "Bucle do-while"
	$str7 : .asciiz "\n"
	$str8 : .asciiz " "
	$str9 : .asciiz "Final"
	$str10 : .asciiz "\n"
.text
.globl main
 main: 
	li $t0,0
	sw $t0,_a
	li $t0,0
	sw $t0,_b
	li $t0,5
	li $t1,2
	add $t0,$t0,$t1
	li $t1,2
	sub $t0,$t0,$t1
	sw $t0,_c
	li $t0,5
	sw $t0,_e
	li $v0,4
	la $a0,$str0
	syscall
	li $v0,5
	syscall
	sw $v0,_dos
	lw $t0,_a
	beqz $t0,$l5
	li $v0,4
	la $a0,$str1
	syscall
	li $v0,4
	la $a0,$str2
	syscall
	j $l6
 $l5:
	lw $t1,_b
	li $t2,0
	sne $t1,$t1,$t2
	beqz $t1,$l3
	li $v0,4
	la $a0,$str3
	syscall
	j $l4
 $l3:
 $l1:
	lw $t2,_c
	beqz $t2,$l2
	li $v0,4
	la $a0,$str4
	syscall
	lw $t3,_c
	li $v0,1
	move $a0,$t3
	syscall
	li $v0,4
	la $a0,$str5
	syscall
	lw $t3,_c
	li $t4,2
	sub $t3,$t3,$t4
	li $t4,1
	add $t3,$t3,$t4
	sw $t3,_c
	j $l1
 $l2:
 $l4:
 $l6:
 $l7:
	li $v0,4
	la $a0,$str6
	syscall
	li $v0,4
	la $a0,$str7
	syscall
	lw $t0,_e
	li $t1,1
	sub $t0,$t0,$t1
	sw $t0,_e
	lw $t0,_e
	li $t1,0
	sne $t0,$t0,$t1
	beqz $t0,$l8
	j $l7
 $l8:
	li $t0,1
	sw $t0,_i
 $l9:
	lw $t0,_i
	li $t1,5
	sle $t0,$t0,$t1
	beqz $t0,$l10
	lw $t1,_i
	li $v0,1
	move $a0,$t1
	syscall
	li $v0,4
	la $a0,$str8
	syscall
	lw $t1,_i
	li $t2,1
	add $t1,$t1,$t2
	sw $t1,_i
	j $l9
 $l10:
	li $v0,4
	la $a0,$str9
	syscall
	li $v0,4
	la $a0,$str10
	syscall
	li $v0 , 10
	syscall
