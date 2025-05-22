#include "Application.h"
Application::Application(RendererAPI api) : m_API(api) {
    Init();
}
Application::~Application() {
    Shutdown();
}
void Application::Init() {
    //initialize the renderer and imguilayer and window
    bool useVulkan = (m_API == RendererAPI::Vulkan);
    m_Window = new Window(1280, 720, "Zeus Engine", useVulkan);

    m_Renderer = IRenderer::Create(m_API);
    m_Renderer->Init();

    //init imgui

    m_Running = true;
}
void Application::Shutdown() {
    //cleanup member variables and close window
}
void Application::Run() {
    while(m_Running && !m_Window->ShouldClose()) {
        //process events, update and then render
        m_Window->PollEvents();

        float dt = m_Window->GetDeltaTime();
        Update(dt);
        Render();

        if(m_API == RendererAPI::OpenGL) {
            m_Window->SwapBuffers(); //swap buffers function already checks if opengl
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
    //use m_Renderer to render and imguilayer to render frame
}






