

main:

sub $sp, $sp, 4

lw $s7,0($sp)
li $s7,1

j Label_1

Label_0:

lw $s7,0($sp)
sw $s7,0($sp)

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




lw $s7,0($sp)
addi $s7,$s7,1

sw $s7,0($sp)
Label_1:


lw $s6,0($sp)
sw $s6,0($sp)

slti $s7,$s6,5
bne $s7,$zero,Label_0

Label_2:

li, $v0, 0
add $sp, $sp, 4
jr $ra

