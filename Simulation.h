//
// Created by Arian Dovald on 1/31/24.
//

#ifndef PHYSICS_SIMULATION_H
#define PHYSICS_SIMULATION_H
#include "Universe.h"

// this class provides a unified framework to streamline simulations.
// if an instance is initiated, it initializes its own universe
// any objects created will automatically use that universe.
// also keeps track of all object id's.
// suggestion: initiate only one simulation instance at a time.
class Simulation {
public:
    static int identifier;
    static Universe universe;
    Simulation();

    // adds objects to universe
    static void addObject(Object* o, bool physics);

    // call to begin simulation
    static void simulate();

    // functions to change universe and internal parameters of universe
    static void useUniverse(Universe &u);
    static void useSolver(std::string& s);
    static void setMagneticField(vec m);
    static void setElectricField(vec e);
    static void setGravity(vec g);
    static void setTimeStep(double t);
    static void setActiveForces(vector<string> &l);
};


#endif //PHYSICS_SIMULATION_H
