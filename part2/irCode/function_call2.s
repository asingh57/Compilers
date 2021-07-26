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
doubleSquare:

sub $sp, $sp, 12

lw $s7,4($sp)

lw $s5,8($sp)
li $s6,2
mult $s6,$a0
mflo $s7

move $a0,$s7


sw $s7,4($sp)
sw $s5,8($sp)

sub $sp, $sp, 8
sw $a0,4($sp)
sw $ra,0($sp)

move $a0,$a0
jal square
move $s5,$v0
lw $a0,4($sp)
lw $ra,0($sp)
add $sp, $sp, 8




sw $s5,8($sp)
############
lw $s7,8($sp)
move $a0,$s7

move, $v0, $a0
sw $s7,8($sp)
add $sp, $sp, 12
jr $ra

############
main:

sub $sp, $sp, 8

lw $s7,0($sp)
sw $s7,0($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,10
jal doubleSquare
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

