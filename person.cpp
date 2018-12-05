
#include <iostream>       // std::cout
#include <thread>  
#include <string>
#include "Header.h"
#include <thread>




person::person() { m_sName = " Not entered"; } // constructor

void person::printName( void )            
{
   std::cout << m_sName << std::endl;
}

void person::setHeight( int a )
{
   if ( a > MAXHEIGHT )
   {
      std::cout << "please enter Valid height: MAX HEIGHT is 200 cm: ";
      std::cin >> a;
   }
   m_iHeight = a;
}

int person::getHeight( void )
{
   return m_iHeight;
}

void person::setName( std::string a )
{
   m_sName = a;
}

std::string person::getName( )
{
   return m_sName;
}

void person::setWeight( int a )
{
   if ( a > MAXWEIGHT )
   {
      std::cout << "please enter Valid hwight: MAX wEIGHT is 200 KG: ";
      std::cin >> a;
   }
   m_iWeight = a;
}

int person::getWeight( void )
{
   return m_iWeight;
}

person::~person() {}  //destructor
nt main()
{
   person name1;
   person name2;
   std::string personName = "";
   int personWeight;
   int personHeight;
   std::cout << "Enter your name: "; 
   std::cin >> personName;
   name1.setName(personName);
   personName = name1.getName();
   std::cout << "Your name is : " << personName << std::endl;
   std::cout << "Enter your height and weight : ";
   std::cin >> personHeight >> personWeight;
   name1.setWeight( personWeight );
   name1.setHeight( personHeight );
   personHeight = name1.getHeight();
   personWeight = name1.getWeight();
   std::cout << "\n" << "Your Height is : " << personHeight << "cm's" << " and your weight is : " << personWeight << "KG" << std::endl;

   int end;
   std::cin >> end;
}
