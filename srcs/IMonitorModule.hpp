#ifndef IMonitorModule_H
#define IMonitorModule_H

#include "Window.class.hpp"

class IMonitorModule {
public:
    virtual ~IMonitorModule();
    virtual void displayGraph(Window *) = 0;

};

#endif
