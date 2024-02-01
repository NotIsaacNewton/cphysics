//
// Created by Arian Dovald on 4/21/23.
//
#include "Object.h"
#include "Simulation.h"


Object::Object(Universe& universe, bool physics, vec position, vec velocity, vec acceleration, vec net_force,
               double mass, double charge) {
    // sets correct value for identifier
    id = Simulation::identifier;
    Simulation::identifier++;
    // adds object instance to universe's list of objects and physics objects
    universe.addObject(*this);
    if (physics) {
        universe.addPhysicsObject(*this);
    }
    // defines physical values
    fnet = net_force;
    vel = velocity;
    acc = acceleration;
    pos = position;
    m = mass;
    q = charge;
}

Object::Object(bool physics, vec position, vec velocity, vec acceleration, vec net_force,
               double mass, double charge) {
    // sets correct value for identifier
    id = Simulation::identifier;
    Simulation::identifier++;
    // lets the simulation know that an object has been created, and needs to be added to the universe
    Simulation::addObject(this, physics);
    // set values
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

[[nodiscard]] bool Object::find(const vector<Object> &l) const {
    bool b = false;
    for (Object i: l) {
        if (i.id==id) {
            b = true;
            break;
        }
    }
    return b;
}
