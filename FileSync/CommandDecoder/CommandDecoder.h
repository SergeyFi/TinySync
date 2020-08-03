#pragma once
#include <map>
#include <vector>


#include "CommandDecoderInterface.h"

class CommandDecoder : CommandDecoderInterface
{
public:

    void AddRawData(int argc, char* argv[]) override;

    std::vector<CommandArgument> GetCommands() override;

private:

    const std::map<std::string, Command> commands
    {
        {{"-O"}, Command::origin},
        {{"--origin"}, Command::origin},
        {{"-T"}, Command::target},
        {{"--target"}, Command::target},
        {{"-F"}, Command::filter},
        {{"--filter"}, Command::filter},
        {{"-I"}, Command::inverted},
        {{"--inverted"}, Command::inverted},
        {{"-S"} ,Command::sync},
        {{"--sync"} ,Command::sync},
        {{"-C"} ,Command::clean},
        {{ "--clean"} ,Command::clean},
        {{"-B"} ,Command::balance},
        {{"--balance"} ,Command::balance},
        {{"-H"} ,Command::help},
        {{"--help"} ,Command::help}
    };

    const std::map<Command, int> commands_arg_count
    {
        {Command::origin, 1},
        {Command::target, 1},
        {Command::filter, -1},
        {Command::inverted, 0},
        {Command::sync, 0},
        {Command::clean, 0},
        {Command::balance, 0},
        {Command::help, 0}
    };

    std::vector<CommandArgument> commandArguments;
};
