#pragma once
#include <string>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int width, int height, const std::string& title, bool useVulkan);
    ~Window();
    void PollEvents();
    float GetDeltaTime() const;
    bool ShouldClose();
    void SwapBuffers();
    GLFWwindow* GetNativeWindow() const;

private:
    void Init();
    void CalculateDeltaTime();

    GLFWwindow* m_Window = nullptr;
    int m_Width = 1280;
    int m_Height = 720;
    float m_LastTime;
    float m_DeltaTime;
    std::string m_Title;
    bool m_UseVulkan;
};
