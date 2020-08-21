#pragma once
#include <map>
#include <string>
#include <vector>
#include <memory>

#include "ICommandDecoder.h"
#include "../../Controller/IController.h"
#include "../Controller/IGetCommands.h"

class CommandDecoder : public ICommandDecoder
{
public:

    CommandDecoder(std::shared_ptr<IController>& Controller);
    
    void AddRawData(int argc, char* argv[]) override;

private:

    std::shared_ptr<IController> Controller;

    std::map<std::string, std::string> commandsMap;

    void MakeCommandsMap();

    bool CheckCommand(std::string& command);
};
