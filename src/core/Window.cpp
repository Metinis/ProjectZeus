#include "Window.h"

#include <glad/glad.h>

Window::Window(int width, int height, const std::string& title, bool useVulkan)
    : m_Width(width), m_Height(height), m_Title(title), m_UseVulkan(useVulkan)
{
    Init();
}
Window::~Window() {
    if(m_Window) {
        glfwDestroyWindow(m_Window);
        glfwTerminate();
    }
}

void Window::Init() {
    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    if (m_UseVulkan) {
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    } else {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
#ifdef __APPLE__
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Required on macOS
#else
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
#endif
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    }

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), nullptr, nullptr);
    if (!m_Window)
        throw std::runtime_error("Failed to create window");

    if (!m_UseVulkan) {
        glfwMakeContextCurrent(m_Window);
        //glfwSwapInterval(1); // Enable VSync
    }

    m_LastTime = static_cast<float>(glfwGetTime());
}
void Window::PollEvents() {
    glfwPollEvents();
    CalculateDeltaTime();
}
void Window::CalculateDeltaTime() {
    float currentTime = static_cast<float>(glfwGetTime());
    m_DeltaTime = currentTime - m_LastTime;
    m_LastTime = currentTime;
}
float Window::GetDeltaTime() const {
    return m_DeltaTime;
}
GLFWwindow* Window::GetNativeWindow() const {
    return m_Window;
}
bool Window::ShouldClose() {
    return glfwWindowShouldClose(m_Window);
}
void Window::SwapBuffers() {
    glfwSwapBuffers(m_Window);
}




