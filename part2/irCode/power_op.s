############


############
main:

sub $sp, $sp, 48

lw $s7,16($sp)

lw $s5,0($sp)
lw $s4,4($sp)
lw $s3,40($sp)
li $s3,2

li $s5,1

li $s4,10

li $s7,2

sw $s7,16($sp)
sw $s3,40($sp)
sw $s5,0($sp)
sw $s4,4($sp)

slti$s6,$s7,0
beq $s6,$zero,Label_0

############
Label_1:

lw $s7,4($sp)
lw $s6,16($sp)

lw $s4,0($sp)
div $s4,$s7
mflo $s7

li $s5,0
sub $s6,$s5,$s6

sw $s4,0($sp)
sw $s7,4($sp)
sw $s6,16($sp)

############
Label_0:


lw $s6,16($sp)
sw $s6,16($sp)

li $s7,0
beq $s6,$s7,Label_2

############
Label_3:

lw $s7,0($sp)
lw $s6,16($sp)

lw $s4,4($sp)
mult $s4,$s7
mflo $s7

addi $s6,$s6,-1

sw $s4,4($sp)
sw $s7,0($sp)
sw $s6,16($sp)

j Label_0

############
Label_2:

lw $s7,44($sp)
lw $s6,0($sp)
move $s7,$s6

sw $s7,44($sp)
sw $s6,0($sp)

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
lw $s7,28($sp)

lw $s5,20($sp)
lw $s4,24($sp)
lw $s3,40($sp)
li $s5,1

move $s4,$s3

li $s7,3

sw $s5,20($sp)
sw $s4,24($sp)
sw $s3,40($sp)
sw $s7,28($sp)

slti$s6,$s7,0
beq $s6,$zero,Label_4

############
Label_5:

lw $s7,24($sp)
lw $s6,28($sp)

lw $s4,20($sp)
div $s4,$s7
mflo $s7

li $s5,0
sub $s6,$s5,$s6

sw $s4,20($sp)
sw $s7,24($sp)
sw $s6,28($sp)

############
Label_4:


lw $s6,28($sp)
sw $s6,28($sp)

li $s7,0
beq $s6,$s7,Label_6

############
Label_7:

lw $s7,20($sp)
lw $s6,28($sp)

lw $s4,24($sp)
mult $s4,$s7
mflo $s7

addi $s6,$s6,-1

sw $s4,24($sp)
sw $s7,20($sp)
sw $s6,28($sp)

j Label_4

############
Label_6:

lw $s7,8($sp)

lw $s5,20($sp)
lw $s4,32($sp)
lw $s3,36($sp)
li $s4,1

li $s3,3

move $s7,$s5

sw $s4,32($sp)
sw $s3,36($sp)
sw $s7,8($sp)
sw $s5,20($sp)

slti$s6,$s7,0
beq $s6,$zero,Label_8

############
Label_9:

lw $s7,8($sp)
lw $s6,36($sp)

lw $s4,32($sp)
div $s4,$s6
mflo $s6

li $s5,0
sub $s7,$s5,$s7

sw $s4,32($sp)
sw $s6,36($sp)
sw $s7,8($sp)

############
Label_8:


lw $s6,8($sp)
sw $s6,8($sp)

li $s7,0
beq $s6,$s7,Label_10

############
Label_11:

lw $s7,8($sp)
lw $s6,32($sp)

lw $s4,36($sp)
mult $s4,$s6
mflo $s6

addi $s7,$s7,-1

sw $s4,36($sp)
sw $s6,32($sp)
sw $s7,8($sp)

j Label_8

############
Label_10:

lw $s7,44($sp)
lw $s6,32($sp)
move $s7,$s6

sw $s7,44($sp)
sw $s6,32($sp)

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
add $sp, $sp, 48
jr $ra

