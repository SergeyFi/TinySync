#include "DataTypeBase.h"

#include <set>
#include <string>

struct CFullName : public DataTypeBase<std::set<std::string>>
{

};