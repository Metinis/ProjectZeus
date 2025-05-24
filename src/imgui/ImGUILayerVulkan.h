#pragma once
#include "ImGUILayer.h"
#include "GLFW/glfw3.h"

class ImGUILayerVulkan : public ImGUILayer{
    void Init(GLFWwindow* window) override;
    void Shutdown() override;
    void Render() override;
};
