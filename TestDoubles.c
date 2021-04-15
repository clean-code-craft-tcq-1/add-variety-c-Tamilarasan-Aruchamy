#include "typewise-alert.h"
#include <stddef.h>

unsigned short Test_Controller_header=NULL;
int Test_Controller_breachType=NULL;
int Func_CallCount_Controller=0;

char* Test_Mail_recepient=NULL;
char* Test_Mail_MailContent=NULL;
int Func_CallCount_Mail=0;

char* Test_Console_ConsoleContent=NULL;
int Func_CallCount_printf=0;



int TestInterface_Reset()
{
Test_Controller_header=NULL;
Test_Controller_breachType=NULL;
Func_CallCount_Controller=0;

Test_Mail_recepient=NULL;
Test_Mail_MailContent=NULL;
Func_CallCount_Mail=0;

Test_Console_ConsoleContent=NULL;
Func_CallCount_printf=0;
	
}



int Controller(const unsigned short header,BreachType breachType)
{
	Test_Controller_header=header;
	Test_Controller_breachType=breachType;
	Func_CallCount_Controller++;
	return 1;
}

int Mail(char* recepient,char* MailContent)
{
	Test_Mail_recepient=recepient;
	Test_Mail_MailContent=MailContent;
	Func_CallCount_Mail++;
	return 1;
}



int printf(char* ConsoleContent)
{
	Test_Console_ConsoleContent=ConsoleContent;
	Func_CallCount_printf++;
	return 1;
}


char* ReadRecepient()
{	
	char* recepient="a.b@c.com";
	return recepient;
}


unsigned short ReadHeader()
{	
	unsigned short header = 0xfeed;
	return header;
}
