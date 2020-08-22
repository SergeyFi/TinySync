#pragma once

#include <memory>
#include <map>

#include "ICommandExecutor.h"
#include "../Commands/ICommand.h"
#include "IGetCommands.h"

class CommandExecutor : public ICommandExecutor, public IGetCommands
{
public:

    CommandExecutor(std::vector<std::shared_ptr<ICommand>>& NewCommands);

    void InputCommand(std::vector<Command> commands) override;

    bool debug;

    const std::map<std::string, std::shared_ptr<ICommand>>& GetCommandsMap() const override;

private:

    std::vector<std::shared_ptr<ICommand>> Commands;
    std::map<std::string, std::shared_ptr<ICommand>> CommandsMap;

    void GenerateCommandsMap();

};
