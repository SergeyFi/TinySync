#pragma once
#include <memory>

#include "IInputManager.h"
#include "../CommandDecoder/ICommandDecoder.h"
#include "../CommandDecoder/CommandDecoder.h"
#include "../Controller/IController.h"

class InputManager : public IInputManager
{
public:

    InputManager();

    void InputArguments(int argc, char* argv[]) override;

    void AddController(std::weak_ptr<IController> Controller) override;

private:

    std::shared_ptr<ICommandDecoder> Command_decoder;
    std::weak_ptr<IController> Controller_;


};
