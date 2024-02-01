//
// Created by Arian Dovald on 4/20/23.
//

#ifndef PHYSICS_VEC_H
#define PHYSICS_VEC_H
#include <cmath>

using namespace std;

// does what you expect vectors to be able to do.
class vec {
public:
    double x, y, z;

    vec(double x_component, double y_component, double z_component);

    vec operator+(vec vector) const;

    void operator+=(vec vector);

    vec operator-(vec vector) const;

    void operator-=(vec vector);

    vec operator*(double m) const;

    vec operator/(double m) const;

    [[nodiscard]] double dot(vec vector) const;

    [[nodiscard]] double mag() const;

    [[nodiscard]] vec norm() const;

    [[nodiscard]] vec cross(vec vector) const;

    vec& operator=(const vec&);
};
#endif //PHYSICS_VEC_H
