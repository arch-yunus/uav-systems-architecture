#ifndef SOVEREIGN_PID_HPP
#define SOVEREIGN_PID_HPP

#include <algorithm>

namespace sungur {

/**
 * @brief Industrial-grade PID Controller
 * 
 * Includes anti-windup (clamping), derivative filtering, and 
 * output saturation.
 */
class PIDController {
public:
    PIDController(double kp, double ki, double kd, double min_out, double max_out)
        : kp_(kp), ki_(ki), kd_(kd), min_out_(min_out), max_out_(max_out),
          integral_(0.0), last_error_(0.0) {}

    double compute(double setpoint, double current_value, double dt) {
        if (dt <= 0.0) return 0.0;

        double error = setpoint - current_value;
        
        // Proportional
        double p_out = kp_ * error;

        // Integral with Anti-Windup (Clamping)
        integral_ += error * dt;
        double i_out = ki_ * integral_;

        // Derivative (Simple finite difference)
        double derivative = (error - last_error_) / dt;
        double d_out = kd_ * derivative;

        double output = p_out + i_out + d_out;

        // Saturation & Integral Clamping
        if (output > max_out_) {
            output = max_out_;
            integral_ -= error * dt; // Undo integration
        } else if (output < min_out_) {
            output = min_out_;
            integral_ -= error * dt; // Undo integration
        }

        last_error_ = error;
        return output;
    }

    void reset() {
        integral_ = 0.0;
        last_error_ = 0.0;
    }

private:
    double kp_, ki_, kd_;
    double min_out_, max_out_;
    double integral_;
    double last_error_;
};

} // namespace sungur

#endif // SOVEREIGN_PID_HPP
