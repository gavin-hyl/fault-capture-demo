#include <rclcpp/rclcpp.hpp>

#include "fault_report_interfaces/msg/fault_report.hpp"

class FaultPublisher : public rclcpp::Node
{
public:
    FaultPublisher()
        : Node("fault_publisher")
    {
        publisher_ = this->create_publisher<fault_report_interfaces::msg::FaultReport>("/fault_report", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&FaultPublisher::publish, this));
    }

private:
    void publish()
    {
        auto fault_msg = fault_report_interfaces::msg::FaultReport();
        fault_msg.header.stamp = this->get_clock()->now();
        fault_msg.severity_level = static_cast<uint8_t>(fault_report_interfaces::msg::FaultReport::ERROR);
        fault_msg.warning_id = "IAC-FP-20241101-0003";
        fault_msg.description = "Sensor data timeout detected";
        fault_msg.affected_node = "Localization";
        fault_msg.error_code = "ERR-SENSOR-TIMEOUT";
        // Optional fields
        fault_msg.possible_causes = {"Sensor disconnected", "Network latency"};
        fault_msg.recommended_actions = {"Check sensor connection", "Verify network status"};
        publisher_->publish(fault_msg);
        RCLCPP_INFO(this->get_logger(), "Fault report published");
    }

    rclcpp::Publisher<fault_report_interfaces::msg::FaultReport>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<FaultPublisher>());
    rclcpp::shutdown();
    return 0;
}
