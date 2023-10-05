//
// Created by Arian Dovald on 4/21/23.
//
#include "Universe.h"
#include <thread>

Universe::Universe(const string& method, vec magnetic, vec electric, vec gravity, double time_step,
                   const vector<string>& active_forces) {
    // solver to use
    solver = method;
    // physical values of environment
    B = magnetic;
    E = electric;
    G = gravity;
    // universal clock
    t = 0;
    dt = time_step;
    // list of active forces
    forces = active_forces;
    // tracks initial state of verlet
    n = 0;
    // tracks when the simulation should stop
    stop = false;
}

void Universe::add_object(Object o) {
    objects.push_back(o);
}

void Universe::add_physics_object(Object o) {
    physics.push_back(o);
}

void Universe::gravitational() {
    for (Object o: physics) {
        o.fnet += G;
        for (Object p: objects) {
            if (p != o) {
                o.fnet += (p.pos - o.posn).norm() * (6.7e-11 * p.m * o.m) /
                          pow((o.posn - p.pos).mag(), 2);
            }
        }
    }
}

void Universe::electric() {
    for (Object o: physics) {
        o.fnet += E;
        for (Object p: objects) {
            if (p != o) {
                o.fnet += (o.posn - p.pos).norm() * (9e9 * p.q * o.q) /
                          pow((o.posn - p.pos).mag(), 2);
            }
        }
    }
}

void Universe::magnetic() {
    for (Object o: physics) {
        o.fnet += o.vel.cross(B) * o.q;
        for (Object p: objects) {
            if (p != o) {
                o.fnet += o.vel.cross(p.vel.cross((o.posn - p.pos).norm())) * (1e-7 * o.q * p.q) /
                          pow((o.posn - p.pos).mag(), 2);
            }
        }
    }
}

void Universe::force() {
    for (string& f: forces) {
        if (f == "electric") {
            electric();
        } else if (f == "magnetic") {
            magnetic();
        } else if (f == "gravity") {
            gravitational();
        }
    }
}

void Universe::euler() {
    force();
    for (Object o: objects) {
        if (o.find(physics)) {
            o.acc += o.fnet / o.m;
        }
        o.vel += o.acc * dt;
        o.posn += o.vel * dt;
        o.fnet = {0, 0, 0};
    }
    for (Object o: objects) {
        o.pos = o.posn;
    }
    t += dt;
}

void Universe::verlet() {
    force();
    switch (n) {
        case 0:
            for (Object o: objects) {
                if (o.find(physics)) {
                    o.acc += o.fnet / o.m;
                }
                o.pos0 = o.posn;
                o.posn += (o.vel * dt) + (o.acc * pow(dt, 2) / 2);
                o.fnet = {0, 0, 0};
            }
            for (Object o: objects) {
                o.pos = o.posn;
            }
            n++;
            break;
        case 1:
            for (Object o: objects) {
                if (o.find(physics)) {
                    o.acc += o.fnet / o.m;
                }
                o.vel = o.posn - o.pos0;
                o.pos0 = o.posn;
                o.posn += o.vel + (o.acc * pow(dt, 2));
                o.fnet = {0, 0, 0};
            }
            for (Object o: objects) {
                o.pos = o.posn;
            }
            break;
    }
}

void Universe::update() {
    if (solver == "none") {
        stop = true;
        cout << "Please specify the method to use for the physics solver.";
    } else if (solver == "euler") {
        euler();
    } else if (solver == "verlet") {
        verlet();
    }
}

void Universe::end() {
    string input;
    cout << "\n" << "Press return to stop simulation." << "\n";
    input = cin.get();
    if (input == "\n") {
        stop = true;
    }
}

void Universe::start(double time) {
    if (time == 0) {
        while (!stop) {
            update();
        }
    } else {
        while (t < time && !stop) {
            update();
        }
    }
}

void Universe::simulate(double time) {
    thread ender([this](){end();});
    thread starter([this, time]() {start(time);});
    ender.join();
    starter.join();
}
