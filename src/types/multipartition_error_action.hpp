#ifndef MULTIPARTITION_ERROR_ACTION
#define MULTIPARTITION_ERROR_ACTION

#include "error_level.h"


class MultiPartitionErrorAction
{
    private:
        identifier_t errorIdentifier;                       /* required */
        ERROR_LEVEL_TYPE level;                             /* required */
        std::optional<MODULE_RECOVERY_ACTION_TYPE> action;  /* optional */

    public:
        MultiPartitionErrorAction(identifier_t id, ERROR_LEVEL_TYPE level, MODULE_RECOVERY_ACTION_TYPE action):
          errorIdentifier(id), action(action), level(level) {}

        identifier_t getErrorAction();

        ERROR_LEVEL_TYPE getLevel();

        MODULE_RECOVERY_ACTION_TYPE getAction();
};

#endif
