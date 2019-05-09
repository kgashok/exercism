#include "gigasecond.h"



#include <math.h> 

time_t gigasecond_after (time_t tt) {
    return tt + pow(10, 9);
}