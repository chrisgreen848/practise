#pragma once
#include <iostream>
#include <string>
//visionforce practices 
#define MAXHEIGHT 200 
#define MAXWEIGHT 200
//indents of 3 spaces and ad void to no arguements
class person
{
private:

   std::string m_sName; // variables named as: i.e member_type<name of variable> In this case membervariable_stringName;
   int m_iHeight = 0;
   int m_iWeight = 0;


public:
   person();
   void setHeight(int a);
   int getHeight();
   std::string getName();
   void setName(std::string a);
   void printName();
   void setWeight( int a );
   int getWeight();
   ~person();
   
   
  
};
