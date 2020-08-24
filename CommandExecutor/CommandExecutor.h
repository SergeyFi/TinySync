#pragma once

#include <memory>
#include <map>
#include <set>

#include "ICommandExecutor.h"
#include "../Commands/ICommand.h"
#include "../CommandConstructor/ICommandConstructor.h"

class CommandExecutor : public ICommandExecutor
{
public:

    CommandExecutor(ICommandConstructor* CommandConstructor);

    void InputCommand(std::vector<Command> commands) override;

private:

    ICommandConstructor* CommandConstructor;
};
