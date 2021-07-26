

main:

sub $sp, $sp, 60

lw $s7,0($sp)
lw $s6,56($sp)
lw $s5,48($sp)
lw $s4,52($sp)
li $s5,5

li $s4,5

li $s7,300

move $s6,$s7

sw $s5,48($sp)
sw $s4,52($sp)
sw $s6,56($sp)
sw $s7,0($sp)

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




lw $s7,4($sp)
lw $s6,56($sp)
lw $s5,48($sp)
addi $s7,$s5,50

move $s6,$s7

sw $s5,48($sp)
sw $s7,4($sp)
sw $s6,56($sp)

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




lw $s7,16($sp)
lw $s6,56($sp)
lw $s5,48($sp)
lw $s4,52($sp)
add $s7,$s4,$s5

move $s6,$s7

sw $s7,16($sp)
sw $s5,48($sp)
sw $s4,52($sp)
sw $s6,56($sp)

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




lw $s7,20($sp)
lw $s6,56($sp)

li $s7,100

move $s6,$s7

sw $s7,20($sp)

sw $s6,56($sp)

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




lw $s7,24($sp)
lw $s6,56($sp)

lw $s4,48($sp)
addi $s7,$s4,-50

move $s6,$s7

sw $s4,48($sp)
sw $s7,24($sp)

sw $s6,56($sp)

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




lw $s7,28($sp)
lw $s6,56($sp)
lw $s5,48($sp)
lw $s4,52($sp)
sub $s7,$s5,$s4

move $s6,$s7

sw $s5,48($sp)
sw $s4,52($sp)
sw $s7,28($sp)
sw $s6,56($sp)

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




lw $s7,32($sp)
lw $s6,56($sp)

li $s7,20000

move $s6,$s7

sw $s7,32($sp)

sw $s6,56($sp)

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




lw $s7,36($sp)
lw $s6,56($sp)

lw $s4,48($sp)
li $s5,50
mult $s5,$s4
mflo $s7

move $s6,$s7

sw $s4,48($sp)
sw $s7,36($sp)

sw $s6,56($sp)

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




lw $s7,40($sp)
lw $s6,56($sp)
lw $s5,48($sp)
lw $s4,52($sp)
mult $s5,$s4
mflo $s7

move $s6,$s7

sw $s5,48($sp)
sw $s4,52($sp)
sw $s6,56($sp)
sw $s7,40($sp)

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




lw $s7,44($sp)
lw $s6,56($sp)

li $s7,2

move $s6,$s7

sw $s7,44($sp)

sw $s6,56($sp)

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




lw $s7,8($sp)
lw $s6,56($sp)

lw $s4,48($sp)
li $s5,1
div $s4,$s5
mflo $s7

move $s6,$s7


sw $s4,48($sp)
sw $s7,8($sp)
sw $s6,56($sp)

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




lw $s7,12($sp)
lw $s6,56($sp)
lw $s5,48($sp)
lw $s4,52($sp)
div $s5,$s4
mflo $s7

move $s6,$s7

sw $s7,12($sp)
sw $s5,48($sp)
sw $s4,52($sp)
sw $s6,56($sp)

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




li, $v0, 0
add $sp, $sp, 60
jr $ra

