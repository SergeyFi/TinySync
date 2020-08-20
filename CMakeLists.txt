cmake_minimum_required(VERSION 3.17)
project(TinySync)

set(CMAKE_CXX_STANDARD 17)

include_directories(Controller)
include_directories(InputManager)
include_directories(InputManager/CommandDecoder)
include_directories(OutputManager)
include_directories(SyncManager)

add_executable(TinySync
        Controller/Controller.cpp
        Controller/Controller.h
        Controller/IController.h
        InputManager/CommandDecoder/CommandType.h
        InputManager/CommandDecoder/CommandDecoder.cpp
        InputManager/CommandDecoder/CommandDecoder.h
        InputManager/CommandDecoder/ICommandDecoder.h
        InputManager/IInputManager.h
        InputManager/InputManager.cpp
        InputManager/InputManager.h
        OutputManager/IOutputManager.h
        OutputManager/OutputManager.cpp
        OutputManager/OutputManager.h
        SyncManager/Filter.h
        SyncManager/ISync.h
        SyncManager/SyncManager.cpp
        SyncManager/SyncManager.h
        TinySync.cpp  Logger/ILogger.h Logger/Logger.cpp Logger/Logger.h Logger/GetLogger.h Logger/GetLogger.cpp Commands/ICommand.h Commands/CommandAddOrigin.cpp Commands/CommandAddOrigin.h Controller/IGetSyncManager.h Commands/CommandAddTarget.cpp Commands/CommandAddTarget.h Commands/CommandSync.cpp Commands/CommandSync.h Commands/CommandBalance.cpp Commands/CommandBalance.h Commands/CommandCleanTarget.cpp Commands/CommandCleanTarget.h Commands/CommandBase.cpp Commands/CommandBase.h Controller/IGetCommands.h)
