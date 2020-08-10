#include "Controller.h"

Controller::Controller(bool debug, std::shared_ptr<IInputManager> Input_manager,
    std::shared_ptr<IOutputManager> Output_manager, std::shared_ptr<ISync> Sync_manager)
{
    this->debug = debug;
    this->Input_manager = Input_manager;
    this->Output_manager = Output_manager;
    this->Sync_manager = Sync_manager;
    
}

void Controller::InputConsoleArgument(int argc, char* argv[])
{
    Input_manager->InputArguments(argc, argv);
}

void Controller::InputCommand(Commands commands)
{
    // if (debug)
    // {
    //     Output_manager->PrintCommand(commands);
    // }

    CommandHelp(commands);
}

bool Controller::ContainCommand(Command command, Commands& commands)
{
    for (auto cur_command : commands.commands)
    {
        if (cur_command == command)
        {
            return true;
        }
    }

    return false;
}

std::vector<std::string> Controller::GetCommandArguments(Command command, Commands& commands)
{
    for (auto i = 0; i < commands.commands.size(); ++i)
    {
        if (commands.commands[i] == command)
        {
            return commands.arguments[i];
        }
    }

    return {};
}

void Controller::CommandHelp(Commands& commands)
{
    if (ContainCommand(Command::help, commands))
    {
        Output_manager->PrintHelp();
    }
}
