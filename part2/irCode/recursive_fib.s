############


############
fib:

sub $sp, $sp, 32

lw $s7,4($sp)
lw $s6,8($sp)

li $s7,0

li $s6,0

sw $s7,4($sp)
sw $s6,8($sp)

li $s5,1
slt$s5,$s5,$a0
bne $s5,$zero,Label_1

############
Label_0:

move, $v0, $a0
add $sp, $sp, 32
jr $ra

############
Label_1:

lw $s7,12($sp)

lw $s5,16($sp)
addi $s7,$a0,-1


sw $s7,12($sp)
sw $s5,16($sp)

sub $sp, $sp, 8
sw $a0,4($sp)
sw $ra,0($sp)

move $a0,$s7
jal fib
move $s5,$v0
lw $a0,4($sp)
lw $ra,0($sp)
add $sp, $sp, 8




sw $s5,16($sp)
############
lw $s7,20($sp)
lw $s6,4($sp)

lw $s4,16($sp)
lw $s3,24($sp)
move $s6,$s4

addi $s7,$a0,-2

sw $s6,4($sp)

sw $s4,16($sp)
sw $s7,20($sp)
sw $s3,24($sp)

sub $sp, $sp, 8
sw $a0,4($sp)
sw $ra,0($sp)

move $a0,$s7
jal fib
move $s3,$v0
lw $a0,4($sp)
lw $ra,0($sp)
add $sp, $sp, 8




sw $s3,24($sp)
############
lw $s7,8($sp)
lw $s6,28($sp)
lw $s5,4($sp)
lw $s4,24($sp)
move $s7,$s4

add $s6,$s7,$s5

move, $v0, $s6
sw $s6,28($sp)
sw $s4,24($sp)
sw $s7,8($sp)
sw $s5,4($sp)
add $sp, $sp, 32
jr $ra

############
main:

sub $sp, $sp, 4
move $v1, $sp

sub $sp, $sp, 4

lw $s7,0($sp)
sw $s7,0($sp)

sub $sp, $sp, 4
sw $ra,0($sp)

li $a0,12
jal fib
move $s7,$v0
lw $ra,0($sp)
add $sp, $sp, 4




sw $s7,0($sp)
############
lw $s7,0($v1)
lw $s6,0($sp)
move $s7,$s6

sw $s6,0($sp)
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
add $sp, $sp, 4
jr $ra

