#pragma once

#include "../Vectors/vector.hpp"

namespace cyclone{
    class Particle{
        public:
            cyclone::Vector3 displacement;
            cyclone::Vector3 velocity;
            cyclone::Vector3 acceleration;

            cyclone::real damping;
            cyclone::real mass;

            Particle(): displacement(0,0,0), velocity(0,0,0), acceleration(0,0,0), mass(0){}

            cyclone::Vector3 setDisplacement(cyclone::real const x, cyclone::real const y, cyclone::real const z){
                displacement.x = x;
                displacement.y = y;
                displacement.z = z;
                return displacement;
            }
            cyclone::Vector3 setVelocity(cyclone::real const x, cyclone::real const y, cyclone::real const z){
                velocity.x = x;
                velocity.y = y;
                velocity.z = z;
                return velocity;
            }
            cyclone::Vector3 setAcceleration(cyclone::real const x, cyclone::real const y, cyclone::real const z){
                acceleration.x = x;
                acceleration.y = y;
                acceleration.z = z;
                return acceleration;
            }
            cyclone::real setMass(cyclone::real m){
                mass = m;
                return mass;
            }

    };
}