#include "typewise-alert.h"
#include "TestDoublesHeader.h"
//#include <stdio.h>


BreachType inferBreach(double value, BreachLimitConfig breachLimit);
BreachType checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);


BreachType inferBreach(double value, BreachLimitConfig breachLimit) 
{
  if(value < breachLimit.lowerLimit) {
    return TOO_LOW;
  }
  if(value > breachLimit.upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}



BreachType checkAndAlert(AlertTarget alertTargetInput, BatteryCharacter batteryChar, double temperatureInC) 
{
BreachType breachTypeRet = inferBreach(temperatureInC,BreachLimitForCoolingType[batteryChar.coolingType]);
AlertTarget alertTargetRet = alertTarget[alertTargetInput].sendTo(breachTypeRet);
return breachTypeRet;
}



AlertTarget sendToController(BreachType breachType) 
{	
 // const unsigned short header = 0xfeed;
  const unsigned short header = ReadHeader();
 // printf("%x : %x\n", header, breachType);
  Controller(header, breachType);
  return TO_CONTROLLER;
}


AlertTarget sendToEmail(BreachType breachType) 
{
 // const char* recepient = "a.b@c.com";
  const char* recepient = ReadRecepient();
 // printf("To: %s\n", recepient);
 // printf("%s\n",&MailContent[breachType]);
  Mail(recepient,&MailContent[breachType]);
  return TO_EMAIL;
}

AlertTarget sendToConsole(BreachType breachType) 
{	
  //printf("%s\n",&ConsoleContent[breachType]);
  printf(&ConsoleContent[breachType]);
  return TO_CONSOLE;
}
