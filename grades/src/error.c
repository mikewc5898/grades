/*
 * Error handling routines
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int errors;
int warnings;
int dbflag = 1;

void fatal(char *fmt, ...)
{
        va_list ap;
        va_start(ap,fmt);

        fprintf(stderr, "\nFatal error: ");
        vfprintf(stderr, fmt,ap);
        fprintf(stderr, "\n");
        va_end(ap);
        exit(1);
}

void error(char *fmt,...)
{
        va_list ap;
        va_start(ap,fmt);
        fprintf(stderr, "\nError: ");
        vfprintf(stderr, fmt, ap);
        fprintf(stderr, "\n");
        va_end(ap);
        errors++;
}

void warning(char *fmt,...)
{
        va_list ap;
        va_start(ap,fmt);
        fprintf(stderr, "\nWarning: ");
        vfprintf(stderr, fmt,ap);
        fprintf(stderr, "\n");
        va_end(ap);
        warnings++;
}

void debug(char *fmt,...)
{
        if(!dbflag) return;
        va_list ap;
        va_start(ap,fmt);
        fprintf(stderr, "\nDebug: ");
        vfprintf(stderr, fmt,ap);
        fprintf(stderr, "\n");
        va_end(ap);
}
