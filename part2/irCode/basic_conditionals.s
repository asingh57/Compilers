

main:

sub $sp, $sp, 12

lw $s7,0($sp)

lw $s5,4($sp)
lw $s4,8($sp)
li $s7,1

li $s5,2

li $s4,3

sw $s7,0($sp)
sw $s5,4($sp)
sw $s4,8($sp)

slti $s6,$s7,1
bne $s6,$zero,Label_2

Label_0:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 1
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




Label_2:


lw $s6,0($sp)
sw $s6,0($sp)

slti$s7,$s6,2
beq $s7,$zero,Label_5

Label_3:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 2
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




Label_5:


lw $s6,4($sp)
sw $s6,4($sp)

li $s7,2
bne $s6,$s7,Label_8

Label_6:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 3
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




Label_8:


lw $s6,4($sp)
sw $s6,4($sp)

li $s7,4
beq $s6,$s7,Label_11

Label_9:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 4
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




Label_11:


lw $s6,8($sp)
sw $s6,8($sp)

slti$s7,$s6,0
bne $s7,$zero,Label_13

Label_12:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 5
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




j Label_14

Label_13:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 6
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




Label_14:


lw $s6,8($sp)
sw $s6,8($sp)

li $s7,0
slt$s7,$s7,$s6
bne $s7,$zero,Label_16

Label_15:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 7
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




j Label_17

Label_16:


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 8
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




Label_17:

li, $v0, 0
add $sp, $sp, 12
jr $ra

