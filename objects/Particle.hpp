#pragma once

#include "../Vectors/vector.hpp"

namespace cyclone{
    class Particle{
        public:
            bool onGround = true;

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
                if (displacement.z){
                    onGround = false;
                }
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

            void printInit(){
                printf("Initial displacement (x,y,z): %f %f %f \n", this->displacement.x, this->displacement.y, this->displacement.z);
                printf("Initial velocity (x,y,z): %f %f %f \n", this->velocity.x, this->velocity.y, this->velocity.z);
                printf("Initial acceleration (x,y,z): %f %f %f \n", this->acceleration.x, this->acceleration.y, this->acceleration.z);
            }

    };
}