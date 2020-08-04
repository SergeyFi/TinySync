#include "InputManager.h"

InputManager::InputManager()
{
    Command_decoder = std::make_shared<CommandDecoder>();
}

void InputManager::InputArguments(int argc, char* argv[])
{
    Command_decoder->AddRawData(argc, argv);
}
