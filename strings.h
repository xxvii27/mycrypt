/*
 * Filename: strings.h
 * Author: TODO: Louis Lesmana
 * Userid: TODO: cs30xds 
 * Description: Strings used in PA2 output
 */

#define STR_ENTER_KEYS "Enter the two 32-bit keys [octal, decimal, or hex]\n"\
                        "\tseparated by a space or tab: "

#define STR_ERR_NO_KEYS "\n\tNo keys entered. You must enter 2 keys.\n\n"
#define STR_ERR_ONE_KEY "\n\tOnly 1 key entered. You must enter 2 keys.\n\n"

#define STR_ENTER_PASSPHRASE "Enter the passphrase [at least %d chars]: "
#define STR_ERR_BAD_PASSPHRASE "\n\tPassphrase must be at least %d chars long;"\
                               " Try again.\n\n"

#define STR_ENTER_ROTATION "Enter the rotation key [%d <-> +%d]: "
#define STR_ERR_NO_ROTATION	"\n\tNo rotation key entered; Try again.\n\n"
#define STR_ERR_BAD_ROTATION "\n\tRotation key must be within the range of "\
                             "[%d <-> %d]\n\n"

#define STR_STRTOULONG_CONVERTING "\n\tConverting \"%s\" base \"%d\""
#define STR_STRTOULONG_NOTINT "\n\t\"%s\" is not an integer\n\n"

#define STR_USAGE "\n\tUsage: %s filename | -\n\n"

#define STR_NEWLINE "\n"
