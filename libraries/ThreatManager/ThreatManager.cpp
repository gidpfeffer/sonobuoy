/*
This class was written by Gideon

This class is inteded to be used to add unique identification to threats.
It packs a threat with an id. The id should be unique from other threats.
*/

#include "Arduino.h"
#include "IdentifiableThreat.h"
#include "ThreatManager.h"

void ThreatManager::addIDThreat(IdentifiableThreat* threat){
  _threats[0] = threat;
}

IdentifiableThreat* ThreatManager::findThreat(int id){
  for(int i = 0; i < MAX_CAPACITY; i++){
    if(_threats[i] -> getID() == id){
      return _threats[i];
    }
  }
  return 0;
}