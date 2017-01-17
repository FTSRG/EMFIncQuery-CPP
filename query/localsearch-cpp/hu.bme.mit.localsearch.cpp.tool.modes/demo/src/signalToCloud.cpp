#define DEBUG
#ifndef DEBUG
#include "ros/ros.h"
#include "demo/TrainSlow.h"
#include "demo/TrainStop.h"

ros::NodeHandle* n = nullptr;
ros::Subscriber slowSub;
ros::Subscriber stopSub;

void trainSlowCallback(const demo::TrainSlow::ConstPtr record);
void trainStopCallback(const demo::TrainStop::ConstPtr record);

void init(int argc, char** argv){
  ros::init(argc, argv, "signalToCloud");
  n = new ros::NodeHandle();

  slowSub = n->subscribe("slowStream", 1000, trainSlowCallback);
  stopSub = n->subscribe("stopStream", 1000, trainStopCallback);

  ros::spin();
}

int main(int argc, char** argv)
{
  init(argc, argv);
  return 0;
}

void trainSlowCallback(const demo::TrainSlow::ConstPtr record){
  if(record->slowDown == 1) ROS_DEBUG("Slow - Train(id=%d)",record->trainID);
}

void trainStopCallback(const demo::TrainStop::ConstPtr record){
  if(record->stopTrain == 1) ROS_DEBUG("   STOP - Train(id=%d)", record->trainID);
}
#endif
