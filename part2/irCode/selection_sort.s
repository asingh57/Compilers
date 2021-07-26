############



############
main:

sub $sp, $sp, 104

la $s7,0($sp)








lw $t6,32($sp)
lw $t5,48($sp)
li $s6,7
sw $s6,0($s7)

li $s5,2
sw $s5,4($s7)

li $s4,10
sw $s4,8($s7)

li $s3,20
sw $s3,12($s7)

li $s2,5
sw $s2,16($s7)

li $s1,6
sw $s1,20($s7)

li $s0,44
sw $s0,24($s7)

li $t7,33
sw $t7,28($s7)

li $t5,8

li $t6,0










sw $t6,32($sp)
sw $t5,48($sp)

############
_loop_label_0:

lw $s7,64($sp)


lw $s4,32($sp)
lw $s3,48($sp)
addi $s7,$s3,-1

sw $s7,64($sp)


sw $s4,32($sp)
sw $s3,48($sp)

slt$s5,$s7,$s4
bne $s5,$zero,_loop_label_1

############
lw $s7,68($sp)
lw $s6,32($sp)
lw $s5,36($sp)
lw $s4,40($sp)
move $s5,$s6

addi $s7,$s6,1

move $s4,$s7

sw $s7,68($sp)
sw $s6,32($sp)
sw $s5,36($sp)
sw $s4,40($sp)

############
_loop_label_2:

lw $s7,72($sp)


lw $s4,48($sp)
lw $s3,40($sp)
addi $s7,$s4,-1

sw $s7,72($sp)


sw $s4,48($sp)
sw $s3,40($sp)

slt$s5,$s7,$s3
bne $s5,$zero,_loop_label_3

############
lw $s7,80($sp)
lw $s6,84($sp)
la $s5,0($sp)



lw $s1,76($sp)
lw $s0,36($sp)
lw $t7,40($sp)
move $s4,$t7
sll $s4,$s4,2
add $s4,$s4,$s5
lw $s7,0($s4)

move $s3,$s0
sll $s3,$s3,2
add $s3,$s3,$s5
lw $s6,0($s3)

li $s1,0

sw $s7,80($sp)
sw $s6,84($sp)




sw $s1,76($sp)
sw $s0,36($sp)
sw $t7,40($sp)

slt$s2,$s7,$s6
beq $s2,$zero,_if_label_5

############
lw $s7,76($sp)
li $s7,1

sw $s7,76($sp)

############
_if_label_5:


lw $s6,76($sp)

sw $s6,76($sp)

li $s7,1
bne $s6,$s7,_if_label_4

############
lw $s7,36($sp)
lw $s6,40($sp)
move $s7,$s6

sw $s7,36($sp)
sw $s6,40($sp)

############
_if_label_4:

lw $s7,40($sp)
addi $s7,$s7,1

sw $s7,40($sp)

j _loop_label_2

############
_loop_label_3:

la $s7,0($sp)
lw $s6,32($sp)
lw $s5,88($sp)
lw $s4,92($sp)
lw $s3,60($sp)
lw $s2,36($sp)
lw $s1,56($sp)




move $s0,$s6
sll $s0,$s0,2
add $s0,$s0,$s7
lw $s5,0($s0)

move $s3,$s5

move $t7,$s2
sll $t7,$t7,2
add $t7,$t7,$s7
lw $s4,0($t7)

move $s1,$s4

move $t6,$s6
sll $t6,$t6,2
add $t6,$t6,$s7
sw $s1,0($t6)

move $t5,$s2
sll $t5,$t5,2
add $t5,$t5,$s7
sw $s3,0($t5)

addi $s6,$s6,1


sw $s6,32($sp)
sw $s5,88($sp)
sw $s4,92($sp)
sw $s3,60($sp)
sw $s2,36($sp)
sw $s1,56($sp)





j _loop_label_0

############
_loop_label_1:

lw $s7,32($sp)
li $s7,0

sw $s7,32($sp)

############
_loop_label_6:

lw $s7,96($sp)


lw $s4,32($sp)
lw $s3,48($sp)
addi $s7,$s3,-1

sw $s7,96($sp)


sw $s4,32($sp)
sw $s3,48($sp)

slt$s5,$s7,$s4
bne $s5,$zero,_loop_label_7

############
lw $s7,100($sp)

la $s5,0($sp)
lw $s4,32($sp)
move $s6,$s4
sll $s6,$s6,2
add $s6,$s6,$s5
lw $s7,0($s6)

sw $s7,100($sp)


sw $s4,32($sp)


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
lw $s7,32($sp)
addi $s7,$s7,1

sw $s7,32($sp)

j _loop_label_6

############
_loop_label_7:

li, $v0, 0

add $sp, $sp, 104
jr $ra

