

main:

sub $sp, $sp, 12

lw $s7,0($sp)
lw $s6,4($sp)

lw $s4,8($sp)
li $s7,1

li $s6,2

li $s4,3

sw $s7,0($sp)
sw $s6,4($sp)
sw $s4,8($sp)

slt $s5,$s6,$s7
beq $s5,$zero,Label_1

Label_0:


lw $s6,4($sp)
lw $s5,8($sp)
sw $s6,4($sp)
sw $s5,8($sp)

slt $s7,$s5,$s6
beq $s7,$zero,Label_4

Label_3:


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




j Label_5

Label_4:


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

j Label_2

Label_1:


lw $s6,4($sp)
lw $s5,8($sp)
sw $s6,4($sp)
sw $s5,8($sp)

slt$s7,$s6,$s5
beq $s7,$zero,Label_7

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




j Label_8

Label_7:


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




Label_8:

Label_2:

li, $v0, 0
add $sp, $sp, 12
jr $ra

