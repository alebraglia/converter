#ifndef CONVERTER_HPP_
#define CONVERTER_HPP_

#include "rclcpp/rclcpp.hpp"
#include "mmr_base/msg/marker.hpp"
#include "mmr_base/msg/marker_array.hpp"

class MarkerConverterNode : public rclcpp::Node
{
public:
    MarkerConverterNode();

private:
    void markerCallback(const mmr_base::msg::Marker::SharedPtr msg);

    rclcpp::Subscription<mmr_base::msg::Marker>::SharedPtr marker_sub_;
    rclcpp::Publisher<mmr_base::msg::MarkerArray>::SharedPtr marker_array_pub_;
    mmr_base::msg::MarkerArray marker_array_;
};

#endif 
