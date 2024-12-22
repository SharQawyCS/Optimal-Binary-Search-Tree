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

  void popAlert(std::string msg)
  {
    Utils::clearTerminal();
    std::cout << msg << "\n"
              << std::endl
              << "Press [Enter] to continue...";
    std::cin.ignore();
    std::cin.get();
  }

}