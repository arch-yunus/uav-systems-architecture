# 📡 MAVLink & DDS Bridge Architecture

This document details the middleware strategy for bridging high-level ROS2 (DDS) communication with low-level Flight Controller (MAVLink) data.

## 1. Overview
The bridge serves as the translation layer between the asychronous, topic-based world of ROS2 and the serial-oriented, message-based world of MAVLink.

## 2. Technology Stack
- **DDS Implementation:** eProsima FastDDS (Hardened QoS).
- **MAVLink Version:** 2.0 with signing.
- **Bridge Tool:** `micro-ros-agent` for modern RTOS or `mavros` for legacy support.

## 3. Communication Flow
```mermaid
graph LR
    A[Companion Computer] -->|DDS| B[micro-ros-agent]
    B -->|UART/Ethernet| C[Flight Controller]
    C -->|MAVLink| B
```

## 4. QoS Tuning for Resilient Link
To ensure "Siber-Asabiyet", we use the following QoS parameters:
- **Reliability:** RELIABLE for mission commands, BEST_EFFORT for high-frequency telemetry.
- **History:** Keep last 10 samples to minimize latency.
- **Durability:** TRANSIENT_LOCAL for static metadata (e.g., hardware IDs).
