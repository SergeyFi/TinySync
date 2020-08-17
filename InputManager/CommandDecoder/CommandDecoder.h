#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>

#include "ICommandDecoder.h"
#include "../../Controller/IController.h"

class CommandDecoder : public ICommandDecoder
{
public:

    CommandDecoder(std::shared_ptr<IController>& Controller);
    
    void AddRawData(int argc, char* argv[]) override;

private:

    std::shared_ptr<IController> Controller;

    const std::map<std::string, Command> commands
    {
        {{"-O"}, Command::origin},
        {{"--origin"}, Command::origin},
        {{"-T"}, Command::target},
        {{"--target"}, Command::target},
        {{"-F"}, Command::filter},
        {{"--filter"}, Command::filter},
        {{"-I"}, Command::inverted_filter},
        {{"--inverted"}, Command::inverted_filter},
        {{"-S"}, Command::sync},
        {{"--sync"}, Command::sync},
        {{"-C"}, Command::clean},
        {{"--clean"}, Command::clean},
        {{"-B"}, Command::balance},
        {{"--balance"}, Command::balance},
        {{"-H"}, Command::help},
        {{"--help"}, Command::help}
    };
};
