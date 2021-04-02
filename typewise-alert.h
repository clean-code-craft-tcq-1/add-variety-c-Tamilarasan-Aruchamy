#pragma once

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL,
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
  void (*sendTo)(BreachType);
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


void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);


static const BreachLimitConfig BreachLimitByCoolingType[Max_CoolingType]={[PASSIVE_COOLING]={0,35},[HI_ACTIVE_COOLING]={0,45},[MED_ACTIVE_COOLING]={0,40}};
static const AlertTargetConfig alertTarget[Max_AlertTarget]={[TO_CONTROLLER]={&sendToController},[TO_EMAIL]={&sendToEmail}};

static const ConsoleMgsConfig MailContent[Max_BreachType]={{"The temperature is normal"},{"The temperature is to low"},{"The temperature is too high"}};


