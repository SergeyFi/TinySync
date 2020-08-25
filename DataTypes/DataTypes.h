#pragma once

#include <functional>

using CFullName = std::set<std::string>;

using CName = std::string;

using CArg = std::vector<std::string>;

using CConstructor = std::function<ICommand*(std::vector<std::string> arg)>;