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

#include "hardware_interface/components/actuator_interface.hpp"

using hardware_interface::status;
using hardware_interface::return_type;
using hardware_interface::StateHandle;
using hardware_interface::CommandHandle;

class TestActuator : public hardware_interface::components::ActuatorInterface
{
  return_type configure(const hardware_interface::HardwareInfo & actuator_info) override
  {
    actuator_info_ = actuator_info;
    return return_type::OK;
  }

  std::vector<StateHandle> export_state_handles() override
  {
    std::vector<StateHandle> state_handles;
    state_handles.emplace_back(
      hardware_interface::StateHandle("joint1", "position", &position_state_));
    state_handles.emplace_back(
      hardware_interface::StateHandle("joint1", "velocity", &velocity_state_));

    return state_handles;
  }

  std::vector<CommandHandle> export_command_handles() override
  {
    std::vector<CommandHandle> command_handles;
    command_handles.emplace_back(
      hardware_interface::CommandHandle("joint1", "velocity", &velocity_command_));

    return command_handles;
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

  return_type write() override
  {
    return return_type::OK;
  }

private:
  double position_state_ = 0.0;
  double velocity_state_ = 0.0;
  double velocity_command_ = 0.0;
  hardware_interface::HardwareInfo actuator_info_;
};

#include "pluginlib/class_list_macros.hpp"  // NOLINT
PLUGINLIB_EXPORT_CLASS(TestActuator, hardware_interface::components::ActuatorInterface)
