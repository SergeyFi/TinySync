#include "CommandDecoder.h"

#include <vector>

CommandDecoder::CommandDecoder(std::shared_ptr<IController> Controller)
{
    this->Controller = Controller;
}

void CommandDecoder::AddRawData(int argc, char* argv[])
{
    Commands command;

    int command_index = -1;

    for (int i = 1; i < argc; ++i)
    {   
        const std::string current_argument = argv[i];

        if (commands.count(current_argument) > 0)
        {
            command.commands.push_back(commands.find(current_argument)->second);
            command.arguments.push_back(std::vector<std::string>());
            ++command_index;
        }
        else
        {
            if (command_index >= 0)
            {
                command.arguments[command_index].push_back(current_argument);
            }
        }
    }

    if (Controller)
    {
        Controller->InputCommand(command);
    }
}
