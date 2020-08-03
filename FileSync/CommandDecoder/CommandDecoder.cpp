#include "CommandDecoder.h"

void CommandDecoder::AddRawData(int argc, char* argv[])
{
    const std::string first_argument = argv[1];
    
    if (commands.count(first_argument) > 0)
    {
        ParseOrigin(argc, argv, first_argument);
    }
}

std::vector<CommandArgument> CommandDecoder::GetCommands()
{
    return commandArguments;
}

void CommandDecoder::ParseOrigin(int argc, char* argv[], const std::string& first_argument)
{

    if (argc >= 3)
    {
        if (commands.find(first_argument)->second == Command::origin)
        {
            CommandArgument argument;
            
            argument.command = Command::origin;

            argument.arguments.insert(argv[2]);

            commandArguments.push_back(argument);
        }
    }
}
