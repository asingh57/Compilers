############



############
main:

sub $sp, $sp, 32

lw $s7,24($sp)
lw $s6,0($sp)
lw $s5,8($sp)
lw $s4,4($sp)
lw $s3,12($sp)
lw $s2,28($sp)
lw $s1,16($sp)
lw $s0,20($sp)
li $s6,10

li $s4,25

add $s7,$s4,$s6

add $s7,$s7,$s6

add $s7,$s7,$s6

li $s5,30

li $s3,45

add $s2,$s3,$s5

li $s1,60

li $s0,69

add $s7,$s4,$s6

add $s2,$s3,$s5

add $s2,$s5,$s5

sw $s7,24($sp)
sw $s6,0($sp)
sw $s5,8($sp)
sw $s4,4($sp)
sw $s3,12($sp)
sw $s2,28($sp)
sw $s1,16($sp)
sw $s0,20($sp)

add $sp, $sp, 32

sw $s7,24($sp)
sw $s6,0($sp)
sw $s5,8($sp)
sw $s4,4($sp)
sw $s3,12($sp)
sw $s2,28($sp)
sw $s1,16($sp)
sw $s0,20($sp)

jr $ra

