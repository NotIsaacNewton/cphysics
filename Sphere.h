//
// Created by Arian Dovald on 1/31/24.
//

#ifndef PHYSICS_SPHERE_H
#define PHYSICS_SPHERE_H
#include "Object.h"

// sphere object!
class Sphere: public Object {
public:
    double r = 1.0;
    // used to creates new sphere instance.
    explicit Sphere(Universe& universe, bool physics=true,
           vec position={0, 0, 0},
           vec velocity={0, 0, 0},
           vec acceleration={0, 0, 0},
           vec net_force={0, 0, 0}, double mass=0, double charge=0,
           double radius = 0);

    explicit Sphere(bool physics=true,
                    vec position={0, 0, 0},
                    vec velocity={0, 0, 0},
                    vec acceleration={0, 0, 0},
                    vec net_force={0, 0, 0}, double mass=0, double charge=0,
                    double radius = 0);

    // call opengl code to draw sphere
    void drawSphere();
};

#endif //PHYSICS_SPHERE_H
