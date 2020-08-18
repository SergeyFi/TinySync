#include "CommandDecoder.h"
#include <vector>

CommandDecoder::CommandDecoder(std::shared_ptr<IController>& Controller)
{
    this->Controller = Controller;
}

void CommandDecoder::AddRawData(int argc, char* argv[])
{
    std::vector<Command> commands;

    for (auto i = 0; i < argc; ++i)
    {
        std::string currentArgument = argv[i];

        if (commandsMap.count(currentArgument) > 0)
        {
            Command new_command;
            new_command.command = commandsMap.find(currentArgument)->second;

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
