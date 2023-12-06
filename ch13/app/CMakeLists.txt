add_executable(run_kitti_stereo run_kitti_stereo.cpp)//添加可执行文件
target_link_libraries(run_kitti_stereo myslam ${THIRD_PARTY_LIBS})//链接库文件
