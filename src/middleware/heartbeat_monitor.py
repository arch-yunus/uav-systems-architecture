#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import Header
import time

class HeartbeatMonitor(Node):
    """
    Monitors the heartbeat between CC and FC.
    Triggers failsafe if heartbeat is lost for more than 1 second.
    """
    def __init__(self):
        super().__init__('heartbeat_monitor')
        self.subscription = self.create_subscription(
            Header,
            'mavros/heartbeat',
            self.heartbeat_callback,
            10)
        
        self.last_heartbeat = time.time()
        self.timer = self.create_wall_timer(0.1, self.check_health)
        
        self.get_logger().info("Sovereign Heartbeat Monitor Initialized.")

    def heartbeat_callback(self, msg):
        self.last_heartbeat = time.time()

    def check_health(self):
        if time.time() - self.last_heartbeat > 1.0:
            self.get_logger().error("CRITICAL: Heartbeat Lost! Initiating Failsafe Protocol.")
            # TODO: Call Failsafe Service or Publish Emergency Command
        
def main(args=None):
    rclpy.init(args=args)
    node = HeartbeatMonitor()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
