############


############
main:

sub $sp, $sp, 24

lw $s7,0($sp)
lw $s6,4($sp)
lw $s5,8($sp)
lw $s4,12($sp)
lw $s3,16($sp)
lw $s2,20($sp)
li $s4,3

li $s3,4

li $s2,4

li $s7,1

li $s5,2

li $s6,2

sw $s4,12($sp)
sw $s3,16($sp)
sw $s2,20($sp)
sw $s7,0($sp)
sw $s5,8($sp)
sw $s6,4($sp)

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
lw $s6,8($sp)
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




sw $s7,4($sp)
sw $s6,8($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s6
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,12($sp)
lw $s6,16($sp)
sw $s7,12($sp)

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




sw $s7,12($sp)
sw $s6,16($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s6
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,20($sp)
sw $s7,20($sp)

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




li, $v0, 0
sw $s7,20($sp)
add $sp, $sp, 24
jr $ra

