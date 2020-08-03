#pragma once
#include <map>
#include <string>
#include <vector>


#include "CommandDecoderInterface.h"

class CommandDecoder : CommandDecoderInterface
{
public:

    void AddRawData(int argc, char* argv[]) override;

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
};
