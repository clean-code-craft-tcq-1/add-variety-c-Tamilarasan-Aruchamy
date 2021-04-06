#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

extern int checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

TEST_CASE("infers the breach according to PASSIVE_COOLING and send to CONTROLLER") {
  BatteryCharacter batteryChar={PASSIVE_COOLING,"Bosch"};
  REQUIRE(checkAndAlert(TO_CONTROLLER,batteryChar,-5) == ((TOO_LOW+1)*(TO_CONTROLLER+1)));
}

TEST_CASE("infers the breach according to HI_ACTIVE_COOLING and send to EMAIL") {
  BatteryCharacter batteryChar={HI_ACTIVE_COOLING,"Bosch"};
  REQUIRE(checkAndAlert(TO_EMAIL,batteryChar,-5) == ((TOO_HIGH+1)*(TO_CONTROLLER+1)));
}

TEST_CASE("infers the breach according to MED_ACTIVE_COOLING and send to CONSOLE") {
  BatteryCharacter batteryChar={MED_ACTIVE_COOLING,"Bosch"};
  REQUIRE(checkAndAlert(TO_CONSOLE,batteryChar,-5) == ((NORMAL+1)*(TO_CONTROLLER+1)));
}
