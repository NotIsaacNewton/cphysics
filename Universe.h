//
// Created by Arian Dovald on 4/20/23.
//

#ifndef PHYSICS_UNIVERSE_H
#define PHYSICS_UNIVERSE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
#include "vec.h"
#include "Object.h"

class Object;

using namespace std;

// universes control the actual meat of the simulation.
// they hold the different solvers, field strengths, and functions to move forward time.
class Universe {
public:
    string solver;
    vec B = {0, 0, 0};
    vec E = {0, 0, 0};
    vec G = {0, 0, 0};
    double t;
    double dt;
    vector<string> forces;
    vector<Object> objects = {};
    vector<Object> physics = {};
    int n;
    bool stop;

    explicit Universe(const string& method="none", vec magnetic={0, 0, 0},
                      vec electric={0, 0, 0},
                      vec gravity={0, 0, 0}, double time_step=0.01,
                      const vector<string>& active_forces={"electric", "magnetic", "gravity"});

    // adds objects to universal objects list
    void addObject(Object o);

    // adds physics objects to universal physics objects list
    void addPhysicsObject(Object o);

    // calculates gravitational force
    void gravitational();

    // calculates electric force
    void electric();

    // calculates magnetic force
    void magnetic();

    // calculates all forces
    void force();

    // euler solver
    void euler();

    // verlet solver
    void verlet();

    //rk4 solver
    void rk4();

    // updates the universe by one step "dt" in time
    void update();

    // stops the simulation
    void end();

    // starts the simulation
    void start(double time);

    // threads end and start functions together
    void simulate(double time=0);
};

#endif //PHYSICS_UNIVERSE_H
