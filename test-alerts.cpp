#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

extern int checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

int expectedResult(BreachType breachType,AlertTarget alertTarget)
{
	return ((breachType+1)*(alertTarget+1)); // Why "+1" with return value? Enum value start from index 0 for BreachType,AlertTarget.So +1 is needed to calculation.
	
}

TEST_CASE("infers the breach(TOO_LOW) according to PASSIVE_COOLING and send to CONTROLLER") {
  BatteryCharacter batteryChar={PASSIVE_COOLING,"Bosch"};
  REQUIRE(checkAndAlert(TO_CONTROLLER,batteryChar,-5) == expectedResult(TOO_LOW,TO_CONTROLLER));
}

TEST_CASE("infers the breach(TOO_HIGH) according to HI_ACTIVE_COOLING and send to EMAIL") {
  BatteryCharacter batteryChar={HI_ACTIVE_COOLING,"Bosch"};
  REQUIRE(checkAndAlert(TO_EMAIL,batteryChar,50) == expectedResult(TOO_HIGH,TO_EMAIL));
}

TEST_CASE("infers the breach(NORMAL) according to MED_ACTIVE_COOLING and send to CONSOLE") {
  BatteryCharacter batteryChar={MED_ACTIVE_COOLING,"Bosch"};
  REQUIRE(checkAndAlert(TO_CONSOLE,batteryChar,20) == expectedResult(NORMAL,TO_CONSOLE));
}
