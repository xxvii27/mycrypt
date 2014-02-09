/*
 *Filename: rotate.s
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: SPARC Assembly rotate bits
 *Date: 02/03/2014
 *Sources of Help:Lecture Notes, Discussion
 */

    .global rotate               ! Declares the symbol to be globally visible so
                                 ! we can call this funtion from toher modules.
    .section ".text"             ! The text segments begins here



    MASK_LOWER_6 = 0x3F          ! mask constants
    MASK_HIGH_BIT = 0x80000000
    MASK_LOW_BIT = 0x1

    LONG = 4                     ! sizeof long
    BITSHIFT = 31                ! end to end 32 bit distance


/* Function name: rotate()
 * Function prototype: void rotate( unsigned long mask[], int rotateCnt );
 * Description: rotate left while count positive else rotate right
 * Parameters: arg1,2: mask to rotate, and the count
 * Side Effects: mask rotated
 * Error Conditions: none
 * Return Value: none
 * Registers Used: i0, 1 (input registers); l0-4,6(bit manip/loop);
 * 
*/

rotate:

        save    %sp, -96, %sp               ! Save caller's window

        ld      [%i0],  %l0                 ! Get mask1
        add     %i0, LONG, %i0              ! traverse mask[1]
        ld      [%i0],  %l1                 ! Get mask2
        set     MASK_HIGH_BIT, %l2          ! set mask to l2
        clr     %l6                         ! loop count

        cmp     %i1, 0                      ! check rotateCnt pos/neg
        ble     else
        nop

        and     %i1, MASK_LOWER_6, %i1      ! get lower 6

        cmp     %l6, %i1                    ! loop check
        bge     endloop
        nop

loop:

        and     %l0, %l2, %l3               ! clear bits
        and     %l1, %l2, %l4               ! clear bits

        srl     %l3, BITSHIFT, %l3          ! shift bit to pos
        srl     %l4, BITSHIFT, %l4          ! shift bit to pos

        sll     %l0, 1, %l0                 ! shift bit make space
        sll     %l1, 1, %l1                 ! shift bit make space

        or      %l0, %l4, %l0               ! put lower to up
        or      %l1, %l3, %l1               ! put upper to low

        inc     %l6                         ! increment

        cmp     %l6, %i1                    ! traverse
        bl      loop
        nop

endloop:

        st      %l1, [%i0]                  ! store rotation
        sub     %i0, LONG, %i0              ! Go to mask[0]
        st      %l0, [%i0]                  ! store value

        ba      endif                       ! end if
        nop

else:

        neg     %i1                         ! flip count to positive
        and     %i1, MASK_LOWER_6, %i1      ! get lower 6

        cmp     %l6, %i1                    ! loop check
        bge     endlooptwo
        nop

looptwo:

        and     %l0, MASK_LOW_BIT, %l3      ! clear bits
        and     %l1, MASK_LOW_BIT, %l4      ! clear bits

        sll     %l3, BITSHIFT, %l3          ! shift to pos
        sll     %l4, BITSHIFT, %l4          ! Shift to pos

        srl     %l0, 1, %l0                 ! shift bit make space
        srl     %l1, 1, %l1                 ! shift bit make space

        or      %l0, %l4, %l0               ! put lower to up
        or      %l1, %l3, %l1               ! put upper to low

        inc     %l6                         ! increment

        cmp     %l6, %i1                    ! traverse
        bl      looptwo
        nop

endlooptwo:

        st      %l1, [%i0]                  ! store rotation
        sub     %i0, LONG, %i0              ! Go to mask[0]
        st      %l0, [%i0]                  ! store value

endif:

        ret                                 ! return from subroutine
        restore                             ! Restore caller's window;
                                            ! in "ret" delay slot












