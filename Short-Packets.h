#pragma once

#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <filesystem>
#include <experimental/filesystem>

using namespace std;

namespace config
{
   string cd = "";
   int port = 0;
   string vs = "";
   bool ism = false;
}

void CreateFile(string fname, string fcontent, string operator)
{
   std::ifstream operator(fname);
   operator >> fcontent;
   operator.close();
}

void OpenFile(string fname, string fncontent, string operator)
{
   ofstream operator;
   operator.open(fname);
   operator >> fncontent;
   operator.close();
}

void ChangeStringConfig(string type, string newtype)
{
   if (type == "cd")
   {
      config::cd = newtype;
   }
}

void ChangeIntConfig(int type, int newtype)
{
   if (type == "port")
   {
      config::port = newtype;
   }
}
