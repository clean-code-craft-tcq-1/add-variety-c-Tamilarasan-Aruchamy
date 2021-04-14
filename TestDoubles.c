#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "TestDoublesHeader.h"
#include <stddef.h>

extern BreachType checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);


TEST_CASE("infers the breach(TOO_LOW) according to PASSIVE_COOLING and send to CONTROLLER") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={PASSIVE_COOLING,"Bosch"};
  
  TestInterface_Reset();
  BreachTypeActual=checkAndAlert(TO_CONTROLLER,batteryChar,-5);
   
  REQUIRE(BreachTypeActual == TOO_LOW); 
  REQUIRE(Test_Controller_header == 0xfeed);
  REQUIRE(Test_Controller_breachType == TOO_LOW);
  REQUIRE(Test_Mail_recepient == NULL);
  REQUIRE(Test_Mail_MailContent == NULL);
  REQUIRE(Test_Console_ConsoleContent == NULL);  
  REQUIRE(Func_CallCount_Controller == 1);
  REQUIRE(Func_CallCount_Mail == 0);
  REQUIRE(Func_CallCount_printf == 0);  
  
}


TEST_CASE("infers the breach(NORMAL) according to PASSIVE_COOLING and send to CONTROLLER") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={PASSIVE_COOLING,"Bosch"};
  
  TestInterface_Reset();
  BreachTypeActual=checkAndAlert(TO_CONTROLLER,batteryChar,30);
   
  REQUIRE(BreachTypeActual == NORMAL); 
  REQUIRE(Test_Controller_header == 0xfeed);
  REQUIRE(Test_Controller_breachType == NORMAL);
  REQUIRE(Test_Mail_recepient == NULL);
  REQUIRE(Test_Mail_MailContent == NULL);
  REQUIRE(Test_Console_ConsoleContent == NULL);  
  REQUIRE(Func_CallCount_Controller == 1);
  REQUIRE(Func_CallCount_Mail == 0);
  REQUIRE(Func_CallCount_printf == 0);  
  
}


TEST_CASE("infers the breach(TOO_HIGH) according to PASSIVE_COOLING and send to CONTROLLER") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={PASSIVE_COOLING,"Bosch"};
  
  TestInterface_Reset();
  BreachTypeActual=checkAndAlert(TO_CONTROLLER,batteryChar,40);
   
  REQUIRE(BreachTypeActual == TOO_HIGH); 
  REQUIRE(Test_Controller_header == 0xfeed);
  REQUIRE(Test_Controller_breachType == TOO_HIGH);
  REQUIRE(Test_Mail_recepient == NULL);
  REQUIRE(Test_Mail_MailContent == NULL);
  REQUIRE(Test_Console_ConsoleContent == NULL);  
  REQUIRE(Func_CallCount_Controller == 1);
  REQUIRE(Func_CallCount_Mail == 0);
  REQUIRE(Func_CallCount_printf == 0);  
  
}

