#include <iostream>

class ThermalModel {
private:
    float tau;          // Time constant (how fast it responds)
    float alpha;        // Heating efficiency
    float T_ambient;    // Room temperature
    float T_current;    // Current temperature
    float dt;           // Time step
    
public:
    ThermalModel(float time_constant, float heating_eff, float ambient, float timestep)
        : tau(time_constant), alpha(heating_eff), 
          T_ambient(ambient), T_current(ambient), dt(timestep) {}
    
    float update(float heater_power) {
        float cooling = (1.0f / tau) * (T_ambient - T_current);
        float heating = alpha * heater_power;
        
        float dT = dt * (cooling + heating);
        T_current += dT;
        
        return T_current;
    }
    
    float getTemperature() { return T_current; }
};

int main() {
    ThermalModel system(60.0f, 0.5f, 25.0f, 0.1f);
    
    for (int i = 0; i < 100; i++) {
        float temp = system.update(50.0f);
        
        if (i % 10 == 0) {
            std::cout << "Step " << i << ": " << temp << " °C\n";
        }
    }
    
    return 0;
}