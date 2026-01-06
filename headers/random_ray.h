#ifndef RANDOM_RAY_H
#define RANDOM_RAY_H

#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>


class random_ray {
  public:
    
    static glm::dvec3 random() {
        return glm::dvec3(random_double(), random_double(), random_double());
    }

    static glm::dvec3 random(double min, double max) {
        return glm::dvec3(random_double(min,max), random_double(min,max), random_double(min,max));
    }
};


bool near_zero(glm::dvec3 vec_zero) {
    // return true if the vector is close to zero in all dimensions.
    auto s = 1e-8;
    return (glm::all(glm::lessThan(glm::abs(vec_zero), glm::dvec3(s))));
}



inline glm::dvec3 random_unit_vector() {
    while (true) {
        auto p = random_ray::random(-1,1);
        auto lensq = glm::length2(p);
        if (1e-160 < lensq && lensq <= 1)
            return p / sqrt(lensq);
    }
}


inline glm::dvec3 random_on_hemisphere(const glm::dvec3& normal) {
    glm::dvec3 on_unit_sphere = random_unit_vector();
    if (dot(on_unit_sphere, normal) > 0.0) // In the same hemisphere as the normal
        return on_unit_sphere;
    else
        return -on_unit_sphere;
}


inline glm::dvec3 reflect(const glm::dvec3& v, const glm::dvec3& n) {
    return v - 2*dot(v, n) * n;
}


inline glm::dvec3 refract(const glm::dvec3& uv, const glm::dvec3 n, double etai_over_etat) {
    auto cos_theta = std::fmin(dot(-uv, n), 1.0);

    glm::dvec3 r_out_perp = etai_over_etat * (uv + cos_theta*n);
    glm::dvec3 r_out_parallel = -std::sqrt(std::fabs(1.0 - glm::length2(r_out_perp))) * n;

    return r_out_perp + r_out_parallel;
}

inline glm::dvec3 random_in_unit_disk() {
    while (true) {
        auto p = glm::dvec3(random_double(-1,1), random_double(-1,1), 0);
        if (glm::length2(p) < 1)
            return p;
    }
}

#endif