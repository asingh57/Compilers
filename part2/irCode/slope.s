main:

sub $sp, $sp, 32
move $v1, $sp

sub $sp, $sp, 48

lw $s7,8($v1)
li $s7,1

sw $s7,8($v1)
lw $s7,0($v1)
lw $s6,8($v1)
move $s7,$s6

sw $s7,0($v1)
sw $s6,8($v1)
lw $s7,12($v1)
li $s7,2

sw $s7,12($v1)
lw $s7,4($v1)
lw $s6,12($v1)
move $s7,$s6

sw $s7,4($v1)
sw $s6,12($v1)
lw $s7,12($v1)
lw $s6,8($v1)
lw $s5,0($sp)
sub $s5,$s7,$s6

sw $s7,12($v1)
sw $s6,8($v1)
sw $s5,0($sp)
lw $s7,20($v1)
lw $s6,0($sp)
move $s7,$s6

sw $s7,20($v1)
sw $s6,0($sp)
lw $s7,4($v1)
lw $s6,0($v1)
lw $s5,4($sp)
sub $s5,$s7,$s6

sw $s7,4($v1)
sw $s6,0($v1)
sw $s5,4($sp)
lw $s7,24($v1)
lw $s6,4($sp)
move $s7,$s6

sw $s7,24($v1)
sw $s6,4($sp)
lw $s7,20($v1)
lw $s6,24($v1)
lw $s5,8($sp)
div $s7,$s6
mflo $s5

sw $s7,20($v1)
sw $s6,24($v1)
sw $s5,8($sp)
lw $s7,16($v1)
lw $s6,8($sp)
move $s7,$s6

sw $s7,16($v1)
sw $s6,8($sp)
lw $s7,16($v1)
lw $s6,4($v1)
lw $s5,12($sp)
mult $s7,$s6
mflo $s5

sw $s7,16($v1)
sw $s6,4($v1)
sw $s5,12($sp)
lw $s7,12($v1)
lw $s6,12($sp)
lw $s5,16($sp)
sub $s5,$s7,$s6

sw $s7,12($v1)
sw $s6,12($sp)
sw $s5,16($sp)
lw $s7,28($v1)
lw $s6,16($sp)
move $s7,$s6

sw $s7,28($v1)
sw $s6,16($sp)
lw $s7,4($v1)
li $s7,7

sw $s7,4($v1)
lw $s7,16($v1)
lw $s6,4($v1)
lw $s5,20($sp)
mult $s7,$s6
mflo $s5

sw $s7,16($v1)
sw $s6,4($v1)
sw $s5,20($sp)
lw $s7,20($sp)
lw $s6,28($v1)
lw $s5,24($sp)
add $s5,$s6,$s7

sw $s7,20($sp)
sw $s6,28($v1)
sw $s5,24($sp)
lw $s7,12($v1)
lw $s6,24($sp)
move $s7,$s6

sw $s7,12($v1)
sw $s6,24($sp)
lw $s7,4($v1)
lw $s6,0($v1)
lw $s5,28($sp)
sub $s5,$s7,$s6

sw $s7,4($v1)
sw $s6,0($v1)
sw $s5,28($sp)
lw $s7,12($v1)
lw $s6,8($v1)
lw $s5,32($sp)
sub $s5,$s7,$s6

sw $s7,12($v1)
sw $s6,8($v1)
sw $s5,32($sp)
lw $s7,32($sp)
lw $s6,28($sp)
lw $s5,36($sp)
div $s7,$s6
mflo $s5

sw $s7,32($sp)
sw $s6,28($sp)
sw $s5,36($sp)
lw $s7,16($v1)
lw $s6,36($sp)
move $s7,$s6

sw $s7,16($v1)
sw $s6,36($sp)
lw $s7,40($sp)
li $s7,0

sw $s7,40($sp)
lw $s7,16($v1)

li $s6,1
bne $s7,$s6,_if_label_0

sw $s7,16($v1)

lw $s7,40($sp)
li $s7,1

sw $s7,40($sp)
_if_label_0:

lw $s7,40($sp)

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




sw $s7,40($sp)
lw $s7,44($sp)
li $s7,0

sw $s7,44($sp)
lw $s7,28($v1)

li $s6,0
bne $s7,$s6,_if_label_1

sw $s7,28($v1)

lw $s7,44($sp)
li $s7,1

sw $s7,44($sp)
_if_label_1:

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
add $sp, $sp, 32
add $sp, $sp, 48
jr $ra

