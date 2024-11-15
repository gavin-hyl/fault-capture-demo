#include <rclcpp/rclcpp.hpp>

#include "fault_report_interfaces/msg/fault_report.hpp"

class FaultPublisher : public rclcpp::Node
{
public:
    FaultPublisher()
        : Node("fault_publisher")
    {
        publisher_ = this->create_publisher<fault_report_interfaces::msg::FaultReport>("fault_report", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&FaultPublisher::publish, this));
    }

private:
    void publish()
    {
        auto message = fault_report_interfaces::msg::FaultReport();
        publisher_->publish(message);
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
