#include <iostream>
#include <chrono>
#include <thread>

#include "physics/gravity.hpp"
#include "objects/Particle.hpp"
#include "Vectors/vector.hpp"

using namespace std;

int main(){
    cyclone::Vector3 ground;

    cyclone::Particle p1; 
    p1.setDisplacement(0,0,150); // in meters
    p1.setVelocity(0,0,0);

    const float timestep = 0.0333;
    float timer;

    p1.printInit();

    while(p1.displacement.z > 0){
                
        cout << "displacement: " << p1.displacement.z << endl;
        cout << "velocity: " << p1.velocity.z << endl;
        cout << "current time: " << timer << endl;

        ParticleGravityFall(p1,timestep);

        if (p1.displacement.z <= 0){
            GroundImpact(p1);  // needs more sophistication;
            timer += timestep;
            cout << "final displacement (z-axis): " << p1.displacement.z << endl;
            cout << "velocity: " << p1.velocity.z << endl;
            cout << "current time: " << timer << endl;
        }

        timer += timestep;
    }

    return 0;
}