#include <iostream>
#include "physics/gravity.hpp"
#include "objects/Particle.hpp"
#include "Vectors/vector.hpp"

using namespace std;

int main(){
    cyclone::Particle p1; 
    p1.setDisplacement(0,0,12);
    p1.setVelocity(0,0,-0.5);
    
    ParticleGravityFall(p1, 4);

    cout << p1.velocity.z << endl;

    return 0;
}