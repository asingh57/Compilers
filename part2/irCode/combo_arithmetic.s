############



############
main:

sub $sp, $sp, 108

lw $s7,0($sp)
lw $s6,4($sp)
lw $s5,96($sp)
lw $s4,100($sp)
lw $s3,104($sp)
li $s5,5

li $s4,50

addi $s7,$s5,100

add $s6,$s4,$s7

move $s3,$s6

sw $s7,0($sp)
sw $s6,4($sp)
sw $s5,96($sp)
sw $s4,100($sp)
sw $s3,104($sp)


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
lw $s7,48($sp)
lw $s6,68($sp)
lw $s5,104($sp)

lw $s3,96($sp)
lw $s2,100($sp)
li $s4,100
sub $s7,$s4,$s3

sub $s6,$s7,$s2

move $s5,$s6

sw $s7,48($sp)
sw $s6,68($sp)
sw $s5,104($sp)

sw $s3,96($sp)
sw $s2,100($sp)


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s5
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,72($sp)
lw $s6,76($sp)
lw $s5,104($sp)

lw $s3,96($sp)
lw $s2,100($sp)
li $s4,100
mult $s4,$s3
mflo $s7

mult $s7,$s2
mflo $s6

move $s5,$s6

sw $s7,72($sp)
sw $s6,76($sp)
sw $s5,104($sp)

sw $s3,96($sp)
sw $s2,100($sp)


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s5
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,80($sp)
lw $s6,84($sp)
lw $s5,104($sp)

lw $s3,96($sp)
lw $s2,100($sp)
li $s4,500
div $s4,$s3
mflo $s7

div $s7,$s2
mflo $s6

move $s5,$s6

sw $s7,80($sp)
sw $s6,84($sp)
sw $s5,104($sp)

sw $s3,96($sp)
sw $s2,100($sp)


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s5
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,88($sp)
lw $s6,92($sp)
lw $s5,104($sp)

li $s7,50

addi $s6,$s7,25

move $s5,$s6

sw $s7,88($sp)
sw $s6,92($sp)
sw $s5,104($sp)



sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s5
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,8($sp)
lw $s6,12($sp)
lw $s5,104($sp)


li $s7,2

li $s3,25
mult $s3,$s7
mflo $s6

move $s5,$s6

sw $s7,8($sp)
sw $s6,12($sp)
sw $s5,104($sp)




sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s5
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,96($sp)
lw $s6,100($sp)
lw $s5,16($sp)
lw $s4,20($sp)
lw $s3,24($sp)
lw $s2,28($sp)
lw $s1,32($sp)
lw $s0,36($sp)
lw $t7,104($sp)
mult $s7,$s6
mflo $s5

add $s4,$s7,$s5

add $s3,$s6,$s4

sub $s2,$s3,$s7

div $s6,$s7
mflo $s1

sub $s0,$s2,$s1

move $t7,$s0

sw $s7,96($sp)
sw $s6,100($sp)
sw $s5,16($sp)
sw $s4,20($sp)
sw $s3,24($sp)
sw $s2,28($sp)
sw $s1,32($sp)
sw $s0,36($sp)
sw $t7,104($sp)


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $t7
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,40($sp)
lw $s6,44($sp)
lw $s5,52($sp)
lw $s4,104($sp)


li $s7,50

li $s6,5

sub $s5,$s7,$s6

move $s4,$s5

sw $s7,40($sp)
sw $s6,44($sp)
sw $s5,52($sp)
sw $s4,104($sp)




sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s4
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
lw $s7,56($sp)
lw $s6,60($sp)
lw $s5,64($sp)
lw $s4,104($sp)

lw $s2,96($sp)
lw $s1,100($sp)
mult $s1,$s2
mflo $s7

li $s3,100
sub $s6,$s3,$s7

addi $s5,$s6,7

move $s4,$s5

sw $s7,56($sp)
sw $s6,60($sp)
sw $s5,64($sp)
sw $s4,104($sp)

sw $s2,96($sp)
sw $s1,100($sp)


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
move $a0, $s4
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




############
li, $v0, 0

add $sp, $sp, 108
jr $ra

