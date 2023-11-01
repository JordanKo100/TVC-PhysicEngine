#include "gravity.hpp"
#include "objects/Particle.hpp"
#include "Vectors/vector.hpp"
#include "physics/forces.hpp"

void ParticleGravityFall(Particle &p, cyclone::real duration){
    // update particle position
    p.displacement.addScaledVector(p.velocity, duration);

    // making sure only force due to gravity is present
    p.acceleration.z = 9.81;
    cyclone::Vector3 resultAcc = p.acceleration;

    // update particle velocity
    p.velocity.addScaledVector(resultAcc, duration);
    
}