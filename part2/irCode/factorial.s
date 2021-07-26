############


############
factorial:

sub $sp, $sp, 20



li $s7,0
bne $a0,$s7,Label_2

############
Label_0:

li, $v0, 1
add $sp, $sp, 20
jr $ra

############
Label_2:

lw $s7,8($sp)

lw $s5,12($sp)
addi $s7,$a0,-1


sw $s7,8($sp)
sw $s5,12($sp)

sub $sp, $sp, 8
sw $a0,4($sp)
sw $ra,0($sp)

move $a0,$s7
jal factorial
move $s5,$v0
lw $a0,4($sp)
lw $ra,0($sp)
add $sp, $sp, 8




sw $s5,12($sp)
############
lw $s7,4($sp)
lw $s6,16($sp)
lw $s5,12($sp)
move $s7,$s5

mult $a0,$s7
mflo $s6

move, $v0, $s6
sw $s6,16($sp)
sw $s5,12($sp)
sw $s7,4($sp)
add $sp, $sp, 20
jr $ra

############
main:

sub $sp, $sp, 8

lw $s7,0($sp)
sw $s7,0($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,7
jal factorial
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

