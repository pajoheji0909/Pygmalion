#pragma once
#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_
#include <iostream>
#include "Leap.h"
#include "LeapMath.h"
#include <time.h>

using namespace Leap;

class Leap_Listener : public Listener {
public:
	virtual void onConnect(const Controller&);
	virtual void onDisconnect(const Controller&);
	virtual void onFrame(const Controller&);
};
void ex();
extern float **fingerPos;
#endif
