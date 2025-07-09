import launch
import launch_ros
from ament_index_python import get_package_share_directory
import launch_ros.parameter_descriptions

def generate_launch_description():
    # 获取URDF路径
    urdf_file = get_package_share_directory('fishbot_description') + '/urdf/first_robot.urdf'
    default_rviz_config_path = get_package_share_directory('fishbot_description') + '/rviz_config/display_robot_modle.rviz'
    #声明一个URDF目录参数方便修改
    action_declear_arg_mode_path = launch.actions.DeclareLaunchArgument(
        'modle',
        default_value=str(urdf_file),
        description='加载的URDF模型文件路径'
    )
    
    #通过文件路径获取内容并转换成参数值
    substitutions_command_result = launch.substitutions.Command(['xacro ',launch.substitutions.LaunchConfiguration('modle')])
    robot_description_value = launch_ros.parameter_descriptions.ParameterValue(
        substitutions_command_result,
        value_type=str
    )

    action_robot_state_publisher = launch_ros.actions.Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        parameters=[{'robot_description': robot_description_value}],
    )

    action_joint_state_publisher = launch_ros.actions.Node(
        package='joint_state_publisher',
        executable='joint_state_publisher'
    )

    action_rviz_node = launch_ros.actions.Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', default_rviz_config_path],
    )

    # Create a launch description with a robot state publisher
    return launch.LaunchDescription([
        action_declear_arg_mode_path,
        action_robot_state_publisher,
        action_joint_state_publisher,
        action_rviz_node
    ])