import launch
import launch.launch_description_sources
import launch_ros
from ament_index_python import get_package_share_directory
import launch_ros.parameter_descriptions
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    # 获取URDF路径
    urdf_file = get_package_share_directory('fishbot_description') + '/urdf/fhishbot/fishbot.urdf.xacro'
    default_gazebo_world_path = get_package_share_directory('fishbot_description') + '/world/custom_room.world'
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

    action_launch_gazebo  = launch.actions.IncludeLaunchDescription(
       launch.launch_description_sources.PythonLaunchDescriptionSource(
           get_package_share_directory('gazebo_ros') + '/launch/gazebo.launch.py'
       ),
         launch_arguments={
              'world': default_gazebo_world_path,
              'verbose': 'true',
         }.items()
    )

    action_spawn_entity = launch_ros.actions.Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=['-topic', '/robot_description','-entity', 'fishbot']
    )

    # Create a launch description with a robot state publisher
    return launch.LaunchDescription([
        action_declear_arg_mode_path,
        action_robot_state_publisher,
        action_launch_gazebo,
        action_spawn_entity
    ])