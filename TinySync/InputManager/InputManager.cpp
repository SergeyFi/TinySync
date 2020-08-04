#include "InputManager.h"

InputManager::InputManager()
{
}

void InputManager::InputArguments(int argc, char* argv[])
{
    Command_decoder->AddRawData(argc, argv);
}

void InputManager::AddController(std::shared_ptr<IController> Controller)
{
    this->Controller = Controller;
    Command_decoder = std::make_shared<CommandDecoder>(Controller);
}
