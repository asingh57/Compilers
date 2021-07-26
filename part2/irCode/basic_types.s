

main:

sub $sp, $sp, 12

lw $s7,8($sp)
lw $s6,0($sp)
lw $s5,4($sp)
li $s5,5

li $s7,10

add $s6,$s7,$s5

move $s7,$s6

sw $s5,4($sp)
sw $s7,8($sp)
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




li, $v0, 0
add $sp, $sp, 12
jr $ra

