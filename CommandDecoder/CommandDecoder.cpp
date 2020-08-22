#include "CommandDecoder.h"
#include <vector>
#include "../Logger/GetLogger.h"

CommandDecoder::CommandDecoder(IController* Controller)
{
    this->Controller = Controller;
}

void CommandDecoder::AddRawData(int argc, char* argv[])
{
    MakeCommandsMap();

    std::vector<Command> commands;

    for (auto i = 0; i < argc; ++i)
    {
        std::string currentArgument = argv[i];

        if (!CheckCommand(currentArgument))
        {
            break;
        }

        if (commandsMap.count(currentArgument) > 0)
        {
            Command new_command;
            new_command.commandName = commandsMap.find(currentArgument)->second;

            commands.push_back(new_command);
        }
        else
        {
            if (!commands.empty())
            {
                commands.back().arguments.push_back(currentArgument);
            }
        }
    }


    if (Controller)
    {
        Controller->InputCommand(commands);
    }
}

void CommandDecoder::MakeCommandsMap()
{
    auto ControllerCommands = dynamic_cast<IGetCommands*>(Controller);

    if (ControllerCommands)
    {
        const auto& commands = ControllerCommands->GetCommandsMap();

        for (auto& [commandsList, Command] : commands)
        {
            for (auto& commandArgument : Command->GetCommandsList().commandsList)
            {
                commandsMap[commandArgument] = Command->GetCommandName();
            }
        }
    }
}

bool CommandDecoder::CheckCommand(std::string& command)
{
    if (command[0] == '-')
    {
        if (commandsMap.count(command) == 0)
        {
            GetLogger::LoggerGet()->Log("Command '" + command + "' does not exist.", LogType::error);

            return false;
        }
    }

    return true;
}
