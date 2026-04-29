#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
import cv2
import numpy as np

class TargetPerceptionNode(Node):
    """
    TargetPerceptionNode
    
    Bu düğüm, İHA üzerindeki kamera verisini işleyerek hedef tespiti
    ve takibi yapar. Donanımsal hızlandırma (TensorRT/OpenVINO) 
    entegrasyonu için optimize edilmiştir.
    """
    def __init__(self):
        super().__init__('target_perception_node')
        self.bridge = CvBridge()
        
        # Abonelik: GStreamer boru hattından gelen ham görüntü
        self.subscription = self.create_subscription(
            Image,
            'camera/image_raw',
            self.image_callback,
            10)
        
        self.get_logger().info("Target Perception Core Initialized.")
        
        # TODO: Load TensorRT Model here
        # self.model = load_tensorrt_engine('yolov8n_float16.engine')

    def image_callback(self, msg):
        try:
            # ROS Image -> OpenCV
            cv_image = self.bridge.imgmsg_to_cv2(msg, "bgr8")
            
            # --- Image Processing Pipeline ---
            # 1. Pre-processing (Resize, Normalize)
            # 2. Inference (AI Model)
            # 3. Post-processing (NMS, Bounding Boxes)
            
            # Placeholder: Simple color thresholding for target tracking
            hsv = cv2.cvtColor(cv_image, cv2.COLOR_BGR2HSV)
            mask = cv2.inRange(hsv, (0, 100, 100), (10, 255, 255)) # Red Target
            
            # Detect contours
            contours, _ = cv2.findContours(mask, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            if contours:
                largest = max(contours, key=cv2.contourArea)
                x, y, w, h = cv2.boundingRect(largest)
                cv2.rectangle(cv_image, (x, y), (x+w, y+h), (0, 255, 0), 2)
                self.get_logger().info(f"Target Detected at: {x+w/2}, {y+h/2}")

            # Visualization (Debug only)
            # cv2.imshow("SUNGUR Vision", cv_image)
            # cv2.waitKey(1)
            
        except Exception as e:
            self.get_logger().error(f"Perception Error: {str(e)}")

def main(args=None):
    rclpy.init(args=args)
    node = TargetPerceptionNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
