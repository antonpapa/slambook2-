//
// Created by gaoxiang on 19-5-4.
//

#include <gflags/gflags.h>
#include "myslam/visual_odometry.h"
//DEFINE_string 是 Google 的开源 C++ 库中 gflags 提供的一个宏，用于定义命令行标志（command-line flags）。
DEFINE_string(config_file, "./config/default.yaml", "config file path");

int main(int argc, char **argv) {
    //是 Google 的开源 C++ 库中 gflags 提供的一个函数，用于解析命令行标志
    google::ParseCommandLineFlags(&argc, &argv, true);

    myslam::VisualOdometry::Ptr vo(
    //使用 FLAGS_config_file 变量来获取用户提供的值，而不需要直接解析命令行参数。
    //gflags 库会在 google::ParseCommandLineFlags 被调用后，将用户提供的值设置到相应的标志变量中
        new myslam::VisualOdometry(FLAGS_config_file));
    assert(vo->Init() == true);//确保 vo->Init() 返回 true。如果返回 false，则程序会中止，并输出一条错误信息
    vo->Run();

    return 0;
}
