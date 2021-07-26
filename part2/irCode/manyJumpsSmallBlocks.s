############



############
main:

sub $sp, $sp, 12

lw $s7,0($sp)
lw $s6,4($sp)
lw $s5,8($sp)
li $s7,10

li $s6,20

add $s5,$s6,$s7

sw $s7,0($sp)
sw $s6,4($sp)
sw $s5,8($sp)

############
_label1:

lw $s7,0($sp)
lw $s6,4($sp)
lw $s5,8($sp)
li $s6,10

li $s7,20

add $s7,$s6,$s5

sw $s7,0($sp)
sw $s6,4($sp)
sw $s5,8($sp)

j _label4

############
_label2:

lw $s7,0($sp)
lw $s6,4($sp)
lw $s5,8($sp)
li $s6,10

li $s7,20

add $s7,$s6,$s5

sw $s7,0($sp)
sw $s6,4($sp)
sw $s5,8($sp)

j _label1

############
_label3:

lw $s7,0($sp)
lw $s6,4($sp)
lw $s5,8($sp)
li $s6,10

li $s7,20

add $s7,$s6,$s5

sw $s7,0($sp)
sw $s6,4($sp)
sw $s5,8($sp)

j _label2

############
_label4:


add $sp, $sp, 12


jr $ra

