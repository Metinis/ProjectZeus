#pragma once
#include <imgui_impl_glfw.h>

enum class RendererAPI;

class ImGUILayer {
public:
    virtual ~ImGUILayer() = default;
    virtual void Init(GLFWwindow* window) = 0;
    virtual void Shutdown() = 0;
    virtual void Render() = 0;

    static ImGUILayer* Create(RendererAPI api);
};
