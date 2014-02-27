/*
 *Filename: maskPassPhrase.s
 *Author: Louis Lesmana
 *Userid: cs30xds
 *Description: SPARC Assembly routine convert passphrase to masks
 *Date: 02/03/2014
 *Sources of Help:Lecture Notes, Discussion
 */

    .global maskPassPhrase               ! Declares the symbol to be globally
                                         ! visible so
                                         ! we can call this funtion
                                         ! from toher modules.
    .section ".text"                     ! The text segments begins here

    LONG = 4                             ! Define size of long

/* Function name: maskPassPhrase()
 * Function prototype: void maskPassPhrase( unsigned long keys[], 
   			char passPhrase[], unsigned long mask[] );
 * Description: xor keys to masks
 * Parameters: arg1,2: keys, phrases, mask
 * Side Effects: passpharase converted
 * Error Conditions: none
 * Return Value: none
 * Registers Used:
 * %i0-2 :params
 * %l0-5 :keys, passphrases and masks
*/

maskPassPhrase:

        save    %sp, -96, %sp                   ! Save caller's window

        ld      [%i0], %l0                      ! load 1st key
        add     %i0, LONG, %i0                  ! Traverse to keys[1]
        ld      [%i0], %l1                      ! load 2nd key

        ld      [%i1], %l2                      ! load pasphrase first
        add     %i1, 4, %i1                     ! traverse passPhrase[4]
        ld      [%i1], %l3                      ! load passphrase second

        xor     %l2, %l0, %l4                   ! first mask
        xor     %l3, %l1, %l5                   ! second mask

        st      %l4, [%i2]                      ! store first mask
        add     %i2, LONG, %i2                  ! traverse to mask[1]
        st      %l5, [%i2]                      ! store second mask

        ret                                     ! return from subroutine
        restore                                 ! Restore caller's window;
                                                ! in "ret" delay slot












