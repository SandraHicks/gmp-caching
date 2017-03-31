/* 
 * File:   overflow_detection.h
 * Author: sandra
 *
 * Created on March 24, 2017, 1:25 PM
 */

#ifndef OVERFLOW_DETECTION_H
#define OVERFLOW_DETECTION_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "mastercache.h"

bool additionOverflow(cachedInt op1, cachedInt op2);
bool subtractionOverflow(cachedInt op1, cachedInt op2);
bool multiplicationOverflow(cachedInt op1, cachedInt op2);
bool divisionOverflow(cachedInt op1, cachedInt op2);
bool exponentiationOverflow(cachedInt base, cachedInt exp);

#ifdef __cplusplus
}
#endif

#endif /* OVERFLOW_DETECTION_H */

