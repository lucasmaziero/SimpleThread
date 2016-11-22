/**************************************************************************
		 LIBRARY THREAD(DELAY NOT LOCKED) FOR ESP8266 OR LINE AVR   
***************************************************************************
AUTOR: LUCAS MAZIERO - Eletrical Engineer                                                    
E-MAIL: lucas.mazie.ro@hotmail.com 									  
CIDADE: Santa Maria - Rio Grande do Sul - Brasil                                       
***************************************************************************
Versão: 1.0                                                             
Data: 26/03/2016                                                        
Modificado: --/--/----                                                                                                                          
***************************************************************************
BASE DO CODIGO: https://github.com/thomasfredericks/Metro-Arduino-Wiring
**************************************************************************/

#include "SimpleThread.h"

SimpleThread::SimpleThread()
{	
	interval_millis = 1000;	//default interval of 1000 milliseconds.
}

SimpleThread::SimpleThread(unsigned long _interval_millis)
{	
	interval_millis = _interval_millis;	
}

void SimpleThread::setInterval(unsigned long _interval_millis)
{	
	interval_millis = _interval_millis;	
}

void SimpleThread::start(void)
{
   if(!flagStart) reset();
   flagStart = true; 
}

void SimpleThread::stop(void)
{
	flagStart = false;
}

boolean SimpleThread::check(void)
{
  if(flagStart)
  {
	unsigned long now = millis();
  
	if ( now - previous_millis >= interval_millis)
	{
		previous_millis = now ; 
		return (true);
	} 
	return (false);
  }
  else
  {
	return (false);
  }
}

void SimpleThread::reset(void) 
{
	previous_millis = millis();
}

boolean SimpleThread::buttonIsPressTimeout(int pin, unsigned long intervalPress) 
{
	if(!digitalRead(pin))
	{
		setInterval(intervalPress);
		start();
		
		if(check())
		{
			return (true);
		}
	}
	else
	{
		stop();
		return (false);
	}
}
