#ifndef stc_interface_in_h
#define stc_interface_in_h
#include "ros/ros.h"

ros::Publisher slowStream_pub;
ros::Publisher stopStream_pub;

void evaluate(char const*);
void evaluate(char const*, int);
void logStates();
void initStatechartEngine();

#endif
