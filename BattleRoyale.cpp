// First Battle Royale Game with C++
// Copyright (c) RetroBooming

#include <iostream>
#include <windows.h.>
#include <fstream>
#include <vector>
#include <string>
#include <thread>
#include <filesystem>
#include <experimental/filesystem>

#include "PlayerDefs.h"
#include "AntiCheat.h"
#include "Islands.h"
#include "Buildings.h"
#include "Short-Packets.h"

using namespace std;

namespace panel
{
   string input;
   string pref = "!";
   string statusview;
}

void launch(int confirz)
{
   // todo!
}

void txt(string content, int method)
{
   if (method == 1)
   {
      std::cout << content << endl;
   }
   else if (method == 2)
   {
      std::cout << content;
   }
   else {
      exit(1);
   }
}
void inputmethods()
{
   if (panel::input == panel::pref + "launch")
   {
      launch(1);
   }
   else if (panel::input == panel::pref + "maintenance")
   {
      ofstream xyz;
      xyz.open("properties/maintenance.txt");
      xyz >> 1;
      xyz.close();
     
      Visualize::PopUpText("Battle-Royale is Going Under-Maintenance. Please try again later!");
   }
   else if (panel::input == panel::pref + "commands")
   {
      txt("Commands: !close, !maintenance, !commands, !status, !discord, ", 1);
   }
   else if (panel::input == panel::pref + "discord")
   {
      txt("https://discord.gg/yourlink", 1);
   }
   else if (panel::input == panel::pref + "status")
   {
      CreateFile("properties/status.txt", panel::statusview);
   }
}
int vc_main()
{
   std::cout << "Battle_Royale Launcher (c) RetroBooming" << endl;
   std::cout << "Server-Panel: (enter method)";
   std::cin >> panel::input;
   inputmethods();
}
