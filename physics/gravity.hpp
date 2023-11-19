#pragma once

#include "../objects/Particle.hpp"
#include "../Vectors/vector.hpp"

/*
Function takes object to drop due to gravity.

TODO:
Possibly add damping force to this as well
*/
void ParticleGravityFall(cyclone::Particle &p, float duration) {
    // Ensure force due to gravity is present
    p.acceleration.z = -9.81;
    cyclone::Vector3 resultAcc = p.acceleration;

    // Update particle velocity
    p.velocity.addScaledVector(resultAcc, duration);

    // Update particle position
    p.displacement.addScaledVector(p.velocity, duration);
}

void GroundImpact(cyclone::Particle &p){
    // Calculate the time using the kinematic equation.
    p.displacement.z = 0.0;
    p.velocity.z = 0.0;
    p.acceleration.z = 0.0;
}