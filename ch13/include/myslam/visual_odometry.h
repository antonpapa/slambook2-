#pragma once
#ifndef MYSLAM_VISUAL_ODOMETRY_H
#define MYSLAM_VISUAL_ODOMETRY_H

#include "myslam/backend.h"
#include "myslam/common_include.h"
#include "myslam/dataset.h"
#include "myslam/frontend.h"
#include "myslam/viewer.h"

namespace myslam {

/**
 * VO 对外接口
 */
class VisualOdometry {
   public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW;//是 Eigen 库提供的一个宏，用于在包含 Eigen 类成员的类中正确地定义 operator new
    typedef std::shared_ptr<VisualOdometry> Ptr;//用Ptr代表一个<VisualOdometry>类的智能指针

    /// constructor with config file
    VisualOdometry(std::string &config_path);//声明VisualOdometry函数

    /**
     * do initialization things before run
     * @return true if success
     */
    bool Init();

    /**
     * start vo in the dataset
     */
    void Run();//启动 VisualOdometry的接口函数声明

    /**
     * Make a step forward in dataset
     */
    bool Step();

    /// 定义了一个名为GetFrontendStatus的常量成员函数获取前端状态，函数体内还调用了一个叫GetStatus的函数，他是frontend的成员函数
    FrontendStatus GetFrontendStatus() const 
   { 
      return frontend_->GetStatus(); 
   }

   private:
    bool inited_ = false;
    std::string config_file_path_;

    Frontend::Ptr frontend_ = nullptr;
    Backend::Ptr backend_ = nullptr;
    Map::Ptr map_ = nullptr;
    Viewer::Ptr viewer_ = nullptr;

    // dataset
    Dataset::Ptr dataset_ = nullptr;
};
}  // namespace myslam

#endif  // MYSLAM_VISUAL_ODOMETRY_H
