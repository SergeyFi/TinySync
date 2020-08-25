#include "CommandDecoder.h"
#include <vector>

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
    for (auto& commandFullName : CommandConstructor->GetCommandsFullNames())
    {
        for (auto& name : commandFullName)
        {
            commandsMap[name] = commandFullName;
        }
    }
}
