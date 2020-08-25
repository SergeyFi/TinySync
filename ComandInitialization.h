#pragma once

#include "CommandConstructor/ICommandConstructor.h"

#include "Commands/CommandAddOrigin.h"
#include "Commands/CommandAddTarget.h"
#include "Commands/CommandSync.h"
#include "Commands/CommandBalance.h"
#include "Commands/CommandCleanTarget.h"
#include "Commands/CommandVersion.h"
#include "Commands/CommandHelp.h"


void InitCommands(ICommandConstructor* CommandConstructor, ISync* SyncManager, IOutputManager* OutputManager)
{
    CommandConstructor->AddCommand<CommandVersion>(
            {"version"} ,"Version", tinySyncVersion, Priority(0), ArgCount(0), OutputManager);


    CommandConstructor->AddCommand<CommandAddOrigin>(
            {"origin"} ,"Origin", Priority(1), ArgCount(1), SyncManager);


    CommandConstructor->AddCommand<CommandAddTarget>(
            {"target"} ,"Target", Priority(1), ArgCount(1), SyncManager);


    CommandConstructor->AddCommand<CommandSync>(
            {"sync"} ,"Sync", Priority(3), ArgCount(0), SyncManager);


    CommandConstructor->AddCommand<CommandBalance>(
            {"balance"} ,"Balance", Priority(3), ArgCount(0), SyncManager);


    CommandConstructor->AddCommand<CommandCleanTarget>(
            {"clean"} ,"Clean", Priority(2), ArgCount(0), SyncManager);


    CommandConstructor->AddCommand<CommandHelp>(
            {"help"} ,"Help", Priority(0), ArgCount(0), OutputManager);

}