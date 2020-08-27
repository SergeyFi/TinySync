#include "DataTypeBase.h"

#include "../Commands/ICommand.h"

#include <functional>


struct CConstructor: public DataTypeBase<std::function<ICommand*(CArg arg)>>
{
    
};