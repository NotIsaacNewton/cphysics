//
// Created by Arian Dovald on 4/21/23.
//
#include "vec.h"

vec::vec(double x_component, double y_component, double z_component) {
    x = x_component;
    y = y_component;
    z = z_component;
}

vec vec::operator+(vec vector) const {
    double new_x = x + vector.x;
    double new_y = y + vector.y;
    double new_z = z + vector.z;
    return {new_x, new_y, new_z};
}

void vec::operator+=(vec vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
}

vec vec::operator-(vec vector) const {
    double new_x = x - vector.x;
    double new_y = y - vector.y;
    double new_z = z - vector.z;
    return {new_x, new_y, new_z};
}

void vec::operator-=(vec vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
}

vec vec::operator*(double m) const {
    double new_x = x * m;
    double new_y = y * m;
    double new_z = z * m;
    return {new_x, new_y, new_z};
}

vec vec::operator/(double m) const {
    double new_x = x / m;
    double new_y = y / m;
    double new_z = z / m;
    return {new_x, new_y, new_z};
}

[[nodiscard]] double vec::dot(vec vector) const {
    double product = (x * vector.x) + (y * vector.y) + (z * vector.z);
    return product;
}

[[nodiscard]] double vec::mag() const {
    double magnitude = sqrt(dot(vec(x, y, z)));
    return magnitude;
}

[[nodiscard]] vec vec::norm() const {
    double magnitude = mag();
    double new_x = x/magnitude;
    double new_y = y/magnitude;
    double new_z = z/magnitude;
    return {new_x, new_y, new_z};
}

[[nodiscard]] vec vec::cross(vec vector) const {
    double new_x = (y * vector.z) - (z * vector.y);
    double new_y = (x * vector.z) - (z * vector.x);
    double new_z = (x * vector.y) - (y * vector.z);
    return {new_x, new_y, new_z};
}

vec& vec::operator=(const vec&) = default;
