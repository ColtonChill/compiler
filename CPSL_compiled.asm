.data
str1: .asciiz "This program contains a function/procedure feature, This functionality is not yet implemented. Sorry for the inconvenience."

str0: .asciiz "\n"
.text #bool key words
li $t0,1
sw $t0,0($gp) #True
li $t0,0
sw $t0,4($gp) #False

#_VarBlock
# VarDeclStm called int
# a int 8
# b int 12
#_FunctionCopout
.globl main
main:
la $t0, str1
li $v0, 4
move $a0, $t0
syscall
exit_main:
