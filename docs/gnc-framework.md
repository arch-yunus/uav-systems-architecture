# GNC Framework Specification

This document outlines the Guidance, Navigation, and Control (GNC) framework for the UAV Systems Architecture.

## 1. Guidance
- Path planning using A* and RRT* algorithms.
- Real-time trajectory optimization.
- Dynamic waypoint generation.

## 2. Navigation
- EKF (Extended Kalman Filter) based state estimation.
- Visual-Inertial Odometry (VIO) for GPS-denied environments.
- Sensor fusion of GNSS, IMU, and Barometer.

## 3. Control
- PID and LQR control loops for stability.
- Robust control under varying wind conditions.
- Adaptive control for changing payloads.
