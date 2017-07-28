#ifndef ThreatManager_h
#define ThreatManager_h

#include "Arduino.h"
#include "IdentifiableThreat.h"

#define MAX_CAPACITY 10

class ThreatManager
{
  public:
  	void addIDThreat(IdentifiableThreat* threat);
  	IdentifiableThreat* findThreat(int id);

  private:
    IdentifiableThreat* _threats[MAX_CAPACITY];
};

#endif