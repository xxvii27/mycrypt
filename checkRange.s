/*
 *Filename: checkRange.s
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: SPARC Assembly routine to check number is in range
 *             Called from main() and numOfDigits().
 *Date: 01/21/2014
 *Sources of Help:Lecture Notes, Discussion
 */

    .global checkRange      !Declares the symbol to be globally visible so
                            !we can call this funtion from toher modules.
    .section ".text"        ! The text segments begins here

/* Function name: checkRange()
 * Function prototype: int checkRange( long value, 
 			long minRange, long maxRange );
 * Description: Check value is in min-max range
 * Parameters: arg1,2,3: value, minrange, maxrange, value to bechecked and
 *             boundaries.
 * Side Effects: None
 * Error Conditions: value outside range.
 * Return Value: 1 or 0, indicating true/false
 * Registers Used:
 *  %i0 - arg1 - the num passed by
 *  %i1 - arg2 - boundaries
 *  %i2 - arg3 - boundaries
 *  %o0 - param1 to cmp    -- for operation and comparison
 *  %o1, %o2 - param2 to cmp -- for operation and comparison
 */

checkRange:
        save    %sp, -96, %sp   ! Save caller's window; if different than -96
                                ! then comment on how that value was calculated.

        mov     %i0, %o0        ! Parameter num to register
        mov     %i1, %o1        ! second register parameter
        mov     %i2, %o2        ! third register parameter
        mov     1, %i0          ! set return true as default

        cmp     %o0, %o1        ! compare value to minValue
        bge     end_if          ! branch to end_if
        nop

        mov     0, %i0          ! setreturn false below min range
        ba      end_iftwo       ! move directly to end
        nop

end_if:

        cmp     %o0, %o2        ! comparing and branches, for 2nd cond
        ble     end_iftwo
        nop

        mov     0, %i0          ! setreturn false above max range

end_iftwo:

        ret                     ! return from subroutine
        restore                 ! Restore caller's window; in "ret" delay slot












