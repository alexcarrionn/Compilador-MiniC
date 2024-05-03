.data
	_a : .word 0
	_b : .word 0
	$str0 : .asciiz "Hola mundo!!!! "
	$str1 : .asciiz "a no cero\n"
	$str2 : .asciiz "no"
.text
.globl main
 main: 
	li $t0,0
	sw $t0,_a
	li $t0,1
	lw $t1,_b
	add $t0,$t0,$t1
	sw $t0,_a
	li $v0,4
	la $a0,$str0
	syscall
	lw $t0,_a
	beqz $t0,$l1:
	li $v0,4
	la $a0,$str1
	syscall
 $l1:
 $l2:
	li $v0,4
	la $a0,$str2
	syscall
	li $v0 , 10
	syscall
