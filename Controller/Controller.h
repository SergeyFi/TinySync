#pragma once

#include <memory>
#include <map>

#include "IController.h"
#include "../InputManager/IInputManager.h"
#include "../OutputManager/IOutputManager.h"
#include "../SyncManager/ISync.h"
#include "../Commands/ICommand.h"
#include "IGetCommands.h"

class Controller : public IController, public IGetCommands
{
public:

    Controller(std::vector<std::shared_ptr<ICommand>>& New_Commands);

    void InputCommand(std::vector<Command> commands) override;

    bool debug;

    const std::map<std::string, std::shared_ptr<ICommand>>& GetCommandsMap() const override;

private:

    std::vector<std::shared_ptr<ICommand>> Commands;
    std::map<std::string, std::shared_ptr<ICommand>> CommandsMap;

    void GenerateCommandsMap();

};
