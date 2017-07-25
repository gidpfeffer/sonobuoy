#ifndef IdentifiableThreat_h
#define IdentifiableThreat_h

#include "Arduino.h"
#include "Threat.h"

class IdentifiableThreat
{
  public:
    IdentifiableThreat(Threat* threat, int id);
    int getID();
    Threat* getThreat();

  private:
    int _id;
    Threat* _threat;
};

#endif