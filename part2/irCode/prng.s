############



############
modulo:

sub $sp, $sp, 24

lw $s7,8($sp)
lw $s6,12($sp)
lw $s5,16($sp)
lw $s4,20($sp)
div $a0,$a1
mflo $s6

mult $a1,$s6
mflo $s5

sub $s4,$a0,$s5

move $s7,$s4

move, $v0, $s7
sw $s7,8($sp)
sw $s6,12($sp)
sw $s5,16($sp)
sw $s4,20($sp)

add $sp, $sp, 24
jr $ra

############
gen_random:

sub $sp, $sp, 40

lw $s7,20($sp)
lw $s6,24($sp)
move $s6,$a0

li $s7,1

sw $s7,20($sp)
sw $s6,24($sp)

j Label_2

############
Label_1:

lw $s7,24($sp)
sw $s7,24($sp)


sub $sp, $sp, 20
sw $a0,4($sp)
sw $a1,8($sp)
sw $a2,12($sp)
sw $a3,16($sp)
sw $ra,0($sp)

li $v0, 1
move $a0, $s7
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $a0,4($sp)
lw $a1,8($sp)
lw $a2,12($sp)
lw $a3,16($sp)
lw $ra,0($sp)
add $sp, $sp, 20




############
lw $s7,28($sp)
lw $s6,32($sp)
lw $s5,24($sp)
lw $s4,36($sp)
mult $s5,$a2
mflo $s7

add $s6,$a3,$s7

sw $s7,28($sp)
sw $s6,32($sp)
sw $s5,24($sp)
sw $s4,36($sp)


sub $sp, $sp, 20
sw $a0,4($sp)
sw $a1,8($sp)
sw $a2,12($sp)
sw $a3,16($sp)
sw $ra,0($sp)

move $a0,$s6
move $a1,$a1
jal modulo
move $s4,$v0
lw $a0,4($sp)
lw $a1,8($sp)
lw $a2,12($sp)
lw $a3,16($sp)
lw $ra,0($sp)
add $sp, $sp, 20




sw $s7,28($sp)
sw $s6,32($sp)
sw $s5,24($sp)
sw $s4,36($sp)

############
lw $s7,16($sp)
lw $s6,20($sp)
lw $s5,24($sp)
lw $s4,36($sp)
move $s7,$s4

move $s5,$s7

addi $s6,$s6,1

sw $s7,16($sp)
sw $s6,20($sp)
sw $s5,24($sp)
sw $s4,36($sp)

############
Label_2:

lw $s7,20($sp)

lw $s5,0($v1)
sw $s7,20($sp)

sw $s5,0($v1)

slt $s6,$s5,$s7
beq $s6,$zero,Label_1

############
Label_3:


add $sp, $sp, 40


jr $ra

############
main:

sub $sp, $sp, 4
move $v1, $sp

lw $s7,0($v1)
li $s7,6

sw $s7,0($v1)


sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,5
li $a1,7
li $a2,3
li $a3,3
jal gen_random
lw $ra,0($sp)
add $sp, $sp, 4




############
li, $v0, 0

add $sp, $sp, 4
jr $ra

