.data

n: .word 4                             # number of test cases
ins:  .word    0,   5,   10,      100  # input numbers
outs: .word    0, 170, 2640, 25164150  # expected result

failmsg: .asciiz "failed for test input: "
expectedmsg: .asciiz ". expected "
tobemsg: .asciiz " to be "
okmsg: .asciiz "all tests passed"


.text

runner:
        lw      $s0, n
        la      $s1, ins
        la      $s2, outs

run_test:
        lw      $s3, 0($s1)             # read input from memory
        move    $a0, $s3                # move it to a0
        jal     difference_of_squares   # call subroutine under test
        move    $v1, $v0                # move return value in v0 to v1 because we need v0 for syscall

        lw      $s4, 0($s2)             # read expected output from memory
        bne     $v1, $s4, exit_fail     # if expected doesn't match actual, jump to fail

        addi    $s1, $s1, 4             # move to next word in input
        addi    $s2, $s2, 4             # move to next word in output
        sub     $s0, $s0, 1             # decrement num of tests left to run
        bgt     $s0, $zero, run_test    # if more than zero tests to run, jump to run_test

exit_ok:
        la      $a0, okmsg              # put address of okmsg into a0
        li      $v0, 4                  # 4 is print string
        syscall

        li      $v0, 10                 # 10 is exit with zero status (clean exit)
        syscall

exit_fail:
        la      $a0, failmsg            # put address of failmsg into a0
        li      $v0, 4                  # 4 is print string
        syscall

        move    $a0, $s3                # set arg of syscall to input that failed the test
        li      $v0, 1                  # 1 is print int
        syscall

        la      $a0, expectedmsg
        li      $v0, 4
        syscall

        move    $a0, $v1                # print actual that failed on
        li      $v0, 1
        syscall

        la      $a0, tobemsg
        li      $v0, 4
        syscall

        move    $a0, $s4                # print expected value that failed on
        li      $v0, 1
        syscall
        
.text
.globl difference_of_squares
difference_of_squares:
    beqz $a0, const_done
    move $v0, $zero
    j square_of_sum

square_of_sum:
    li $t0, 1                               # int sum = 1
    li $t1, 0                               # counter
    j square_of_sum.loop

square_of_sum.loop:
    addu $t0, $t0, $t1
    bne $t1, $a0, square_of_sum.loop
    addiu $t1, $t1, 1                       # increment counter
    j square_of_sum.done

square_of_sum.done:
    mult $t0, $t0
    mflo $t0
    #move $a0, $t0
    #li $v0, 1
    #syscall

sum_of_squares:
    li $t1, 1                               # int sum = 1
    li $t2, 0                               # counter
    move $t4, $zero
    j sum_of_squares.loop

sum_of_squares.loop:
    addiu $t2, $t2, 1                       # increment counter
    mult $t1, $t1
    move $t4, $t3
    mflo $t3
    addu $t1, $t1, 1
    addu $t3, $t3, $t4
    bne $t2, $a0, sum_of_squares.loop
    j done

done:
    move $a0, $t3
    li $v0, 1
    syscall

    subu $v0, $t0, $t3
    jr $ra

const_done:
    move $a0, $t3
    li $v0, 1
    syscall
    move $v0, $zero
    jr $ra