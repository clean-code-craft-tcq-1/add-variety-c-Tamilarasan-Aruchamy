
extern unsigned short Test_Controller_header;
extern BreachType Test_Controller_breachType;
extern int Func_CallCount_Controller;

extern char* Test_Mail_recepient;
extern ConsoleMgsConfig* Test_Mail_MailContent;
extern int Func_CallCount_Mail;

extern char* Test_Console_ConsoleContent;
extern int Func_CallCount_printf;



extern int TestInterface_Reset();
extern int Controller(const unsigned short header,BreachType breachType);
extern int Mail(char* recepient,char* MailContent);
extern int printf(char* ConsoleContent);
extern char* ReadRecepient();
extern char* ReadHeader();

