.TH man 3 "19 April 2022" "0.10" "_printf man page"
.SH NAME
.B _printf

.SH NAME
.B _printf\fR \- formatted output conversion

.SH SYNOPSIS
.B #include \fB"main.h"

.B int printf(const char *\fIformat\fB, ...);

.SH DESCRIPTION
The function \fB_printf()\fR writes output to \fIstdout\fR, the standard 
output. The function writes under the control of a \fIformat\fR string that 
specifies how subsequent arguments (accessed via the variable-length argument 
		facilities of stdarg) are converted for output.

.B Return value
.in +2n
Upon successful return, \fB_printf()\fR returns the number of characters 
printed (excluding the null byte used to end output to strings).

If an output error is encountered, -1 is returned.
.in

.B Format of the format string
.in +2n
The format string is a constant character string composed of zero or more 
directives: ordinary characters (not \fB%\fR) which are copied unchanged to 
the output stream; and conversion specifications, each of which results in 
fetching zero or more subsequent arguments. Conversion specification is 
introduced by the character \fB%\fR and ends with a \fIconversion specifier\fR.

In between the \fB%\fR character and conversion specifier, there may be (in 
		order) zero or more \fIflags\fR, an optional minimum \fIfield width\fR, an 
optional \fIprecision\fR and an optional \fIlength\fR modifier. The arguments 
must correspond with the conversion specifier, and are used in the order given.
.in

.B Flag Characters
.in +2n
The character \fB%\fR may be followed by zero or more of the following flags:

.RS
.B #
.in +2n
For \fBo\fR conversions, the first character of the output string is prefixed 
with 0 if it was not zero already. For x and X converions, 0x or 0X, 
     respectively, is prepended for non-zero numbers.
     .in
     .RE

     .RS
     .B ''
     .in +2n
     (space) A blank is left before a positive number or empty string produced by a 
     signed conversion.
     .in
     .RE

     .RS
     .B +
     .in +2n
     A sign (+ or -) is always placed before a number produced by signed conversion.
     .in
     .RE

     .RS
     .B 0
     .in +2n
     For \fBd\fR, \fBi\fR, \fBo\fR, \fBu\fR, \fBx\fR, and \fBX\fR conversions, the 
     converted value is padded on the left with zeroes rather than blanks. If the 
     \fB0\fR flag is provided to a numeric conversion with a specified precision, 
     it is ignored.
     .in
     .RE

     .RS
     .B -
     .in +2n
     The converted value is left-justified (padded on the right with blanks instead 
		     of on the left with blanks or zeroes). Overrides a \fB0\fR flag.
     .in
     .RE

     .B Field Width
     .in +2n
     After flags, a minimum field width may be specified by a decimal digit string. 
     The first digit must be non-zero. If the converted value has fewer characters 
     than the provided width, the output is padded on the left or right with spaces 
     (depending on whether the \fB-\fR flag was provided).

     Alternatively, width may be provied as an argument using the '*' character. 
     For example, in the following:
     .in

     .in +2n
     _printf("%*d\\n", 6, 1);
     .in

     .in +2nn
     the argument 6 is considered the width for the conversion of the decimal 1.
     .in

     .B Precision
     .in +2n
     After any flags or provided width, a precision may be specified by a '.' 
     followed by a decimal digit string. For \fBd\fR, \fBi\fR, \fBo\fR, \fBu\fR, 
     \fBx\fR, and \fBX\fR conversions, the precision specifies the minimum number 
     of digits to appear. For \fBs\fR and \fBS\fR conversions, the precision 
     specifies the maximum characters to be printed.

     Alternatively, precision may be provided as an argument using the '*' character 
     after the '.'. For example, in the following:
     .in

     .in +2n
     _printf("%.*d\\n", 6, 1);
     .in

     .in +2n
     the argument 6 is considered the precision for the conversion of the decimal 1.
     .in

     .B Conversion Specifiers
     .in +2n
     A character that specifies the type of conversion to be applied. The 
     conversion specifiers and their meaning are:

     .RS
     .B d, i
     .in +2n
     The \fIint\fR argument is converted to signed decimal notation.
     .in
     .RE

     .RS
     .B b
     .in +2n
     The \fIunsigned int\fR argument is converted to binary.
     .in
     .RE

     .RS
     .B o, u, x, X
     .in +2n
     The \fIunsigned int\fR argument is converted to unsigned octal (\fBo\fR), 
     unsigned decimal (\fBu\fR), or unsigned hexadecimal (\fBx\fR and \fBX\fR) 
	notation. The letters \fBabcdef\fR are used for \fBx\fR conversions; the 
	letters \fBABCDEF\fR are used for \fBX\fR conversions.
	.in
	.RE

	.RS
	.B c
	.in +2n
	The \fIint\fR argument is converted to an \fIunsigned char\fR, and the 
	resulting character is written.
	.in
	.RE

	.RS
	.B s
	.in +2n
	The \fIconst char *\fR argument is expected to be a pointer to a character 
	array (pointer to a string). Characters from the array are written starting 
	from the first element of the array and ending at, but not including, the 
	terminating null byte ('\\0').
	.in
	.RE

	.RS
	.B S
	.in +2n
	Identical to the \fBS\fR conversion specifier, except any non-printable 
	characters in the array (ie. characters with an ASCII value < 32 or >= 127) 
	are written as \fB\\x\fR followed by the ASCII code value in hexadecimal 
	(upper case, two characters).
	.in
	.RE

	.RS
	.B r
	.in +2n
	Identical to the \fBs\fR conversion specifier, except characters from the 
	array are written in reverse, starting from (but not including) the 
	terminating null byte ('\\0') and ending at the first element of the array.
	.in
	.RE

	.RS
	.B R
	.in +2n
	Identical to the \fBs\fR conversion specifier, except each character of the 
	array is converted to its corresponding character in ROT13 before breing written.
	.in
	.RE

	.RS
	.B p
	.in +2n
	The address of the argument is written. The address is written in hexadecimal 
	with a leading \fI0x\fR.
	.in
	.RE

	.RS
	.B %
	.in +2n
	A '%' is written. No argument is converted. The complete conversion 
	specification is '%%'.
	.in
	.RE

.SH EXAMPLE
To print the day of the year, where weekday and month are pointers to strings and day and year are integers:

.RS
#include "main.h"

_printf("%s, %s %d, %d\\n", weekday, month, day, year);

.RS

.SH SEE ALSO
.I printf(3)
.SH BUGS
No known bugs.
.SH AUTHOR
SULE AISHAT ALADI AND CHIJIOKE OGBUANYA
