#include "DataTypeBase.h"

#include <vector>
#include <string>

struct CArg : public DataTypeBase<std::vector<std::string>>
{

};