#include "InputManager.h"

InputManager::InputManager()
{
    Command_decoder = std::make_shared<CommandDecoder>();
}

void InputManager::InputArguments(int argc, char* argv[])
{
    Command_decoder->AddRawData(argc, argv);
}

void InputManager::AddController(std::weak_ptr<IController> Controller)
{
    Controller_ = Controller;
}
