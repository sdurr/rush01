#ifndef IMonitorDisplay_H
#define IMonitorDisplay_H

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay();
		virtual void display( void ) = 0;
};

#endif
