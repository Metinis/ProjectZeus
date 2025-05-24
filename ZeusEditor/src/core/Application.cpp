#include "Application.h"
#include "../imgui/ImGUILayer.h"

Application::Application(RendererAPI api) : m_API(api) {
    Init();
}
Application::~Application() {
    Shutdown();
}
void Application::Init() {
    //initialize the renderer and imguilayer and window
    const bool useVulkan = (m_API == RendererAPI::Vulkan);
    m_Window = new Window(1280, 720, "Zeus Engine", useVulkan);

    m_Renderer = IRenderer::Create(m_API);
    m_Renderer->Init();

    m_ImGuiLayer = ImGUILayer::Create(m_API);
    m_ImGuiLayer->Init(m_Window->GetNativeWindow());

    m_Running = true;
}
void Application::Shutdown() {
    if(m_ImGuiLayer) {
        m_ImGuiLayer->Shutdown();
        delete m_ImGuiLayer;
    }

    //can delete nullptrs
    delete m_Renderer;

    delete m_Window;
}
void Application::Run() {
    while(m_Running && !m_Window->ShouldClose()) {
        m_Window->PollEvents();

        float dt = m_Window->GetDeltaTime();
        Update(dt);
        Render();

        if(m_API == RendererAPI::OpenGL) {
            m_Window->SwapBuffers();
        }
    }
}
void Application::ProcessEvents() {
    //handle input/resize, etc
}
void Application::Update(float deltaTime) {
    //Update Scene here
}
void Application::Render() {
    m_ImGuiLayer->Render();
}






