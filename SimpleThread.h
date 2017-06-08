/**************************************************************************
LIBRARY THREAD(DELAY NOT LOCKED) FOR ESP8266 OR LINE AVR
***************************************************************************
AUTOR: LUCAS MAZIERO - Electrical Engineer
E-MAIL: lucas.mazie.ro@hotmail.com
CIDADE: Santa Maria - Rio Grande do Sul - Brasil
***************************************************************************
Versão: 1.1
Data: 26/03/2016
Modificado: 24/03/2017
***************************************************************************
BASE DO CODIGO: https://github.com/thomasfredericks/Metro-Arduino-Wiring
***************************************************************************							
CHANGELOG:
* 26/03/2016 (1.0v):
    -> Initial version not have log :)
* 24/03/2017 (1.1v):
    -> Add new function "start", "stop" and "setInterval"
    -> Add new function "buttonIsPressTimeout" for use with
       button anti-debounce

***************************************************************************
Copyright(2016-2017) by: Lucas Maziero.
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
	void setInterval(unsigned long _interval_millis);
	boolean buttonIsPressTimeout(int pin, unsigned long intervalPress);
	boolean check(void);
	void start(void);
	void stop(void);
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
	unsigned long previous_millis, interval_millis;
	boolean flagStart = true;
};

#endif
