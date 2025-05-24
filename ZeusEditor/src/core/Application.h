#pragma once
#include "Window.h"
#include "../imgui/ImGUILayer.h"
#include <ZeusEngineCore/IRenderer.h>
#include <ZeusEngineCore/RendererAPI.h>

class Application {
public:
    Application(RendererAPI api);
    ~Application();
    void Run(); //Entry point (main.cpp) calls this
private:
    void Init();
    void Shutdown();

    void ProcessEvents();
    void Update(float deltaTime);
    void Render();

    RendererAPI m_API;
    IRenderer* m_Renderer = nullptr;
    ImGUILayer* m_ImGuiLayer = nullptr;
    Window* m_Window = nullptr;
    bool m_Running = false;
};
