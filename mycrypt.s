/*
 *Filename: mycrypt.s
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: Assembly routine to encrypt/decrypt data from the user
 *Date: 02/7/2014
 *Sources of Help:Lecture Notes, Discussion
 */

    .global     mycrypt     ! Declares the symbol to be globally visible so
                            ! we can call this funtion from other modules.

    .section    ".text"     ! The text segments begins here

    BUFSIZE = 1024          ! Constant buffer
    WORD = 4                ! Constant array mask traversal, for words
    CHAR = 1                ! sizeof Char


/* Function name: mycrypt()
 * Function prototype: void mycrypt( FILE *inFile, 
                       unsigned long mask[], int rotateValue );
 * Description: encrypt/decrypt data from the user using keys and masks
 * Parameters: arg1,2,3 inputfile, mask, rotatecount
 * Side Effects: data encrypted/decrypted
 * Error Conditions: as listed in called functions
 * Return Value: none
 * Registers Used;
 * 
 */

mycrypt:

    save        %sp, -(92 + BUFSIZE) & -8, %sp  ! Save caller's window

    add         %fp, -BUFSIZE, %o0              ! pass buffer
    mov         CHAR, %o1                       ! sizeof(char)
    mov         BUFSIZE, %o2                    ! sizeof(buf)
    mov         %i0, %o3                        ! pass inFile
    call        fread, 4                        ! call fread
    nop

    cmp         %o0, 0                          ! compare-length
    be          endloop_one                     ! branch over
    nop

loop_one:

    clr         %l7                             ! counter for byteproc
    mov         %o0, %l6                        ! make length copy
    mov         -BUFSIZE, %l5                   ! move BUFSIZE, for trav

    cmp         %l7, %l6                        ! byte traverse loop
    bge         endloop_two
    nop

loop_two:

    sub         %l6, %l7, %l4                   ! sub differenceof bytes

    cmp         %l4, 8                          ! check if less than 8
    bl          endloop_two                     ! break if less than 8
    nop

    ld          [%i1], %l0                      ! get mask[0]
    add         %i1, WORD, %i1                  ! go to mask[1]
    ld          [%i1], %l1                      ! get mask[1]
    sub         %i1, WORD, %i1                  ! go back

    ld          [%fp+%l5], %l2                  ! ld 4 byte chunks
    xor         %l2, %l0, %l2                   ! mask with mask[0]
    st          %l2, [%fp+%l5]                  ! store masked

    add         %l5, WORD, %l5                  ! go next 4

    ld          [%fp+%l5], %l3                  ! ld next 4 bytes
    xor         %l3, %l1, %l3                   ! mask this one
    st          %l3, [%fp+%l5]                  ! store masked

    add         %l5, WORD, %l5                  ! go next 4 for next iteration

    mov         %i2, %o1                        ! move rotateValue
    mov         %i1, %o0                        ! rotate mask
    call        rotate
    nop

    add         %l7, 8, %l7                     ! 8 bytes processed

    cmp         %l7, %l6                        ! byte traverse loop
    bl          loop_two
    nop

endloop_two:

    clr         %l7                             ! prepare to reuse counter

    cmp         %l7, %l4                        ! compare with remaining
    bge         endloop_three
    nop

loop_three:

    ldub        [%fp+%l5], %l3                  ! load 1 byte
    ldub        [%i1], %l0                      ! get 1 byte mask

    xor         %l3, %l0, %l3                   ! encrypt
    stb         %l3, [%fp+%l5]                  ! store

    inc         %l5                             ! move 1 byte
    inc         %i1                             ! move 1 byte

    inc         %l7                             ! increment

    cmp         %l7, %l4                        ! traverse
    bl          loop_three
    nop

endloop_three:

    add         %fp, -BUFSIZE, %o0              ! pass buffer
    mov         CHAR, %o1                       ! sizeof char
    mov         %l6, %o2                        ! pass length
    set         stdOutput, %o3                  ! get address
    ld          [%o3], %o3                      ! dereference
    call        fwrite, 4                       ! write to stdout

    add         %fp, -BUFSIZE, %o0              ! pass buffer
    mov         CHAR, %o1                       ! sizeof(char)
    mov         BUFSIZE, %o2                    ! sizeof(buf)
    mov         %i0, %o3                        ! pass inFile
    call        fread, 4                        ! call fread
    nop

    cmp         %o0, 0                          ! compare-length
    bne         loop_one                        ! branch over
    nop

endloop_one:

    ret
    restore




