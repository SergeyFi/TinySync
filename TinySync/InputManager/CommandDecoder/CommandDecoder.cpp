#include "CommandDecoder.h"

CommandDecoder::CommandDecoder(std::shared_ptr<IController> Controller)
{
    this->Controller = Controller;
}

void CommandDecoder::AddRawData(int argc, char* argv[])
{
    Commands command;

    for (int i = 1; i < argc; ++i)
    {
        const std::string current_argument = argv[i];

        if (commands.count(current_argument) > 0)
        {
            command.commands.push_back(commands.find(current_argument)->second);
        }
        else
        {
            command.arguments.push_back(current_argument);
        }
    }

    if (Controller)
    {
        Controller->InputCommand(command);
    }
}
