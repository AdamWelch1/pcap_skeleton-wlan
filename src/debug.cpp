#include "debug.h"

int dbgPrint(const char *filename, uint32_t line, const char *formatStr, ...)
{
    #ifdef DEBUG_MODE

        va_list args;
        va_start(args, formatStr);

        printf("[%s:%d] ", filename, line);
        int retVal = vprintf(formatStr, args);

        va_end(args);

        fflush(stdout);
        return retVal;

    #else

        return 0;

    #endif
}
