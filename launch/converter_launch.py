from launch.actions import DeclareLaunchArgument

from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    converter = Node(
        name='converter',
        package='converter',
        executable='converter',
        output='screen'
        )
    
    return LaunchDescription([
        DeclareLaunchArgument(
            'use_sim_time',
            default_value='false',
            description='Use simulation (Gazebo) clock if true'
        ),
        converter
        ]
    )