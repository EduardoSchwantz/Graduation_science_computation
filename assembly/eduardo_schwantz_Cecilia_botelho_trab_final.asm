.data
contador: .space 40
mensagem: .asciiz "Programa ira realiza calculo de media ponderada, de ate 8 notas e 8 pesos. No lugar de virgula usar (ponto) | . | \n"
mensagem_nota1: .asciiz "Digite a nota 1: \n"
mensagem_peso1: .asciiz "Digite o peso 1: \n"
mensagem_nota2: .asciiz "Digite a nota 2: \n"
mensagem_peso2: .asciiz "Digite o peso 2: \n"
mensagem_nota3: .asciiz "Digite a nota 3: \n"
mensagem_peso3: .asciiz "Digite o peso 3: \n"
mensagem_nota4: .asciiz "Digite a nota 4: \n"
mensagem_peso4: .asciiz "Digite o peso 4: \n"
mensagem_nota5: .asciiz "Digite a nota 5: \n"
mensagem_peso5: .asciiz "Digite o peso 5: \n"
mensagem_nota6: .asciiz "Digite a nota 6: \n"
mensagem_peso6: .asciiz "Digite o peso 6: \n"
mensagem_nota7: .asciiz "Digite a nota 7: \n"
mensagem_peso7: .asciiz "Digite o peso 7: \n"
mensagem_nota8: .asciiz "Digite a nota 8: \n"
mensagem_peso8: .asciiz "Digite o peso 8: \n"
mensagem_media: .asciiz "\nSua media e. \n"
repetir: .asciiz "\nSe deseja adicionar mais notas digite 0, se deseja fazer o calculo da media digite 1.\n"
repetir_programa: .asciiz "\nSe deseja fazer nova media digite 0, se deseja encerrar o programa ditite 1.\n"
zero: .float 0.0
sete: .float 7.0
dez: .float 10.0
tres: .float 3.0
mensagem_exame_reprovado: .asciiz "\nVoce infelizmente esta em exame e necessita tirar: \n"
mensagem_aprovado: .asciiz "\nVoce Passou, sua nota foi maior ou igual a 7, e nao precisa de exame.\n Aproveite suas ferias. \n"
mensagem_sem_exame_reprovado: .asciiz "\nSua media foi menor que 3.0, infelizmente nao tera direito ao exame.\n"
fim_programa: .asciiz "\nEncerrando o programa.....\n"
.text	
	addi $t7, $zero, 0
	la  $t5, contador		#	tentativa salvar memoria
	lwc1 $f1, zero		#	cria variavel zero.
	addi $t4, $zero, 1	#	para encerrar calculos
	
	li $v0, 4
	la $a0, mensagem	#	mensagem da proposta do programa
 	syscall
 #///////////////////////////////////////////////////////////////////////////	inicio das notas, nota1
loop:
beq $t7, 11, fim

	li $v0, 4
	la $a0, mensagem_nota1	#	mensagem para escrever primeira nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f14, $f1, $f0  #	armazena primeira nota em $f14

	li $v0, 4
 	la $a0, mensagem_peso1	#	mensagem para escrever peso da primeira prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s   $f15, $f1, $f0	#	armazena primeiro peso em $f15
	mul.s  $f2, $f14, $f15 #	multiplica��o da nota1 pelo peso1 armazenada em $f2
	
	li $v0, 4
	la $a0, repetir
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, calculo
	
#//////////////////////////////////////////////////////////////////////////////////////		Nota2 
	
	li $v0, 4
	la $a0, mensagem_nota2	#	mensagem para escrever segunda nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f16, $f1, $f0  #	armazena segunda nota em $f16

	li $v0, 4
 	la $a0, mensagem_peso2	#	mensagem para escrever peso da segunda prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s   $f17, $f1, $f0	#	armazena segundo peso em $f17
	mul.s 	$f3, $f16, $f17 #	multiplica��o da nota2 pelo peso2 armazenada em $f3
	
		
	li $v0, 4
	la $a0, repetir
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, calculo
	
#//////////////////////////////////////////////////////////////////////////////////////		Nota3

	li $v0, 4
	la $a0, mensagem_nota3	#	mensagem para escrever terceira nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f18, $f1, $f0  #	armazena terceira nota em $f18

	li $v0, 4
 	la $a0, mensagem_peso3	#	mensagem para escrever peso da terceira prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s   $f19, $f1, $f0	#	armazena terceiro peso em $f19
	mul.s 	$f4, $f18, $f19 #	multiplica��o da nota3 pelo peso 3 armazenada em $f4
	
		
	li $v0, 4
	la $a0, repetir
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, calculo
	
#//////////////////////////////////////////////////////////////////////////////////////		Nota4
	li $v0, 4
	la $a0, mensagem_nota4	#	mensagem para escrever quarta nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f20, $f1, $f0  #	armazena quarta nota em $f20

	li $v0, 4
 	la $a0, mensagem_peso4	#	mensagem para escrever peso da quarta prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s  $f21, $f1, $f0	#	armazena quarto peso em $f21
	mul.s 	$f5, $f20, $f21 #	multiplica��o da nota4 pelo peso 4 armazenada em $f5
	
		
	li $v0, 4
	la $a0, repetir
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, calculo
	
#//////////////////////////////////////////////////////////////////////////////////////		Nota5
	li $v0, 4
	la $a0, mensagem_nota5	#	mensagem para escrever quinta nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f22, $f1, $f0  #	armazena quinta nota em $f22

	li $v0, 4
 	la $a0, mensagem_peso5	#	mensagem para escrever peso da quinta prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s   $f23, $f1, $f0	#	armazena quinto peso em $f23
	mul.s 	$f6, $f22, $f23 #	multiplica��o da nota5 pelo peso5 armazenada em $f6
	
		
	li $v0, 4
	la $a0, repetir
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, calculo
	
#//////////////////////////////////////////////////////////////////////////////////////		Nota6
	li $v0, 4
	la $a0, mensagem_nota6	#	mensagem para escrever sexta nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f24, $f1, $f0  #	armazena sexta nota em $f24

	li $v0, 4
 	la $a0, mensagem_peso6	#	mensagem para escrever peso da sexta prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s   $f25, $f1, $f0	#	armazena sexto peso em $f25
	mul.s 	$f7, $f24, $f25 #	multiplica��o da nota6 pelo peso6 armazenada em $f7
	
		
	li $v0, 4
	la $a0, repetir
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, calculo
	
#//////////////////////////////////////////////////////////////////////////////////////		Nota7

	li $v0, 4
	la $a0, mensagem_nota7	#	mensagem para escrever setima nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f26, $f1, $f0  #	armazena settima nota em $f26

	li $v0, 4
 	la $a0, mensagem_peso7	#	mensagem para escrever peso da setima prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s   $f27, $f1, $f0	#	armazena setimo peso em $f27
	mul.s 	$f8, $f26, $f27 #	multiplica��o da nota7 pelo peso7 armazenada em $f8
			
	li $v0, 4
	la $a0, repetir
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, calculo
#//////////////////////////////////////////////////////////////////////////////////////		Nota8

	li $v0, 4
	la $a0, mensagem_nota8	#	mensagem para escrever setima nota
	syscall 
 
	li $v0, 6		#	chamada para escrever float
 	syscall			#	valores float ser�o armazenados em $f0

 	add.s   $f28, $f1, $f0  #	armazena settima nota em $f28

	li $v0, 4
 	la $a0, mensagem_peso8	#	mensagem para escrever peso da setima prova
 	syscall 

	li $v0, 6		#	chamada para escrever float
	syscall

	add.s   $f29, $f1, $f0	#	armazena setimo peso em $f29
	mul.s 	$f9, $f28, $f29 #	multiplica��o da nota7 pelo peso7 armazenada em $f9
	
	
calculo:

	add.s $f10, $f1, $f2
	add.s $f10, $f10, $f3		#	somas das notas j� multiplicadas pelo peso
	add.s $f10, $f10, $f4
	add.s $f10, $f10, $f5
	add.s $f10, $f10, $f6
	add.s $f10, $f10, $f7
	add.s $f10, $f10, $f8
	add.s $f10, $f10, $f9

	add.s $f11, $f1, $f15
	add.s $f11, $f11, $f17
	add.s $f11, $f11, $f19
	add.s $f11, $f11, $f21		#soma dos pesos.
	add.s $f11, $f11, $f23
	add.s $f11, $f11, $f25
	add.s $f11, $f11, $f27
	add.s $f11, $f11, $f29
	
	div.s $f13, $f10, $f11
	
	s.s  $f13, ($t5) 	#	salva na memoria, primeira rota��o posi��o 0
	addi $t5, $t5, 4	#	soma 4 posi��es para pr�xima memoria.
		
	li $v0, 4
	la $a0, mensagem_media
	syscall
	
	add.s $f12, $f13, $f1	
	li $v0, 2
	syscall
	
	lwc1 $f30, tres
	c.lt.s   $f13, $f30 	#	se $f13 menor que tres retorna true, caso contrario false
	bc1t sem_exame		#	se true, entra no label
	
	lwc1 $f30, sete	
	c.lt.s   $f13, $f30	#	se $f13 menor que sete retorna true, caso contrario false
	bc1t  exame		#	se true, entra no label
	
	li $v0, 4
 	la $a0, mensagem_aprovado
 	syscall 	
 
programa:
 	addi $t7, $t7, 1
 	li $v0, 4
	la $a0, repetir_programa
	syscall
	
	li $v0, 5
	syscall
	
	add $t3, $zero, $v0
	beq $t3, $t4, fim 
 	
 	j loop
	
	
exame:	
 	li $v0, 4
 	la $a0, mensagem_exame_reprovado
 	syscall
 	
 	lwc1   $f30, dez
 	sub.s $f31, $f30, $f13		#	$f31 = $f30 - $f13 // x = 10 - media    retorna valor necessario no exame para media = 5.0
 	add.s $f12, $f31, $f1		#	$f12, necessario para impressao.
 	li $v0, 2
	syscall
	j programa

sem_exame:
	li $v0, 4
 	la $a0, mensagem_sem_exame_reprovado
 	syscall
 	j programa


fim:
		li $v0, 4
		la $a0, fim_programa
		syscall
		
		li $v0, 10	# c�digo para encerrar o programa
		syscall		# executa a chamada do SO para encerrar
	
	
	
	
	
