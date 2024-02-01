//
// Created by Arian Dovald on 1/31/24.
//

#include "Simulation.h"

int Simulation::identifier = 0;
Universe Simulation::universe;

Simulation::Simulation() {
    universe.solver = "verlet";
    universe.B = vec(0, 0 , 0);
    universe.E = vec(0, 0, 0);
    universe.G = vec(0, 0, 0);
    universe.dt = 0.01;
    universe.forces = vector<string> {"electric", "magnetic", "gravity"};
}

// adds objects to universe
void Simulation::addObject(Object* o, bool physics) {
    Simulation::universe.addObject(*o);
    if (physics) {
        Simulation::universe.addPhysicsObject(*o);
    }
}

// call to begin simulation
void Simulation::simulate() {
    useSolver((string&)"verlet");
    Simulation::universe.simulate();
};

// functions to change universe and internal parameters of universe
void Simulation::useUniverse(Universe &u) {
    Simulation::universe = u;
}
void Simulation::useSolver(std::string& s) {
    Simulation::universe.solver = s;
}
void Simulation::setMagneticField(vec b) {
    Simulation::universe.B = b;
}
void Simulation::setElectricField(vec e) {
    Simulation::universe.E = e;
}
void Simulation::setGravity(vec g) {
    Simulation::universe.G = g;
}
void Simulation::setTimeStep(double t) {
    Simulation::universe.dt = t;
}
void Simulation::setActiveForces(vector<string> &l) {
    Simulation::universe.forces = l;
}
