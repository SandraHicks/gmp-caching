 /**
  * @file overflow_detection.h
  * @author Sandra Hicks
  * @brief header for overflow detection functions
  */

#ifndef OVERFLOW_DETECTION_H
#define OVERFLOW_DETECTION_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "mastercache.h"

int additionOverflow(cachedInt op1, cachedInt op2);
int multiplicationOverflow(cachedInt op1, cachedInt op2);
int exponentiationOverflow(cachedInt base, cachedInt exp);

#ifdef __cplusplus
}
#endif

#endif /* OVERFLOW_DETECTION_H */

