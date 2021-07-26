############


############
square:

sub $sp, $sp, 8

lw $s7,4($sp)
mult $a0,$a0
mflo $s7

move, $v0, $s7
sw $s7,4($sp)
add $sp, $sp, 8
jr $ra

############
main:

sub $sp, $sp, 8

lw $s7,0($sp)
sw $s7,0($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,5
jal square
move $s7,$v0
lw $ra,0($sp)
add $sp, $sp, 4




sw $s7,0($sp)
############
lw $s7,4($sp)
lw $s6,0($sp)
move $s7,$s6

sw $s6,0($sp)
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
li, $v0, 0
add $sp, $sp, 8
jr $ra

