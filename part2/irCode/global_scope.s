############


############
addToSum:

sub $sp, $sp, 8

lw $s7,4($sp)
lw $s6,0($v1)
add $s7,$a0,$s6

move $s6,$s7

sw $s7,4($sp)
sw $s6,0($v1)
add $sp, $sp, 8

jr $ra

############
main:

sub $sp, $sp, 4
move $v1, $sp

lw $s7,0($v1)
li $s7,5

sw $s7,0($v1)

sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,10
jal addToSum
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,0($v1)

sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,20
jal addToSum
lw $ra,0($sp)
add $sp, $sp, 4




sw $s7,0($v1)

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
add $sp, $sp, 4
jr $ra

