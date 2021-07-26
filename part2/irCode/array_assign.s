main:

sub $sp, $sp, 52

la $s7,28($sp)

li $s6,1
sw $s6, 0($s7)
sw $s6, 4($s7)
sw $s6, 8($s7)




la $s7,40($sp)

li $s6,10
sw $s6, 0($s7)
sw $s6, 4($s7)
sw $s6, 8($s7)




lw $s7,0($sp)
la $s6,28($sp)
lw $s7,0($s6)

sw $s7,0($sp)

lw $s7,0($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s7
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




sw $s7,0($sp)
lw $s7,4($sp)
la $s6,40($sp)
lw $s7,0($s6)

sw $s7,4($sp)

lw $s7,4($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s7
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




sw $s7,4($sp)
la $s7,40($sp)
la $s6,28($sp)

lw $s5,0($s6)
sw $s5,0($s7)
lw $s5,4($s6)
sw $s5,4($s7)
lw $s5,8($s6)
sw $s5,8($s7)





lw $s7,8($sp)
la $s6,40($sp)
lw $s7,0($s6)

sw $s7,8($sp)

lw $s7,12($sp)
la $s6,40($sp)
lw $s7,4($s6)

sw $s7,12($sp)

lw $s7,8($sp)
lw $s6,12($sp)
lw $s5,16($sp)
add $s5,$s6,$s7

sw $s7,8($sp)
sw $s6,12($sp)
sw $s5,16($sp)
lw $s7,20($sp)
la $s6,40($sp)
lw $s7,8($s6)

sw $s7,20($sp)

lw $s7,16($sp)
lw $s6,20($sp)
lw $s5,24($sp)
add $s5,$s6,$s7

sw $s7,16($sp)
sw $s6,20($sp)
sw $s5,24($sp)
lw $s7,24($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s7
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




sw $s7,24($sp)
li, $v0, 0
add $sp, $sp, 52
jr $ra

