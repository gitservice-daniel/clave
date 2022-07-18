#include <kernel/lib/vfprintf.h>
#include <kernel/lib/string.h>

/**
  * Paramters of vfprinf()
  *
  * Specifier |                            Output                            |    Example
  *  d or i         Signed Decimal integer                                          392
  *    u            Unsigned decimal integer                                        7235
  *    o            Unsigned octal                                                  610
  *    x            Unsigned hexadecimal integer                                    7fa
  *    X            Unsigned hexadecimal integer (uppercase)                        7FA
  *    f            Decimal floating point, lowercase 392.65                        392.65
  *    F            Decimal floating point, uppercase 392.65                        392.65
  *    e            Scientific notation (mantissa/exponent), lowercase              3.9265e+2    
  *    E          	Scientific notation (mantissa/exponent), uppercase              3.9265E+2
  *    g          	Use the shortest representation: %e or %f                       392.65
  *    G            Use the shortest representation: %E or %F                       392.65
  *    a        	Hexadecimal floating point, lowercase                   	    -0xc.90fep-2
  *    A       	    Hexadecimal floating point, uppercase                   	    -0xc.90fep-2
  *    c            Character                                                        'C'
  *    s      	    String of characters                                             "CLAVE"
  *    p      	    Pointer address                                                  0xb8000
  *    n      	    Nothing printed                                                  
  *    %          	Escape of '%'                                                    %
  *
  *    TODO: Implement all specifiers and implement flags, width, length and precision
  */
void vfprintf(const char* fmt, va_list args, char* buffer) {
    char* str;
    char c;
    int n;

	for (int i = 0; fmt[i]; i++) {
        if (fmt[i] == '%') {
            i++;
            switch (fmt[i]) {
                case 'i':
                case 'd':
                    n = va_arg(args, int);
                    itoa(n, str);
                    strcat(buffer, str);
                    break;
                case 'u':
                    n = va_arg(args, unsigned int);
                    itoa(n, str);
                    strcat(buffer, str);
                    break;
                case 'o':
                    append(buffer, '?');
                    break;
                case 'x':
                case 'X':
                    n = va_arg(args, unsigned int);
                    htoa(n, str);
                    strcat(buffer, str);
                    break;
                case 'f':
                case 'F':
                    append(buffer, '?');
                    break;
                case 'e':
                case 'E':
                    append(buffer, '?');
                    break;
                case 'g':
                case 'G':
                    append(buffer, '?');
                    break;
                case 'a':
                case 'A':
                    append(buffer, '?');
                    break;
                case 'c':
                    c = va_arg(args, int);
                    append(buffer, c);
                    break;
                case 's':
                    str = va_arg(args, char*);
                    strcat(buffer, str);
                    break;
                case 'p':
                    n = va_arg(args, int);
                    htoa(n, str);
                    strcat(buffer, str);
                    break;
                case 'n':
                    break;
                case '%':
                    append(buffer, fmt[i]);
                    break;
                default:
                    break;
            }
        } else {
            append(buffer, fmt[i]);
        }
    }
}