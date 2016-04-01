/*
 * Wakes in the simulation environment
 *
 * Author: Roice (LUO Bing)
 * Date: 2016-03-08 create this file (RAOS)
 */

#ifndef WAKE_H
#define WAKE_H

#include "model/SimModel.h"

void WakesInit(std::vector<Robot*>*);
void WakesUpdate(std::vector<Robot*>*, const char*, SimState_t*); // update all of the wakes in the environment
void WakesFinish(void);

// for plume puffs
void WakesIndVelatPlumePuffsInit(std::vector<Robot*>*, std::vector<FilaState_t>*);
void WakesIndVelatPlumePuffsUpdate(std::vector<Robot*>*, std::vector<FilaState_t>*);

#endif

/* End of file wake.h */
