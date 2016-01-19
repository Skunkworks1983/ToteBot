#ifndef SKUNK_ENCODER_H
#define SKUNK_ENCODER_H

#include "WPILib.h"
#include <CounterBase.h>
#include <LiveWindow/LiveWindowSendable.h>
#include <PIDSource.h>
#include <SensorBase.h>

struct Data {
	int *counter;
	priority_mutex *m_mutex;
	DigitalInput * m_DataSource;
	DigitalInput * m_SignSource;
};

class SkunkEncoder: public PIDSource {
public:
	SkunkEncoder(int dataPort, int signPort);
	virtual ~SkunkEncoder();
	int GetPosition();
	void Reset();
	double PIDGet();
private:
	int current_position;
	DigitalInput *dataSource, *signSource;
	priority_mutex *mutex;
	Data *data;
};

#endif

