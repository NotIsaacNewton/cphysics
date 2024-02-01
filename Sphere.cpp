//
// Created by Arian Dovald on 1/31/24.
//

#include "Sphere.h"


Sphere::Sphere(Universe &universe, bool physics, vec position, vec velocity, vec acceleration, vec net_force,
               double mass, double charge, double radius): Object(universe, physics, position, velocity,
                                                                  acceleration, net_force, mass, charge) {
    r = radius;
}

Sphere::Sphere(bool physics, vec position, vec velocity, vec acceleration, vec net_force,
               double mass, double charge, double radius): Object(physics, position, velocity, acceleration,
                                                                  net_force, mass, charge) {
    r = radius;
}


void Sphere::drawSphere() {
    // does nothing right now
}
