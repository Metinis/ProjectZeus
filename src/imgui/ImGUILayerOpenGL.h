#pragma once
#include "ImGUILayer.h"
#include "GLFW/glfw3.h"

class ImGUILayerOpenGL : public ImGUILayer{
public:
    void Init(GLFWwindow* window) override;
    void Shutdown() override;
    void Render() override;
};
