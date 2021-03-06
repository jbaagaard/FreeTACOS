#include "partition_hm_table.hpp"

PartitionHMTable& PartitionHMTable::operator=(const PartitionHMTable& rhs)
{
    tableName = rhs.tableName;
    multiPartitionTableName = rhs.multiPartitionTableName;
    partitionErrorActions = rhs.partitionErrorActions;
    return *this;
}

const NAME_TYPE& PartitionHMTable::getTableName() const
{
    return tableName;
}

const NAME_TYPE& PartitionHMTable::getMultiPartitionTableName() const
{
    return multiPartitionTableName;
}

const std::vector<PartitionErrorAction>& PartitionHMTable::getActions() const
{
    return *partitionErrorActions;
}
