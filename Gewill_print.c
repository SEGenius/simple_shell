#include "shell.h"


/* 
 * print
 *
 * description: -print out the format 
 *
 * return always 0
 *
*/

void gewill_print(Const char *format) {
	write(STDOUT_FILENO, format, strlen(format));
}
