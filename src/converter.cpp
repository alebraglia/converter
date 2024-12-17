#include "rclcpp/rclcpp.hpp"
#include "mmr_base/msg/marker.hpp"
#include "mmr_base/msg/marker_array.hpp"
#include "converter.hpp"

MarkerConverterNode::MarkerConverterNode() : Node("marker_converter_node")
{
    // Subscriber to Marker messages
    marker_sub_ = this->create_subscription<mmr_base::msg::Marker>(
        "/slam/cones_positions",
        10,
        std::bind(&MarkerConverterNode::markerCallback, this, std::placeholders::_1));

    // Publisher for MarkerArray messages
    marker_array_pub_ = this->create_publisher<mmr_base::msg::MarkerArray>("/output_marker_array", 10);
}

void MarkerConverterNode::markerCallback(const mmr_base::msg::Marker::SharedPtr msg)
{
    RCLCPP_INFO(this->get_logger(), "Received a marker with ID: %d", msg->id);

    // Clear the MarkerArray for new markers
    marker_array_.markers.clear();

    // Create a new marker for each point in the received marker
    for (size_t i = 0; i < msg->points.size(); ++i)
    {
        mmr_base::msg::Marker point_marker;
        point_marker.header.frame_id = "track";
        point_marker.header.stamp = this->now();
        point_marker.ns = "";
        point_marker.id = 0;
        point_marker.pose.position = msg->points[i];
        point_marker.pose.orientation.w = 1.0;
        point_marker.pose.orientation.x = 0.0;
        point_marker.pose.orientation.y = 0.0;
        point_marker.pose.orientation.z = 0.0;
        point_marker.scale.x = 0.1;
        point_marker.scale.y = 0.1;
        point_marker.scale.z = 0.1;
        point_marker.color.a = 1.0;

        // Add the point marker to the MarkerArray
        marker_array_.markers.push_back(point_marker);
    }

    // Publish the updated MarkerArray
    marker_array_pub_->publish(marker_array_);
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MarkerConverterNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
