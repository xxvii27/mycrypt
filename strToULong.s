/*
 *Filename: strToULong.s
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: Assembly routine converting string to Ulong
 *Date: 02/1/2014
 *Sources of Help:Lecture Notes, Discussion
 */

    .global     strToULong  ! Declares the symbol to be globally visible so
                            ! we can call this funtion from other modules.

    .section    ".data"     ! Data section begins here

conv:
    .asciz      "\n\tConverting \"%s\" base \"%d\""

notint:
    .asciz      "\n\t\"%s\" is not an integer\n\n"

newline:
    .asciz      "\n"

    .section    ".text"     ! The text segments begins here

    OFFSET = 1028           ! Define constants - local var to allocate * bytes

    BUFSIZE = 1024          ! Constant snprintf

/* Function name: strToULong()
 * Function prototype: long strToULong( char *str, int base );
 * Description: Convert line argument string to Ulong for processing
 * Parameters: arg1: str-the string, base - integer base for conversion 
 * Side Effects: None
 * Error Conditions: -Number too long - Number validity
 * checks to ensure struct data are correct type/values.
 * Return Value: long
 * Registers Used;
 * %i0,1 : parameters
 * l0,1,2,3 : local variables
 * o0,1,2,3,4: pass to functions
 */


strToULong:

    save    %sp, -(92 + OFFSET) & -8, %sp   ! Save caller's window

    set     errno, %l0                      ! get errno to Registers
    st      %g0, [%l0]                      ! errno = 0

    mov     %i0, %o0                        ! pass str to first param
    add     %fp, -4, %o1                    ! endptr to second param
    mov     %i1, %o2                        ! Base 0 as 3rd param
    call    strtoul                         ! call strtoul
    nop

    mov     %o0, %l2                        ! save num return value

    ld      [%fp-4], %l1                    ! obtain endptr value
    ldub    [%l1], %l1                      ! dereference pointer
    cmp     %l1, %g0                        ! compare if '\0'
    be      end_ifptr                       ! branch if pointer error
    nop

    mov     1, %l3                          ! set true value to a reg
    st      %l3, [%l0]                      ! set errno to true
    set     stdError, %o0                   ! obtain stderr
    ld      [%o0], %o0                      ! dereference
    set     notint, %o1                     ! pass formatstring
    mov     %i0, %o2                        ! pass str
    call    fprintf, 3                      ! call fprintf - # of params
    nop

    ba      end_iferrno                     ! prevent invalid error messages
    nop

end_ifptr:

    ld      [%l0], %l0                      ! get errno
    cmp     %l0, %g0                        ! check for erro stat
    be      end_iferrno                     ! Branch if error exist
    nop

    add     %fp, -1028, %o0                 ! set array
    mov     BUFSIZE, %o1                    ! set buffersize
    set     conv, %o2                       ! set formatstring
    mov     %i0, %o3                        ! pass str
    mov     %i1, %o4                        ! pass base
    call    snprintf, 5                     ! call Function
    nop

    add     %fp, -1028, %o0                 ! set message
    call    perror                          ! call
    nop

    set     newline, %o0                    ! set additional newline
    call    printf, 1                       ! print it
    nop

end_iferrno:

    mov     %l2, %i0                        ! set return value

    ret                                     ! return from subroutine
    restore                                 ! Restore caller's window
                                            ! in "ret" delay slot






