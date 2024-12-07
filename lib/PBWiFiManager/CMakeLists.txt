cmake_minimum_required(VERSION 3.5)

idf_component_register(
                       SRCS "PBWiFiManager.cpp" "WiFiManager.cpp"
                       INCLUDE_DIRS "."
                       PRIV_REQUIRES arduino
)

project(WiFiManager)
