#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "ICommandDecoder.h"
#include "../CommandConstructor/ICommandConstructor.h"

class CommandDecoder : public ICommandDecoder
{
public:

    CommandDecoder(ICommandExecutor* NewCommandExecutor, ICommandConstructor* NewCommandConstructor);
    
    void AddRawData(int argc, char* argv[]) override;

private:

    ICommandExecutor* CommandExecutor;
    ICommandConstructor* CommandConstructor;

    std::map<std::string, std::set<std::string>> commandsMap;

    void MakeCommandsMap();

    bool CheckCommand(std::string& command);
};
