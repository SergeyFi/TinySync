#include "CommandDecoder.h"

void CommandDecoder::AddRawData(int argc, char* argv[])
{
    const std::string first_argument = argv[1];
    
    if (commands.count(first_argument) > 0)
    {
        if (ParseOneParam(argc, argv, first_argument, Command::origin)) return;
        if (ParseOneParam(argc, argv, first_argument, Command::target)) return;
    }
}

std::vector<CommandArgument> CommandDecoder::GetCommands()
{
    return commandArguments;
}

bool CommandDecoder::ParseOneParam(int argc, char* argv[], const std::string& first_argument, Command param_name)
{
    if (argc >= 3)
    {
        if (commands.find(first_argument)->second == param_name)
        {
            CommandArgument argument;
            
            argument.command = param_name;

            argument.arguments.insert(argv[2]);

            // Need replace with : Add command argument to controller
            commandArguments.push_back(argument);

            return true;
        }
    }

    return false;
}
