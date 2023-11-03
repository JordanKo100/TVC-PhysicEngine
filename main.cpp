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
    p1.setDisplacement(0,0,12);
    p1.setVelocity(0,0,-0.5);


    chrono::milliseconds framerate(33);
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    while(p1.displacement.magnitude() >= ground.magnitude()){
        chrono::steady_clock::time_point startInterval = chrono::steady_clock::now();
        auto count = startInterval.time_since_epoch().count();

        // Convert count to seconds
        double seconds = static_cast<double>(count) * std::chrono::steady_clock::period::num / std::chrono::steady_clock::period::den;
        ParticleGravityFall(p1, seconds);
        chrono::steady_clock::time_point endInterval = chrono::steady_clock::now(); 

        cout << p1.displacement.z << endl;

        chrono::steady_clock::duration timeElapsed = endInterval - startInterval;
        int timeToSleep = framerate.count() - timeElapsed.count();
        if (timeToSleep > 0){
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToSleep));
        }
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    chrono::steady_clock::duration d = end - start;
    cout << "Time duration for object to fall: " << d.count() << endl;




    cout << p1.displacement.z << endl;

    return 0;
}