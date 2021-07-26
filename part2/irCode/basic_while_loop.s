############


############
main:

sub $sp, $sp, 8

lw $s7,4($sp)
li $s7,0

sw $s7,4($sp)
############
Label_0:


lw $s6,4($sp)
sw $s6,4($sp)

slti$s7,$s6,3
beq $s7,$zero,Label_2

############
Label_1:

lw $s7,4($sp)
sw $s7,4($sp)

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




############
lw $s7,0($sp)
lw $s6,4($sp)
addi $s7,$s6,1

move $s6,$s7

sw $s6,4($sp)
sw $s7,0($sp)
j Label_0

############
Label_2:

li, $v0, 0
add $sp, $sp, 8
jr $ra

