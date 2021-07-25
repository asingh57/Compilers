main:

sub $sp, $sp, 48

lw $s7,40($sp)
li $s7,2

sw $s7,40($sp)
lw $s7,0($sp)
li $s7,1

sw $s7,0($sp)
lw $s7,4($sp)
li $s7,10

sw $s7,4($sp)
lw $s7,16($sp)
li $s7,2

sw $s7,16($sp)
lw $s7,16($sp)

slti$s6,$s7,0
beq $s6,$zero,Label_0

sw $s7,16($sp)

Label_1:

lw $s7,0($sp)
lw $s6,4($sp)
lw $s5,4($sp)
div $s7,$s5
mflo $s5

sw $s7,0($sp)
sw $s5,4($sp)
sw $s5,4($sp)
lw $s7,16($sp)
lw $s6,16($sp)

li $s5,0
sub $s6,$s5,$s6

sw $s6,16($sp)
sw $s6,16($sp)

Label_0:

lw $s7,16($sp)

li $s6,0
beq $s7,$s6,Label_2

sw $s7,16($sp)

Label_3:

lw $s7,4($sp)
lw $s6,0($sp)
lw $s5,0($sp)
mult $s7,$s5
mflo $s5

sw $s7,4($sp)
sw $s5,0($sp)
sw $s5,0($sp)
lw $s7,16($sp)
lw $s6,16($sp)

addi $s6,$s6,-1

sw $s6,16($sp)
sw $s6,16($sp)

j Label_0

Label_2:

lw $s7,44($sp)
lw $s6,0($sp)
move $s7,$s6

sw $s7,44($sp)
sw $s6,0($sp)
lw $s7,44($sp)

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



sw $s7,44($sp)
lw $s7,20($sp)
li $s7,1

sw $s7,20($sp)
lw $s7,24($sp)
lw $s6,40($sp)
move $s7,$s6

sw $s7,24($sp)
sw $s6,40($sp)
lw $s7,28($sp)
li $s7,3

sw $s7,28($sp)
lw $s7,28($sp)

slti$s6,$s7,0
beq $s6,$zero,Label_4

sw $s7,28($sp)

Label_5:

lw $s7,20($sp)
lw $s6,24($sp)
lw $s5,24($sp)
div $s7,$s5
mflo $s5

sw $s7,20($sp)
sw $s5,24($sp)
sw $s5,24($sp)
lw $s7,28($sp)
lw $s6,28($sp)

li $s5,0
sub $s6,$s5,$s6

sw $s6,28($sp)
sw $s6,28($sp)

Label_4:

lw $s7,28($sp)

li $s6,0
beq $s7,$s6,Label_6

sw $s7,28($sp)

Label_7:

lw $s7,24($sp)
lw $s6,20($sp)
lw $s5,20($sp)
mult $s7,$s5
mflo $s5

sw $s7,24($sp)
sw $s5,20($sp)
sw $s5,20($sp)
lw $s7,28($sp)
lw $s6,28($sp)

addi $s6,$s6,-1

sw $s6,28($sp)
sw $s6,28($sp)

j Label_4

Label_6:

lw $s7,32($sp)
li $s7,1

sw $s7,32($sp)
lw $s7,36($sp)
li $s7,3

sw $s7,36($sp)
lw $s7,8($sp)
lw $s6,20($sp)
move $s7,$s6

sw $s7,8($sp)
sw $s6,20($sp)
lw $s7,8($sp)

slti$s6,$s7,0
beq $s6,$zero,Label_8

sw $s7,8($sp)

Label_9:

lw $s7,32($sp)
lw $s6,36($sp)
lw $s5,36($sp)
div $s7,$s5
mflo $s5

sw $s7,32($sp)
sw $s5,36($sp)
sw $s5,36($sp)
lw $s7,8($sp)
lw $s6,8($sp)

li $s5,0
sub $s6,$s5,$s6

sw $s6,8($sp)
sw $s6,8($sp)

Label_8:

lw $s7,8($sp)

li $s6,0
beq $s7,$s6,Label_10

sw $s7,8($sp)

Label_11:

lw $s7,36($sp)
lw $s6,32($sp)
lw $s5,32($sp)
mult $s7,$s5
mflo $s5

sw $s7,36($sp)
sw $s5,32($sp)
sw $s5,32($sp)
lw $s7,8($sp)
lw $s6,8($sp)

addi $s6,$s6,-1

sw $s6,8($sp)
sw $s6,8($sp)

j Label_8

Label_10:

lw $s7,44($sp)
lw $s6,32($sp)
move $s7,$s6

sw $s7,44($sp)
sw $s6,32($sp)
lw $s7,44($sp)

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



sw $s7,44($sp)
li, $v0, 0
add $sp, $sp, 48
jr $ra

