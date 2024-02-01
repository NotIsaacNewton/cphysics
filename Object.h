//
// Created by Arian Dovald on 4/20/23.
//

#ifndef PHYSICS_OBJECT_H
#define PHYSICS_OBJECT_H
#include <cmath>
#include <vector>
#include <algorithm>
#include "vec.h"
#include "Universe.h"

using namespace std;

class Universe;

// objects are the basic building blocks of a simulation. they can have charge, mass, velocity, position, etc.
// they also contain a unique id so that they can be quickly differentiated by the universe.
// objects also need to know what universe they're in, since there can be more than one universe running at a time.
class Object {
public:
    // object identifier
    int id = 0;
    // physical values
    vec fnet = {0, 0, 0};
    vec vel = {0, 0, 0};
    vec acc = {0, 0, 0};
    vec pos = {0, 0, 0};
    // special positions used for computation
    vec pos0 = {0, 0, 0};
    vec posn = {0, 0, 0};
    // mass and charge
    double m;
    double q;

    explicit Object(Universe& universe, bool physics=true,
                    vec position={0, 0, 0},
                    vec velocity={0, 0, 0},
                    vec acceleration={0, 0, 0},
                    vec net_force={0, 0, 0}, double mass=0, double charge=0);

    explicit Object(bool physics=true,
                    vec position={0, 0, 0},
                    vec velocity={0, 0, 0},
                    vec acceleration={0, 0, 0},
                    vec net_force={0, 0, 0}, double mass=0, double charge=0);

    bool operator==(Object o) const;

    bool operator!=(Object o) const;

    [[nodiscard]] bool find(const vector<Object> &l) const;
};

#endif //PHYSICS_OBJECT_H
