#pragma once
#include <memory>

#include "IInputManager.h"
#include "../InputManager/CommandDecoder/ICommandDecoder.h"
#include "../InputManager/CommandDecoder/CommandDecoder.h"
#include "../Controller/IController.h"

class InputManager : public IInputManager
{
public:

    InputManager() = default;

    void InputArguments(int argc, char* argv[]) override;

    void AddController(std::shared_ptr<IController>& Controller) override;

private:

    std::shared_ptr<ICommandDecoder> Command_decoder;
    std::shared_ptr<IController> Controller;


};
