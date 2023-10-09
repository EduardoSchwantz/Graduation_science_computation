#	Escreva um programa que calcule o fatorial de um número N inteiro sem sinal, o
#	valor N deve ser inicializado no registrador $t0. Para o cálculo do fatorial deve ser
#	utilizada uma subrotina recursiva. O resultado final deve ser armazenado em $t1.
#	O argumento para a subrotina deve ser passado através do registrador $a0 e o
#	resultado da subrotina deve ser retornado através do registrador $v0

.data
   num:   .word   10
   one:   .word   1
 .text
	main:
	lw $t0, num		#	passa o valor que quer fatorar para t0
	lw $t7, num 		# 	passa para t7 o valor que quer fatorar para usar na rotina recursiva
	lw $t8, one		# 	passa para t8 o valor 1 para usar na recursa e na comparação 
	add $a0, $zero, $t0	#	passa para a0 o valor de t0 para usar como parametro na rotina
	j LOOP
	

LOOP:
sub $t7, $t7, $t8			#	subtrai em 1 o valor passado como fatorial, recursiva
mul $a0, $a0, $t7		#	multiplica o valor passado como fatorial, ao valor subtraido
bne $t7, $t8, LOOP		#	comparação para controle, vai repetir enquanto for >= a 1.
move $v0, $a0			#	move o resultado ao registrador v0
j Exit 




Exit:
move $t1, $v0			#	move o valor do registrador v0 para o t1, como a questao pede.
