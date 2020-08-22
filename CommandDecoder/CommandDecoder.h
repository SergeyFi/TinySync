#pragma once

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "ICommandDecoder.h"
#include "../CommandExecutor/ICommandExecutor.h"
#include "../CommandExecutor/IGetCommands.h"

class CommandDecoder : public ICommandDecoder
{
public:

    CommandDecoder(ICommandExecutor* NewCommandExecutor);
    
    void AddRawData(int argc, char* argv[]) override;

private:

    ICommandExecutor* CommandExecutor;

    std::map<std::string, std::string> commandsMap;

    void MakeCommandsMap();

    bool CheckCommand(std::string& command);
};
