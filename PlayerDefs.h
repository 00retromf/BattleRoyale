#pragma once

#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

namespace PlayerData
{
   string username = "";
   string password = "";
   string passwordverify = "";
   string email = "";
   string badge = "";
   bool isBanned = false;
   bool isBuilding = false;
   bool isReviving = false;
   int age = 0;
   int level = 1;
   int xp = 0;
   int countryid;
   int userID;
   int x;
   int y;
   int cash = 0;
   int power = 0;
  
   bool isTalking = false;
  
   // rank auth
   bool isInfluencer = false;
   bool isDiscordStaff = false;
   bool isAdministrator = false;
   bool isDeveloper = false;
}

void save(string uwu)
{
   // registration made with .txts
   std::ifstream cs("players/" + PlayerData::username + "/" + uwu + ".txt");
   cs >> uwu;
   cs.close();
}

void PowerUp(string username, string password, int powerlvl)
{
   // open powers.txt for powerlvl list!
   
   username = PlayerData::username;
   password = PlayerData::password;
   powerlvl = PlayerData::power;
  
   if (powerlvl == 1)
   {
      PlayerData::badge = "Influencer";
      PlayerData::power = 1;
      save(atoi(PlayerData::power));
   }
   else if (powerlvl == 2)
   {
      PlayerData::badge = "Discord-Staff";
      PlayerData::power = 2;
      save(atoi(PlayerData::power));
   }
   else if (powerlvl == 3)
   {
      PlayerData::badge = "Administrator";
      PlayerData::power = 3;
      save(atoi(PlayerData::power));
   }
   else if (powerlvl == 4)
   {
      PlayerData::badge = "Developer";
      PlayerData::power = 4;
      save(atoi(PlayerData::power));
   }
}


class Visualize
{
public:
   static void OverlayText(string context);
   static void PopUpText(string context);
   static void DialogPop(string context);
   static void BubbleText(string context);
};

void Visualize::BubbleText(string context)
{
   while(PlayerData::userID)
     userID.input(context)
   endl;
}

void getInternalPoint(int userID, int point)
{
   if (userID = -1)
   {
      autoban();
   }
   else {
      userID = PlayerData::userID + point;
   }
}
void VisualPackets(string content)
{
   string caa = getInternalPoint(PlayerData::userID, 1);
   if (caa.find("input|" + content))
   {
      Visualize::BubbleText(content);
   }
   else if (caa.find("act|"))
   {
      string suggested;
      if (caa.length() < 5)
      {
         suggested = "BubbleText";
      }
      else {
         suggested = "PopUpText";
      }
     
      Visualize::suggested(content);
   }
}

class Player
{
public:
   static void PlayerRegister(string username, string password, string passverify, string email);
   static void ChangePassword(string oldpass, string newpass, string newpassverify);
};

void Player::ChangePassword(string oldpass, string newpass, string newpassverify)
{
   bool mpass = false;
   string truepass;
   if (newpass == newpassverify)
   {
      truepass = newpassverify;
   }
   ofstream vc;
   vc.open("players/" + PlayerData::username + "/" + PlayerData::password + ".txt");
   if (vc.find(oldpass))
   {
      vc >> truepass;
      mpass = true;
      vc.close();
   }
}
