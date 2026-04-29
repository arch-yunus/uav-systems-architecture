import os
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # GNC - Trajectory Generator
        Node(
            package='sungur_architecture',
            executable='trajectory_generator_node',
            name='trajectory_generator',
            output='screen'
        ),
        
        # Mission Manager
        Node(
            package='sungur_architecture',
            executable='mission_manager',
            name='mission_manager',
            output='screen'
        ),
        
        # Middleware - Heartbeat Monitor
        Node(
            package='sungur_architecture',
            executable='heartbeat_monitor.py',
            name='heartbeat_monitor',
            output='screen'
        ),
        
        # Perception - Target Perception (Optional startup)
        Node(
            package='sungur_architecture',
            executable='target_perception_node.py',
            name='target_perception',
            output='screen'
        )
    ])
