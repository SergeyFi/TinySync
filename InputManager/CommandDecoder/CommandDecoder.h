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

    const std::map<std::string, CommandType> commandsMap
    {
        {{"-O"},         CommandType::origin},
        {{"--origin"},   CommandType::origin},
        {{"-T"},         CommandType::target},
        {{"--target"},   CommandType::target},
        {{"-F"},         CommandType::filter},
        {{"--filter"},   CommandType::filter},
        {{"-I"},         CommandType::inverted_filter},
        {{"--inverted"}, CommandType::inverted_filter},
        {{"-S"},         CommandType::sync},
        {{"--sync"},     CommandType::sync},
        {{"-C"},         CommandType::clean},
        {{"--clean"},    CommandType::clean},
        {{"-B"},         CommandType::balance},
        {{"--balance"},  CommandType::balance},
        {{"-H"},         CommandType::help},
        {{"--help"},     CommandType::help}
    };
};
