#ifndef _PLANET_AGE_H
#define _PLANET_AGE_H

enum planet {
  MERCURY,
  VENUS,
  EARTH,
  MARS, /* terrestrial planets */
  JUPITER,
  SATURN,
  URANUS,
  NEPTUNE /* gas giants */
};

double convert_planet_age(enum planet, unsigned long);

#endif