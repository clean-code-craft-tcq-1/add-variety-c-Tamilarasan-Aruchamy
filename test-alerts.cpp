#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"
#include "TestDoublesHeader.h"
#include<stddef.h>
#include<string.h>

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


TEST_CASE("infers the breach(NORMAL) according to HI_ACTIVE_COOLING and send to CONTROLLER") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={HI_ACTIVE_COOLING,"Bosch"};
  
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


TEST_CASE("infers the breach(TOO_HIGH) according to MED_ACTIVE_COOLING and send to CONTROLLER") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={MED_ACTIVE_COOLING,"Bosch"};
  
  TestInterface_Reset();
  BreachTypeActual=checkAndAlert(TO_CONTROLLER,batteryChar,45);
   
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








TEST_CASE("infers the breach(TOO_LOW) according to PASSIVE_COOLING and send TO_EMAIL") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={PASSIVE_COOLING,"Bosch"};
  
  TestInterface_Reset();
  BreachTypeActual=checkAndAlert(TO_EMAIL,batteryChar,-5);
   
  REQUIRE(BreachTypeActual == TOO_LOW); 
  REQUIRE(Test_Controller_header == NULL);
  REQUIRE(Test_Controller_breachType == NULL);
  REQUIRE(strcmp(Test_Mail_recepient,"a.b@c.com")==0);
  REQUIRE(strcmp(Test_Mail_MailContent,"The temperature is to low")==0);
  REQUIRE(Test_Console_ConsoleContent == NULL);  
  REQUIRE(Func_CallCount_Controller == 0);
  REQUIRE(Func_CallCount_Mail == 1);
  REQUIRE(Func_CallCount_printf == 0);  
  
}


TEST_CASE("infers the breach(NORMAL) according to HI_ACTIVE_COOLING and send TO_EMAIL") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={HI_ACTIVE_COOLING,"Bosch"};
  
  TestInterface_Reset();
  BreachTypeActual=checkAndAlert(TO_EMAIL,batteryChar,30);
   
  REQUIRE(BreachTypeActual == NORMAL); 
  REQUIRE(Test_Controller_header == NULL);
  REQUIRE(Test_Controller_breachType == NULL);
  REQUIRE(strcmp(Test_Mail_recepient,"a.b@c.com")==0);
  REQUIRE(strcmp(Test_Mail_MailContent,"The temperature is normal")==0);
  REQUIRE(Test_Console_ConsoleContent == NULL);  
  REQUIRE(Func_CallCount_Controller == 0);
  REQUIRE(Func_CallCount_Mail == 1);
  REQUIRE(Func_CallCount_printf == 0);  
  
}


TEST_CASE("infers the breach(TOO_HIGH) according to MED_ACTIVE_COOLING and send TO_EMAIL") {
	
  BreachType BreachTypeActual;
  BatteryCharacter batteryChar={MED_ACTIVE_COOLING,"Bosch"};
  
  TestInterface_Reset();
  BreachTypeActual=checkAndAlert(TO_EMAIL,batteryChar,45);
   
  REQUIRE(BreachTypeActual == TOO_HIGH); 
  REQUIRE(Test_Controller_header == NULL);
  REQUIRE(Test_Controller_breachType == NULL);
  REQUIRE(strcmp(Test_Mail_recepient,"a.b@c.com")==0);
  REQUIRE(strcmp(Test_Mail_MailContent,"The temperature is too high")==0);
  REQUIRE(Test_Console_ConsoleContent == NULL);  
  REQUIRE(Func_CallCount_Controller == 0);
  REQUIRE(Func_CallCount_Mail == 1);
  REQUIRE(Func_CallCount_printf == 0);   
  
}

