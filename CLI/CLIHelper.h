#pragma once

#include <iostream>
#include <cstdio>
#include <string>
#include "../Utils.h"

namespace CLIHELPER
{
  int getChoice(int range, std::string msg)
  {
    if (msg == "USE_DEFAULT")
      msg = "Please select an option from [0] to [" + std::to_string(range) + "]" + ": ";

    int choice = (int)Utils::readFloatInput(msg, true);

    while (choice < 0 || choice > range)
    {
      std::cout << "Invalid choice. Please try again.\n";
      choice = (int)Utils::readFloatInput(msg, true);
    }

    return choice;
  };

}