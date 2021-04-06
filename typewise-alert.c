#include "typewise-alert.h"
#include <stdio.h>



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
return ((breachTypeRet+1)*(alertTargetRet+1));
}



AlertTarget sendToController(BreachType breachType) 
{	
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
  return TO_CONTROLLER;
}


AlertTarget sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
  printf("To: %s\n", recepient);
  printf("%s\n",&MailContent[breachType]);
  return TO_EMAIL;
}

AlertTarget sendToConsole(BreachType breachType) 
{	
  printf("%s\n",&ConsoleContent[breachType]);
  return TO_CONSOLE;
}
