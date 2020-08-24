#include "CommandDecoder.h"
#include <vector>
#include "../Logger/GetLogger.h"

CommandDecoder::CommandDecoder(ICommandExecutor* NewCommandExecutor, ICommandConstructor* NewCommandConstructor)
{
    CommandExecutor = NewCommandExecutor;
    CommandConstructor = NewCommandConstructor;
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
            new_command.commandFullName = commandsMap.find(currentArgument)->second;

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


    if (CommandExecutor)
    {
        CommandExecutor->InputCommand(commands);
    }
}

void CommandDecoder::MakeCommandsMap()
{
    for (auto& commandFullName : CommandConstructor->GetCommandsFullName())
    {
        for (auto& name : commandFullName)
        {
            commandsMap[name] = commandFullName;
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
