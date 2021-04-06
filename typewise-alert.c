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
BreachType breachType = inferBreach(temperatureInC,BreachLimitForCoolingType[batteryChar.coolingType]);
alertTarget[alertTargetInput].sendTo(breachType);
return breachType;
}



void sendToController(BreachType breachType) 
{	
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}


void sendToEmail(BreachType breachType) 
{
  const char* recepient = "a.b@c.com";
      printf("To: %s\n", recepient);
    printf("%s\n",&MailContent[breachType]);

}

void sendToConsole(BreachType breachType) 
{	
  printf("%s\n",&ConsoleContent[breachType]);
}
