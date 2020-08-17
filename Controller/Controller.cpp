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
    for (auto i = 0; i < commands.commands.size(); ++i)
    {
        const auto& command = commands.commands[i];
        const auto& arguments = commands.arguments[i];
        
        if (command == Command::help)
        {
            CommandHelp();
        }
        else if (command == Command::origin)
        {
            AddOrigin(arguments[0]);
        }
        else if (command == Command::target)
        {
            AddTarget(arguments[0]);
        }
        else if (command == Command::sync)
        {
            Sync();
        }
        else if (command == Command::balance)
        {
            Balance();
        }
        else if (command == Command::clean)
        {
            CleanTarget();
        }
    }
}

void Controller::CommandHelp()
{
    Output_manager->PrintHelp();
}

void Controller::AddOrigin(std::string origin_path)
{
    Sync_manager->AddOrigin(origin_path);
}

void Controller::AddTarget(std::string target_path)
{
    Sync_manager->AddTarget(target_path);
}

void Controller::Sync()
{
    Sync_manager->TransferFilesTarget();
}

void Controller::Balance()
{
    Sync_manager->BalanceFiles();
}

void Controller::CleanTarget()
{
    Sync_manager->CleanTarget();
}

