// Copyright 2020 ros2_control Development Team
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <memory>
#include <vector>

#include "hardware_interface/components/sensor_interface.hpp"

using hardware_interface::status;
using hardware_interface::return_type;
using hardware_interface::StateHandle;

class TestSensor : public hardware_interface::components::SensorInterface
{
  return_type configure(const hardware_interface::HardwareInfo & sensor_info) override
  {
    sensor_info_ = sensor_info;
    return return_type::OK;
  }

  std::vector<StateHandle> export_state_handles() override
  {
    std::vector<StateHandle> state_handles;

    return state_handles;
  }

  return_type start() override
  {
    return return_type::OK;
  }

  return_type stop() override
  {
    return return_type::OK;
  }

  status get_status() const override
  {
    return status::UNKNOWN;
  }

  return_type read() override
  {
    return return_type::OK;
  }

private:
  hardware_interface::HardwareInfo sensor_info_;
};

#include "pluginlib/class_list_macros.hpp"  // NOLINT
PLUGINLIB_EXPORT_CLASS(TestSensor, hardware_interface::components::SensorInterface)
