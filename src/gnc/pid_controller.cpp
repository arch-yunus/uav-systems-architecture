/**
 * 🦅 SUNGUR GNC (Guidance, Navigation, Control)
 * Module: High-Frequency PID Controller
 * Developed with ⚔️ by arch-yunus
 */

#include <iostream>
#include <chrono>

class PIDController {
public:
    PIDController(double kp, double ki, double kd)
        : kp_(kp), ki_(ki), kd_(kd), prev_error_(0), integral_(0) {}

    double calculate(double setpoint, double actual, double dt) {
        double error = setpoint - actual;
        integral_ += error * dt;
        double derivative = (error - prev_error_) / dt;
        double output = (kp_ * error) + (ki_ * integral_) + (kd_ * derivative);
        prev_error_ = error;
        return output;
    }

private:
    double kp_, ki_, kd_;
    double prev_error_;
    double integral_;
};

int main() {
    // Örnek: Pitch Kontrolü (400Hz)
    PIDController pitch_pid(1.5, 0.05, 0.1);
    double target_pitch = 10.0;
    double current_pitch = 0.0;
    double dt = 1.0 / 400.0; // 400Hz cycle time

    std::cout << "--- SUNGUR GNC PID Loop Başlatıldı ---" << std::endl;

    for (int i = 0; i < 100; ++i) {
        double control_output = pitch_pid.calculate(target_pitch, current_pitch, dt);
        current_pitch += control_output * 0.1; // Simüle edilmiş tepki
        std::cout << "Cycle " << i << " | Pitch: " << current_pitch << " | Output: " << control_output << std::endl;
    }

    return 0;
}
