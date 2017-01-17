#include "StatechartEngine/interface_in.h"
#include "StatechartEngine/interface_out.h"
#include "railRoadModel_def.h"
#include "Viatra/Query/IteratorQuery/IteratorQueryQueryGroup.h"
#include "Viatra/Query/DerivedInput/CloseInputUpdater.h"
#include "Viatra/Query/DerivedInput/VeryCloseInputUpdater.h"

//#define DEBUG

#ifndef DEBUG
#include "ros/ros.h"
#include "demo/TrainSlow.h"
#include "demo/TrainStop.h"
#endif

#include <iostream>
#include <iomanip>
#include <vector>
#include <signal.h>

#define nullptr 0
using namespace ::railRoadModel;
using namespace ::Viatra::Query::DerivedInput;

struct mat4 {
    double m[4][4];
public:
    mat4() {}
    mat4(double m00, double m01, double m02, double m03,
         double m10, double m11, double m12, double m13,
         double m20, double m21, double m22, double m23,
         double m30, double m31, double m32, double m33) {
      m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
      m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
      m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
      m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
    }
    mat4 operator*(const mat4& right) {
      mat4 result;
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          result.m[i][j] = 0;
          for (int k = 0; k < 4; k++) result.m[i][j] += m[i][k] * right.m[k][j];
        }
      }
      return result;
    }
    static mat4 Translate(double tx, double ty, double tz) {
      return mat4(1,   0,   0,   0,
                  0,   1,   0,   0,
                  0,   0,   1,   0,
                  tx,  ty,  tz,   1);
    }
    static mat4 Rotate(double angle,double wx,double wy,double wz) {
      double cosa = cosf(angle);
      double sina = sinf(angle);
      return mat4(wx*wx*(1-cosa)+cosa,	wx*wy*(1-cosa)+wz*sina,	wx*wz*(1-cosa)-wy*sina,	0,
                  wx*wy*(1-cosa)-wz*sina,	wy*wy*(1-cosa)+cosa,	wy*wz*(1-cosa)+wx*sina,	0,
                  wx*wz*(1-cosa)+wy*sina,	wy*wz*(1-cosa)-wx*sina,	wz*wz*(1-cosa)+cosa,	0,
                  0,						0,						0,						1);
    }
    static mat4 Scale(double sx,double sy,double sz) {
      return mat4(sx,   0,   0,   0,
                  0,   sy,   0,   0,
                  0,    0,  sz,   0,
                  0,    0,   0,   1);
    }
};

struct vec4 {
    double v[4];
    vec4(double x = 0, double y = 0, double z = 0, double w = 1) {
      v[0] = x; v[1] = y; v[2] = z; v[3] = w;
    }
    vec4 operator*(const mat4& mat) {
      vec4 result;
      for (int j = 0; j < 4; j++) {
        result.v[j] = 0;
        for (int i = 0; i < 4; i++) result.v[j] += v[i] * mat.m[i][j];
      }
      return result;
    }
    vec4 operator*(double a){
      return vec4(v[0] * a, v[1] * a, v[2] *a);
    }
    vec4 operator+(const vec4& op){
      return vec4(v[0] + op.v[0], v[1] + op.v[1], v[2] + op.v[2]);
    }
    vec4 operator-(const vec4& op){
      return vec4(v[0] - op.v[0], v[1] - op.v[1], v[2] - op.v[2]);
    }
    double operator*(const vec4& op){
      return (v[0] * op.v[0] + v[1] * op.v[1] + v[2] * op.v[2]);
    }
    vec4 operator%(const vec4& op){
      return vec4(v[1]*op.v[2]-v[2]*op.v[1], v[2]*op.v[0] - v[0]*op.v[2], v[0]*op.v[1] - v[1]*op.v[0]);
    }
    double Length() const{
      return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]);
    }
    vec4 norm() const{
      return vec4(v[0],v[1],v[2],v[3]) * (1/Length());
    }
};

vec4 robotParts[3];
vec4 trainPos[3];

std::vector<Train*> trElements;
std::vector<RobotPart*> rpElements;

#ifndef DEBUG
// # ROS communication
ros::NodeHandle* n;
ros::Publisher slowStream_pub;
ros::Publisher stopStream_pub;
#endif

bool initializedComm = false;

void sendStopMessage(int trainID, bool stop){
#ifndef DEBUG
  uint8_t isStop = 0;
  if(stop) isStop = 1;
  demo::TrainStop trainStopMsg;
  trainStopMsg.trainID = trainID;
  trainStopMsg.stopTrain = isStop;
  if(initializedComm) stopStream_pub.publish(trainStopMsg);
#endif
}

void sendSlowDownMessage(int trainID, bool slowDown){
#ifndef DEBUG
  uint8_t isSlow = 0;
  if(slowDown) isSlow = 1;
  demo::TrainSlow trainSlowMsg;
  trainSlowMsg.trainID = trainID;
  trainSlowMsg.slowDown = isSlow;
  if(initializedComm) slowStream_pub.publish(trainSlowMsg);
#endif
}

void init_Comm(int argc, char** argv ){
#ifndef DEBUG
  ros::init(argc, argv, "stateMachine");
  n = new ros::NodeHandle();
  slowStream_pub = n->advertise<demo::TrainSlow>("slowStream", 1000);
  stopStream_pub = n->advertise<demo::TrainStop>("stopStream", 1000);
#endif
  initializedComm = true;
}
// # END ROS Communication

void init(int argc, char** argv){
	//Robot* r = new Robot(); rElements.push_back(r);
//TODO Determine RobotPart ids
	RobotPart* rp1 = new RobotPart(); rp1->id=1; rpElements.push_back(rp1);
	RobotPart* rp2 = new RobotPart(); rp2->id=2; rpElements.push_back(rp2);
	RobotPart* rp3 = new RobotPart(); rp3->id=3; rpElements.push_back(rp3);
//TODO Get Train id
	Train* tr1 = new Train(); tr1->id = 11; trElements.push_back(tr1);
	Train* tr2 = new Train(); tr2->id = 12; trElements.push_back(tr2);
	Train* tr3 = new Train(); tr3->id = 13; trElements.push_back(tr3);

	init_Comm(argc, argv);
}

void destruct(){
	for(auto element : trElements){
		delete element;
	}
	for(auto element : rpElements){
		delete element;
	}
	trElements.clear();
	rpElements.clear();
#ifndef DEBUG
	ros::shutdown();
	delete n;
#endif
}

void rotateRobot(){
  mat4 rotate = mat4::Translate(-robotParts[0].v[0],-robotParts[0].v[1],-robotParts[0].v[2]);
  rotate = rotate * mat4::Rotate(M_PI/2, 0,0,1);
  rotate = rotate * mat4::Translate(robotParts[0].v[0],robotParts[0].v[1],robotParts[0].v[1]);
  robotParts[1] = robotParts[1] * rotate;

  rotate = mat4::Translate(-robotParts[0].v[0],-robotParts[0].v[1],-robotParts[0].v[2]);
  rotate = rotate * mat4::Rotate(M_PI/2, 0,0,1);
  rotate = rotate * mat4::Translate(robotParts[0].v[0],robotParts[0].v[1],robotParts[0].v[2]);
  robotParts[2] = robotParts[2] * rotate;

  std::cout << std::setprecision(1) << "Robot Here:(x,y)-(x,y)-(x,y): (" << trainPos[0].v[0] << "," << trainPos[0].v[1] << ")-(" << trainPos[2].v[0] << "," << trainPos[2].v[1] << ")-(" << trainPos[2].v[0] << "," << trainPos[2].v[1] << ")" << std::endl;
}

void trainGo(){
  mat4 translate = mat4::Translate(1,0,0);
  for(int i = 0; i < 3; i++)
    trainPos[i] = trainPos[i] * translate;
  std::cout << std::setprecision(1) << "Train Here:(x,y)....(x,y): (" << trainPos[0].v[0] << "," << trainPos[0].v[1] << ")...(" << trainPos[2].v[0] << "," << trainPos[2].v[1] << ")" << std::endl;
}

using ModelRoot = Viatra::Query::ModelRoot;

void updateModel(){
  ModelRoot modelRoot;
  for (size_t rp = 0; rp < 3; rp++) { //#numofRobotparts
    for (size_t tr = 0; tr < 3; tr++) { //#numofTrains
      CloseInputUpdate::update(&modelRoot, rp+1, tr+11, robotParts[rp].v[0], robotParts[rp].v[1], robotParts[rp].v[2],
          trainPos[tr].v[0], trainPos[tr].v[1], trainPos[tr].v[2]);
      VeryCloseInputUpdate::update(&modelRoot, rp+1, tr+11, robotParts[rp].v[0], robotParts[rp].v[1], robotParts[rp].v[2],
          trainPos[tr].v[0], trainPos[tr].v[1], trainPos[tr].v[2]);
    }
  }
}

void init_poses(){
  robotParts[0] = vec4(2,0,0);
  robotParts[1] = vec4(2,6,0);
  robotParts[2] = vec4(2,8,0);
  trainPos[0] = vec4(-12,15,0);
  trainPos[1] = vec4(-22,15,0);
  trainPos[2] = vec4(-32,15,0);
}

int main(int argc, char** argv) {
  using namespace std::this_thread; // sleep_for, sleep_until
  using namespace std::chrono; // nanoseconds, system_clock, seconds
  //signal(SIGINT,quit);
  std::cout << "---Init---" << std::endl;
  init(argc, argv);
  init_poses();
  std::cout << "---Start---" << std::endl;
  std::cout << "---Init_State---" << std::endl;
  evaluate("turnOn");
  logStates();
  std::cout << "CLK---" << std::endl;
  evaluate("clk");
  std::cout << "---States---" << std::endl;
  logStates();
  while (true) {
    for (size_t i = 0; i < 32; i++) {
      switch(getState()){
        case 0:
          trainGo();
          trainGo();
	break;
	case 1:
	  trainGo();
	break;
	case 2:
	  rotateRobot();
	break;
	default:
	break;
      }
      updateModel();
      sleep_until(system_clock::now() + seconds(1));
      std::cout << "CLK---" << std::endl;
      evaluate("clk");
      std::cout << "---States---" << std::endl;
      logStates();
    }
    init_poses();
    std::cout << "---Restart---" << std::endl;
  }

}
