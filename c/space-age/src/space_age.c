#include "space_age.h"
#include <stdio.h> 

double convert_planet_age(enum planet p, unsigned long age_in_seconds) {
  double scale; 
  
  switch (p) { 
      case EARTH: 
        scale = 1.0;
        break;
      case MERCURY: 
        scale = 0.2408467;
        break;
      case VENUS:
        scale = 0.61519726;
        break;
      case MARS: 
        scale = 1.8808158;
        break;
      case JUPITER:
        scale = 11.862615;
        break;
      case SATURN:
        scale = 29.447498;
        break;
      case URANUS:
        scale = 84.016846;
        break;
      case NEPTUNE:
        scale = 164.79362;
        break;
      
      default: 
        scale = 0; 
        break;
  }
  
  double age = age_in_seconds / (31557600 * scale); 
  printf ("%lf - ", age);
  return age;
}