############


############
main:

sub $sp, $sp, 28

la $s7,16($sp)
lw $s6,0($sp)
lw $s5,4($sp)
lw $s4,8($sp)
lw $s3,12($sp)


li $s2,10
sw $s2,0($s7)

li $s1,20
sw $s1,4($s7)

lw $s6,0($s7)

lw $s5,4($s7)

add $s4,$s5,$s6

sw $s4,8($s7)

lw $s3,8($s7)

sw $s4,8($sp)



sw $s6,0($sp)
sw $s5,4($sp)
sw $s3,12($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s3
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
li, $v0, 0
add $sp, $sp, 28
jr $ra

