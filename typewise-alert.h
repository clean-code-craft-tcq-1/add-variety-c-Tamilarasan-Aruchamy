#pragma once

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
  TO_CONSOLE,
  Max_AlertTarget
} AlertTarget;

typedef enum {
  PASSIVE_COOLING,
  HI_ACTIVE_COOLING,
  MED_ACTIVE_COOLING,
  Max_CoolingType
} CoolingType;

typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  Max_BreachType
} BreachType;

typedef struct {
  AlertTarget (*sendTo)(BreachType);
} AlertTargetConfig;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

typedef struct {
  double lowerLimit;
  double upperLimit;
} BreachLimitConfig;

typedef struct {
	char MailMsg[50];
} ConsoleMgsConfig;


AlertTarget sendToController(BreachType breachType);
AlertTarget sendToEmail(BreachType breachType);
AlertTarget sendToConsole(BreachType breachType);

static const BreachLimitConfig BreachLimitForCoolingType[Max_CoolingType]={ /* Index 0 - TOO_LOW Limit, 1 - TOO_HIGH Limit */ \
									[PASSIVE_COOLING]={0,35},\
									[HI_ACTIVE_COOLING]={0,45},\
									[MED_ACTIVE_COOLING]={0,40}};

static const AlertTargetConfig alertTarget[Max_AlertTarget]={	[TO_CONTROLLER]={&sendToController},\
								[TO_EMAIL]={&sendToEmail},\
								[TO_CONSOLE]={&sendToConsole}};

static const ConsoleMgsConfig MailContent[Max_BreachType]={ /* Alert mail when temperature is abnormal */ \
							{"The temperature is normal"},\
							{"The temperature is to low"},\
							{"The temperature is too high"}};

static const ConsoleMgsConfig ConsoleContent[Max_BreachType]={ /* Alert through console when temperature is abnormal */ \
							{"The temperature is normal"},\
							{"The temperature is to low"},\
							{"The temperature is too high"}};

