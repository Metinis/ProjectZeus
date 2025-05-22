#pragma once
#include "Window.h"
#include "../renderer/IRenderer.h"

enum class RendererAPI {
    Vulkan,
    OpenGL
};

class Application {
public:
    Application(RendererAPI api);
    ~Application();
    void Run(); //Entry point (main.coo) calls this
private:
    void Init();
    void Shutdown();

    void ProcessEvents();
    void Update(float deltaTime);
    void Render();

    RendererAPI m_API;
    IRenderer* m_Renderer = nullptr;
    Window* m_Window = nullptr;
    bool m_Running = false;
};
