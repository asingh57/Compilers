############


############
main:

sub $sp, $sp, 32
move $v1, $sp

lw $s7,4($v1)
lw $s6,12($v1)
lw $s5,16($v1)
lw $s4,8($v1)
lw $s3,0($v1)
lw $s2,0($sp)
lw $s1,36($sp)
lw $s0,4($sp)
lw $t7,8($sp)
lw $t6,12($sp)
lw $t5,16($sp)
lw $t4,20($sp)
sub $sp, $sp, 48

li $s4,1

move $s3,$s4

li $s6,2

move $s7,$s6

sub $s2,$s6,$s4

lw $t3,20($v1)
move $t3,$s2

sw $t3,20($v1)
sub $s0,$s7,$s3

lw $t3,24($v1)
move $t3,$s0

sw $t3,24($v1)
lw $t3,20($v1)
lw $t2,24($v1)
div $t3,$t2
mflo $t7

sw $t3,20($v1)
sw $t2,24($v1)
move $s5,$t7

mult $s5,$s7
mflo $t6

sub $t5,$s6,$t6

lw $t3,28($v1)
move $t3,$t5

sw $t3,28($v1)
li $s7,7

mult $s5,$s7
mflo $t4

lw $t3,28($v1)
lw $t2,24($sp)
add $t2,$t3,$t4

sw $t3,28($v1)
sw $t2,24($sp)
lw $t3,24($sp)
move $s6,$t3

sw $t3,24($sp)
lw $t3,28($sp)
sub $t3,$s7,$s3

sw $t3,28($sp)
lw $t3,32($sp)
sub $t3,$s6,$s4

sw $t3,32($sp)
lw $t3,32($sp)
lw $t2,28($sp)
div $t3,$t2
mflo $s1

sw $t3,32($sp)
sw $t2,28($sp)
move $s5,$s1

lw $t3,40($sp)
li $t3,0

sw $t3,40($sp)

sw $s7,4($v1)
sw $s4,8($v1)
sw $s6,12($v1)
sw $s3,0($v1)
sw $s2,0($sp)
sw $s0,4($sp)
sw $t7,8($sp)
sw $t4,20($sp)
sw $s5,16($v1)
sw $t6,12($sp)
sw $t5,16($sp)
sw $s1,36($sp)

li $t3,1
bne $s5,$t3,_if_label_0

############
lw $s7,40($sp)
li $s7,1

sw $s7,40($sp)
############
_if_label_0:

lw $s7,40($sp)
sw $s7,40($sp)

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

lw $s6,44($sp)
lw $s5,28($v1)
li $s6,0

sw $s5,28($v1)
sw $s6,44($sp)

li $s7,0
bne $s5,$s7,_if_label_1

############
lw $s7,44($sp)
li $s7,1

sw $s7,44($sp)
############
_if_label_1:

lw $s7,44($sp)
sw $s7,44($sp)

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
add $sp, $sp, 32
add $sp, $sp, 48
jr $ra

