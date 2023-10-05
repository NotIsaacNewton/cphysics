//
// Created by Arian Dovald on 4/21/23.
//
#include "Object.h"

int identifier = 0;
Object::Object(Universe& universe, bool physics, vec position, vec velocity, vec acceleration, vec net_force,
               double mass, double charge) {
// sets correct value for identifier
id = identifier;
identifier++;
// adds object instance to universe's list of objects and physics objects
universe.add_object(*this);
if (physics) {
universe.add_physics_object(*this);
}
// defines physical values
fnet = net_force;
vel = velocity;
acc = acceleration;
pos = position;
m = mass;
q = charge;
}

bool Object::operator==(Object o) const {
    if (id==o.id) {
        return true;
    } else {
        return false;
    }
}

bool Object::operator!=(Object o) const {
    if (id != o.id) {
        return true;
    } else {
        return false;
    }
}

[[nodiscard]] bool Object::find(const vector<Object>& l) const {
    bool b = false;
    for (Object i: l) {
        if (i.id==id) {
            b = true;
            break;
        }
    }
    return b;
}
