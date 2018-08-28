#ifndef DEBUG_H
#define DEBUG_H

#include <cstdio>
#include <cstdint>
#include <cstdarg>

#define dbgprint(fmt, ...) dbgPrint(__FILE__, __LINE__, fmt, ##__VA_ARGS__)

int dbgPrint(const char *filename, uint32_t line, const char *formatStr, ...);

#endif
