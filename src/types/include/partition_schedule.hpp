#ifndef PARTITON_SCHEDULE
#define PARTITON_SCHEDULE

#include <apex_types.h>
#include <general_types.hpp>

class PartitionSchedule {
private:
    bool partitionPeriodStart;        /* required */
    decOrHex_t periodDurationSeconds; /* required */
    name_t partitionName;             /* required */
    decOrHex_t offset;                /* required */
    decOrHex_t period;                /* required */
    decOrHex_t affinity;              /* required */

    identifier_t partitionIdentifier;

public:
    PartitionSchedule(bool periodicStart,
                      decOrHex_t duration,
                      name_t name,
                      decOrHex_t offset,
                      decOrHex_t period,
                      decOrHex_t affinity)
        : partitionPeriodStart(periodicStart),
          periodDurationSeconds(duration),
          partitionName(name),
          offset(offset),
          period(period),
          affinity(affinity)
    {
    }

    const bool& getPartitionPeriodStart() const;

    const decOrHex_t& getPeriodDuration() const;

    const name_t& getPartitionName() const;

    const decOrHex_t& getOffset() const;

    void setPartitionIdentifier(identifier_t id);

    const identifier_t& getPartitionIdentifier() const;
};

#endif
