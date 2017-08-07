#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
  //talker is node name
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10); // 10 hz

  int count = 0;

  while (ros::ok())
    {
      std_msgs::String msg;

      std::stringstream ss;
      ss << "hello world " << count;
      msg.data = ss.str();

      ROS_INFO("talker: %s", msg.data.c_str()); // printout

      chatter_pub.publish(msg);

      ros::spinOnce(); //for callbacks

      loop_rate.sleep();
      ++count;
    }

  return 0;
}
