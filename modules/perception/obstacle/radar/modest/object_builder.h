/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#ifndef MODULES_PERCEPTION_OBSTACLE_RADAR_MODEST_OBJECT_BUILDER_H_
#define MODULES_PERCEPTION_OBSTACLE_RADAR_MODEST_OBJECT_BUILDER_H_

#include <Eigen/Core>
#include <map>
#include <memory>
#include "modules/common/log.h"
#include "modules/perception/obstacle/base/object.h"
#include "modules/perception/obstacle/base/types.h"
#include "modules/perception/obstacle/radar/interface/base_radar_detector.h"
#include "modules/perception/obstacle/radar/modest/radar_define.h"

namespace apollo {
namespace perception {
class ObjectBuilder {
 public:
  ObjectBuilder(): delay_frames_(4), use_fp_filter_(true) {
  }
  ~ObjectBuilder() {}
  void Build(const ContiRadar &raw_obstacles,
             const Eigen::Matrix4d &radar_pose,
             const Eigen::Vector2d &main_velocity,
             SensorObjects *radar_objects);

  void SetDelayFrame(int delay_frames) {
    delay_frames_ = delay_frames;
  }

  void SetUseFpFilter(bool use_fp_filter) {
    use_fp_filter_ = use_fp_filter;
  }

  void SetContiParams(const ContiParams &conti_params) {
    conti_params_ = conti_params;
  }

 private:
  std::map<int, int> continuous_ids_;
  int delay_frames_;
  bool use_fp_filter_;
  ContiParams conti_params_;
};

}  // namespace perception
}  // namespace apollo
#endif  // MODULES_PERCEPTION_OBSTACLE_RADAR_MODEST_OBJECT_BUILDER_H_
