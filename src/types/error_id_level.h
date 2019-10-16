#include "general_types.h"

#ifndef ERROR_ID_LEVEL
#define ERROR_ID_LEVEL

typedef
    enum ErrorLevelType
    {
        MODULE      = 0;
        PARTITION   = 1;
        PROCESS     = 2;
    };

typedef
    enum ErrorCodeType
    {
        DEADLINE_MISSED     = 0;
        APPLICATION_ERROR   = 1;
        NUMERIC_ERROR       = 2;
        ILLEGAL_REQUEST     = 3;
        STACK_OVERFLOW      = 4;
        MEMORY_VIOLATION    = 5;
        HARDWARE_FAULT      = 6;
        POWER_FAILURE       = 7;
    };

class ErrorIDLevel
{
    private:
        int errorIdentifier;                       /* required */
        std::optional<nameType> description;        /* optional */
        ErrorLevelType errorLevel;                  /* required */
        std::optional<ErrorCodeType> errorCode;     /* optional */
};

#endif
