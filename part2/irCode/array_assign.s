############


############
main:

sub $sp, $sp, 52

lw $s7,0($sp)
la $s6,28($sp)


la $s3,40($sp)
li $s5,1
sw $s5, 0($s6)
sw $s5, 4($s6)
sw $s5, 8($s6)


li $s4,10
sw $s4, 0($s3)
sw $s4, 4($s3)
sw $s4, 8($s3)


lw $s7,0($s6)





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




############
lw $s7,4($sp)
la $s6,40($sp)
lw $s7,0($s6)


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
la $s7,40($sp)
lw $s6,8($sp)
lw $s5,12($sp)
lw $s4,16($sp)
lw $s3,20($sp)
lw $s2,24($sp)

la $s0,28($sp)
lw $s1,0($s0)
sw $s1,0($s7)
lw $s1,4($s0)
sw $s1,4($s7)
lw $s1,8($s0)
sw $s1,8($s7)


lw $s6,0($s7)

lw $s5,4($s7)

add $s4,$s5,$s6

lw $s3,8($s7)

add $s2,$s3,$s4


sw $s6,8($sp)

sw $s3,20($sp)

sw $s5,12($sp)
sw $s4,16($sp)
sw $s2,24($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s2
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
li, $v0, 0
add $sp, $sp, 52
jr $ra

