/*  
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. 
 * 
 * Author: Lena Voytek
 */

#include "HoleSensor.h"

boolean HoleSensor::begin()
{
    this->isOnline = this->cap.begin();

    return this->isOnline;
}

uint16_t HoleSensor::getPressed()
{
    //Attempt reboot
    if(!this->isOnline)
        this->begin();

    //Invalid reading
    if(!this->isOnline)
        return 1;

    return this->cap.touched();    
}