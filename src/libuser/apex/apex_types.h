/* This is a compilable ANSI C specification of the APEX interface.     */
/* The declarations of the services given below are taken from the      */
/* standard, as are the enum types and the names of the others types.   */
/* However, the definitions given for these others types, and the       */
/* names and values given below for constants, are all implementation   */
/* specific.                                                            */

/* This ANSI C specification follows the same structure (package) as    */
/* the Ada specification.                                               */

/*----------------------------------------------------------------*/
/*                                                                */
/* Global constant and type definitions                           */
/*                                                                */
/*----------------------------------------------------------------*/

#ifndef APEX_TYPES
#define APEX_TYPES

#include <vector>
#include <circle/util.h>

/*---------------------------*/
/* Domain limits             */
/*---------------------------*/

/* Domain dependent                                                        */
/* These values define the domain limits and are implementation dependent. */

#define SYSTEM_LIMIT_NUMBER_OF_PARTITIONS 32 /* module scope */

#define SYSTEM_LIMIT_NUMBER_OF_MESSAGES 512 /* module scope */

#define SYSTEM_LIMIT_MESSAGE_SIZE 8192 /* module scope */

#define SYSTEM_LIMIT_NUMBER_OF_PROCESSES 128 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_SAMPLING_PORTS 512 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_QUEUING_PORTS 512 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_BUFFERS 256 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_BLACKBOARDS 256 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_SEMAPHORES 256 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_EVENTS 256 /* partition scope */

#define INFINITE_TIME_VALUE -1

// only applies to the error handler process
#define CORE_AFFINITY_NO_PREFERENCE -1

const int MAX_NAME_LENGTH = 30;

/*----------------------*/
/* Base APEX types      */
/*----------------------*/

/* The actual size of these base types is system specific and the   */
/* sizes must match the sizes used by the implementation of the     */
/* underlying Operating System.                                     */

typedef unsigned char APEX_BYTE; /* 8-bit unsigned */

typedef long APEX_INTEGER; /* 32-bit signed */

typedef unsigned long APEX_UNSIGNED; /* 32-bit unsigned */

typedef long long APEX_LONG_INTEGER; /* 64-bit signed */

/*----------------------*/
/* General APEX types   */
/*----------------------*/

typedef enum {
    NO_ERROR = 0,       /* request valid and operation performed */
    NO_ACTION = 1,      /* status of system unaffected by request */
    NOT_AVAILABLE = 2,  /* resource required by request unavailable */
    INVALID_PARAM = 3,  /* invalid parameter specified in request */
    INVALID_CONFIG = 4, /* parameter incompatible with configuration */
    INVALID_MODE = 5,   /* request incompatible with current mode */
    TIMED_OUT = 6       /* time-out tied up with request has expired */
} RETURN_CODE_TYPE;

struct NAME_TYPE {
    char x[MAX_NAME_LENGTH];
    NAME_TYPE() {}
    NAME_TYPE(std::vector<char> name){
      memcpy(&x, &name[0], MAX_NAME_LENGTH);
    }
};

typedef void(*SYSTEM_ADDRESS_TYPE);

typedef APEX_BYTE* MESSAGE_ADDR_TYPE;

typedef APEX_INTEGER MESSAGE_SIZE_TYPE;

typedef APEX_INTEGER MESSAGE_RANGE_TYPE;

typedef enum { SOURCE = 0, DESTINATION = 1 } PORT_DIRECTION_TYPE;

typedef enum { FIFO = 0, PRIORITY = 1 } QUEUING_DISCIPLINE_TYPE;

/* 64-bit signed integer with a 1 nanosecond LSB */
typedef APEX_LONG_INTEGER SYSTEM_TIME_TYPE;

typedef APEX_INTEGER PROCESSOR_CORE_ID_TYPE;

#endif
