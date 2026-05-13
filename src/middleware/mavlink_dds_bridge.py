#!/usr/bin/env python3
import time
import os

# Dummy fallback for environments without rclpy or pymavlink
try:
    import rclpy
    from rclpy.node import Node
    # Optional: std_msgs or custom px4_msgs would be used here
    # from std_msgs.msg import String
    from pymavlink import mavutil
    HAS_DEPS = True
except ImportError:
    HAS_DEPS = False

class MavlinkDDSBridgeNode:
    """
    Sovereign MAVLink-DDS Bridge Prototype
    Translates MAVLink telemetry from the Flight Controller to ROS2 DDS Topics.
    """
    def __init__(self):
        # We simulate the ROS2 Node initialization for environment compatibility
        self.node_name = 'mavlink_dds_bridge'
        self.connection_string = os.environ.get('MAVLINK_CONN', 'udp:127.0.0.1:14550')
        print(f"[{self.node_name}] Initializing Sovereign MAVLink-DDS Bridge...")
        print(f"[{self.node_name}] Connecting to FCU at: {self.connection_string}")
        
        if HAS_DEPS:
            # Setup real pymavlink connection
            try:
                self.master = mavutil.mavlink_connection(self.connection_string)
                self.master.wait_heartbeat()
                print(f"[{self.node_name}] Heartbeat received from system (system {self.master.target_system} component {self.master.target_component})")
            except Exception as e:
                print(f"[{self.node_name}] Connection failed: {e}. Running in simulation mode.")
                self.master = None
        else:
            print(f"[{self.node_name}] Missing pymavlink/rclpy. Running in dummy logging mode.")
            self.master = None

    def spin(self):
        print(f"[{self.node_name}] Starting telemetry bridge loop. (Press Ctrl+C to stop)")
        try:
            while True:
                if self.master:
                    msg = self.master.recv_match(blocking=False)
                    if msg:
                        # In a real scenario, map MAVLink messages to ROS2 Publisher Topics
                        msg_type = msg.get_type()
                        if msg_type in ['HEARTBEAT', 'ATTITUDE', 'GLOBAL_POSITION_INT']:
                            print(f"[DDS Publish] Topic: /fcu/{msg_type.lower()} | Data: {msg.to_dict()}")
                else:
                    # Simulated bridge output
                    print("[DDS Publish] Topic: /fcu/heartbeat | Data: {'custom_mode': 0, 'type': 2, 'autopilot': 3, 'base_mode': 81, 'system_status': 4}")
                    time.sleep(1.0)
                    print("[DDS Publish] Topic: /fcu/attitude | Data: {'time_boot_ms': 12345, 'roll': 0.01, 'pitch': -0.02, 'yaw': 1.57}")
                    time.sleep(1.0)
                
        except KeyboardInterrupt:
            print(f"\n[{self.node_name}] Shutting down bridge gracefully.")

def main(args=None):
    if HAS_DEPS:
        rclpy.init(args=args)
        # Using a dummy class since we don't strictly inherit Node to avoid crashes without rclpy
        bridge = MavlinkDDSBridgeNode()
        bridge.spin()
        rclpy.shutdown()
    else:
        # Fallback dummy execution
        bridge = MavlinkDDSBridgeNode()
        bridge.spin()

if __name__ == '__main__':
    main()
