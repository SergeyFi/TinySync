#include "Controller.h"

#include <algorithm>

Controller::Controller(bool debug, std::shared_ptr<IInputManager>& Input_manager,
    std::shared_ptr<IOutputManager>& Output_manager, std::shared_ptr<ISync>& Sync_manager,
    std::map<CommandType, std::shared_ptr<ICommand>>& New_Commands)
{
    this->debug = debug;
    this->Input_manager = Input_manager;
    this->Output_manager = Output_manager;
    this->Sync_manager = Sync_manager;
    Commands = New_Commands;
}

void Controller::InputConsoleArgument(int argc, char* argv[])
{
    Input_manager->InputArguments(argc, argv);
}

void Controller::InputCommand(std::vector<Command> commands)
{
    std::sort(commands.begin(), commands.end(), [this](const Command& a, const Command& b)
    {
        return Commands[a.command]->GetCommandPriority() < Commands[b.command]->GetCommandPriority();
    });

    for (const auto& command : commands)
    {
        Commands[command.command]->Execute(command.arguments, this);
    }
}

std::shared_ptr<ISync> Controller::GetSyncManager()
{
    return Sync_manager;
}

std::map<CommandType, std::shared_ptr<ICommand>> Controller::GetCommands() const
{
    return Commands;
}

std::shared_ptr<IOutputManager> Controller::GetOutputManager()
{
    return Output_manager;
}
