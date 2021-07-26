

main:





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


sub $sp, $sp, 4
sw $ra,0($sp)

li $v0, 1
li $a0, 0
syscall
addi $a0, $0, 0xA 
addi $v0, $0, 0xB
syscall
lw $ra,0($sp)
add $sp, $sp, 4




li, $v0, 0
jr $ra

