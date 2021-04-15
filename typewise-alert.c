#include "typewise-alert.h"
#include "TestDoublesHeader.h"


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
  const unsigned short header = ReadHeader();
  Controller(header, breachType);
  return TO_CONTROLLER;
}


AlertTarget sendToEmail(BreachType breachType) 
{
  char* recepient = ReadRecepient();
  Mail(recepient,(char*)&MailContent[breachType]);
  return TO_EMAIL;
}

AlertTarget sendToConsole(BreachType breachType) 
{	
  printf((char*)&ConsoleContent[breachType]);
  return TO_CONSOLE;
}
