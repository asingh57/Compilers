############


############
printSquare:

sub $sp, $sp, 8

lw $s7,4($sp)
mult $a0,$a0
mflo $s7

sw $s7,4($sp)

sub $sp, $sp, 8
sw $a0,4($sp)
sw $ra,0($sp)

li $v0, 1
move $a0, $s7
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $a0,4($sp)
lw $ra,0($sp)
add $sp, $sp, 8




############
add $sp, $sp, 8

jr $ra

############
main:


sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,10
jal printSquare
lw $ra,0($sp)
add $sp, $sp, 4




############
li, $v0, 0
jr $ra

