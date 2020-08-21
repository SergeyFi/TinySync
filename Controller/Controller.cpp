﻿#include "Controller.h"

#include <algorithm>

Controller::Controller(bool debug, std::shared_ptr<IInputManager>& Input_manager,
    std::shared_ptr<IOutputManager>& Output_manager, std::shared_ptr<ISync>& Sync_manager,
    std::vector<std::shared_ptr<ICommand>>& New_Commands)
{
    this->debug = debug;
    this->Input_manager = Input_manager;
    this->Output_manager = Output_manager;
    this->Sync_manager = Sync_manager;

    Commands = New_Commands;

    GenerateCommandsMap();
}

void Controller::InputCommand(std::vector<Command> commands)
{
    std::sort(commands.begin(), commands.end(), [this](const Command& a, const Command& b)
    {
        return CommandsMap[a.commandName]->GetCommandPriority() < CommandsMap[b.commandName]->GetCommandPriority();
    });

    for (const auto& command : commands)
    {
        CommandsMap[command.commandName]->Execute(command.arguments, this);
    }
}

std::shared_ptr<ISync> Controller::GetSyncManager()
{
    return Sync_manager;
}

const std::map<std::string, std::shared_ptr<ICommand>>& Controller::GetCommandsMap() const
{
    return CommandsMap;
}

std::shared_ptr<IOutputManager> Controller::GetOutputManager()
{
    return Output_manager;
}

void Controller::GenerateCommandsMap()
{
    for (const auto& command : Commands)
    {
        CommandsMap[command->GetCommandName()] = command;
    }
}
