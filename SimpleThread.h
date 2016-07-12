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

#ifndef SimpleThread_h
#define SimpleThread_h

#include "Arduino.h"

class SimpleThread
{
	public:
		/**************************************************************************
		Functions public     
		***************************************************************************/
		SimpleThread();
		SimpleThread(unsigned long interval_millis);
		boolean check(void);
		void reset(void);
		
		/**************************************************************************
		variables public     
		***************************************************************************/
	
	private:
		/**************************************************************************
		Functions private   
		***************************************************************************/
		
		
		/**************************************************************************
		variables private    
		***************************************************************************/
		unsigned long  previous_millis, interval_millis;
};

#endif


