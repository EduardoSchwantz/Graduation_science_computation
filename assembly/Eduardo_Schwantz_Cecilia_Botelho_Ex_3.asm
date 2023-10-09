	.data # inicia a seção de dados
	a: .word 20	# escreve a em 0x10010000
	b: .word 15	# escreve b em 0x10010004
	c: .word 12	# escreve c em 0x10010008
	.text # inicia a seção de instruções
		
	.main:
	lui $t0, 0x1001 # carrega o reg $t0 com 0x10010000
	lw $t1, 0($t0)	# carrega $t1 com a word em 0x10010000
	lw $t2, 4($t0)	# carrega $t2 com a word em 0x10010004
	lw $t3, 8($t0)	# carrega $t3 com a word em 0x10010008
	
	
	#primeira possibilidade para t1 mediana
	slt $t4, $t1, $t2			#testa se t1 < t2 e retorna 1 a t4 se verdadeiro, se não 0.
	bne $t4, $zero, teste1t1		#se t4 diferente de zero, va para teste1t1.
		
	else1t1:				#se teste1t1 for falso retorna para ca
	#segunda possibilidade de t1 mediana
	slt $t4, $t1, $t3			#testa se t1 < t3 e retorna 1 a t4 se verdadeiro, se não 0.
	bne $t4, $zero, teste2t1		#se t4 diferente de zero, va para teste2t1.
	
	else2t1:				#se teste2t1 for falso retorna para ca
	#primeira possibilidade de t2 mediana
	slt $t4, $t2, $t1			#testa se t2 < t1 e retorna 1 a t4 se verdadeiro, se não 0.
	bne $t4, $zero, teste1t2		#se t4 diferente de zero, va para teste1t2.
	
	else1t2:				#se teste1t2 for falso retorna para ca
	#segunda possibilidade de t2 mediana
	slt $t4, $t2, $t3			#testa se t2 < t3 e retorna 1 a t4 se verdadeiro, se não 0.
	bne $t4, $zero, teste2t2		#se t4 diferente de zero, va para teste2t2.
	
	else2t2:				#se teste2t2 for falso retorna para ca
	#primeira possibilidade de t3 mediana
	slt $t4, $t3, $t1			#testa se t3 < t1 e retorna 1 a t4 se verdadeiro, se não 0.
	bne $t4, $zero, teste1t3		#se t4 diferente de zero, va para teste1t3.
	
	else1t3:				#se teste1t3 for falso retorna para ca
	#segunda possibilidade de t2 mediana
	slt $t4, $t3, $t2			#testa se t3 < t2 e retorna 1 a t4 se verdadeiro, se não 0.
	bne $t4, $zero, teste2t3		#se t4 diferente de zero, va para teste1t3.
		
	teste1t1:				
	bgt $t1, $t3, t1			#testa se t1 > t3 se verdadeiro entao t1 é a mediana e vai para t1
	j else1t1				#se falso vai para else1t1
	
	teste2t1:
	bgt $t1, $t2, t1			#testa se t1 > t2 se verdadeiro entao t1 é a mediana e vai para t1
	j else2t1				# se falso vai para else2t1
	
	teste1t2:
	bgt $t2, $t3, t2			#testa se t2 > t3 se verdadeiro entao t2 é a mediana e vai para t2
	j else1t2				# se falso vai para else1t2
	
	teste2t2:
	bgt $t2, $t1, t2			#testa se t2 > t1 se verdadeiro entao t2 é a mediana e vai para t2 
	j else2t2				# se falso vai para else2t2
	
	teste1t3:
	bgt $t3, $t2, t3			#testa se t3 > t2 se verdadeiro entao t3 é a mediana e vai para t3
	j else1t3				# se falso vai para else1t3
	
	teste2t3:
	bgt $t3, $t1, t3			#testa se t3 > t1 se verdadeiro entao t3 é a mediana e vai para t3

	
	t1:
	add $s2, $zero, $t1			#S2 recebem a soma de 0 + t1
	sw $s2, 12($t0) # escreve a word $s2 em 0x1001000C		
	li $v0, 1		#chama para imp
	move $a0, $s2		#move o valor
	syscall			#imprime o valor
	li $v0, 10		#v0 recebe 10 para encerrar o programa
	syscall
	
	t2:
	add $s2, $zero, $t2			#S2 recebem a soma de 0 + t2
	sw $s2, 12($t0) # escreve a word $s2 em 0x1001000C	
	li $v0, 1		#chama para imp
	move $a0, $s2		#move o valor
	syscall			#imprime o valor
	li $v0, 10		#v0 recebe 10 para encerrar o programa
	syscall
	
	
	t3:
	add $s2, $zero, $t3			#S2 recebem a soma de 0 + t3
	sw $s2, 12($t0) # escreve a word $s2 em 0x1001000C		
	li $v0, 1		#chama para imp
	move $a0, $s2		#move o valor
	syscall			#imprime o valor
	li $v0, 10		#v0 recebe 10 para encerrar o programa
	syscall
	
	
