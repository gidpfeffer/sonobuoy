/*
This class was written by Gideon

This class is inteded to be used to add unique identification to threats.
It packs a threat with an id. The id should be unique from other threats.
*/

#include "Arduino.h"
#include "Threat.h"
#include "IdentifiableThreat.h"

IdentifiableThreat::IdentifiableThreat(Threat* threat, int id)
{
  _threat = threat;
  _id = id;
}

Threat* IdentifiableThreat::getThreat()
{
  return _threat;
}

int IdentifiableThreat::getID()
{
  return _id;
}