#include "CommandDecoder.h"

void CommandDecoder::AddRawData(int argc, char* argv[])
{
    const auto arg_count = 3;
    
    for (int i = 1; i < argc; ++i)
    {
        CommandArgument command_new;
        
        auto& raw_argument = argv[i];

        if (commands.count(raw_argument) > 0)
        {
            const auto current_command = commands.find(raw_argument)->second;

            if (current_command == Command::origin)
            {
                if (argc > arg_count)
                {
                    
                }
            }
        }
    }
}

std::vector<CommandArgument> CommandDecoder::GetCommands()
{
    return commandArguments;
}
