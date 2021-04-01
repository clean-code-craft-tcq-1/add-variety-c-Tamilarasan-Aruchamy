#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "typewise-alert.h"

extern BreachType checkAndAlert(AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

TEST_CASE("infers the breach according to limits") {
  BatteryCharacter batteryChar={PASSIVE_COOLING,"Bosch"};
  REQUIRE(checkAndAlert(TO_EMAIL,batteryChar,-5) == TOO_LOW);
}
