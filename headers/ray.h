#ifndef RAY_H
#define RAY_H


class ray {
public:
    ray() {}

    ray(const glm::dvec3& origin, const glm::dvec3& direction, double time) : orig(origin), dir(direction), tm(time) {}
    ray(const glm::dvec3& origin, const glm::dvec3& direction) : ray(origin, direction, 0) {}

    const glm::dvec3& origin() const { return orig; }
    const glm::dvec3& direction() const { return dir; }

    double time() const { return tm; }

    glm::dvec3 at(double t) const { return orig + t * dir; }

private:
    glm::dvec3 orig;
    glm::dvec3 dir;
    double tm;
};

#endif