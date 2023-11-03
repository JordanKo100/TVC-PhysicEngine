#pragma once

#include "../objects/Particle.hpp"

void ParticleGravityFall(cyclone::Particle &p, float duration){
    // update particle position
    p.displacement.addScaledVector(p.velocity, duration);

    // making sure only force due to gravity is present
    p.acceleration.z = 9.81;
    cyclone::Vector3 resultAcc = p.acceleration;

    // update particle velocity
    p.velocity.addScaledVector(resultAcc, duration);
    
}