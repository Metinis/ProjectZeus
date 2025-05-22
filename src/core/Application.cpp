#include "Application.h"
Application::Application(RendererAPI api) : m_API(api) {
    Init();
}
Application::~Application() {
    Shutdown();
}
void Application::Init() {
    //initialize the renderer and imguilayer
    m_Renderer = IRenderer::Create(m_API);
    m_Renderer->Init();

    //init imgui

    m_Running = true;
}
void Application::Shutdown() {
    //cleanup member variables and close window
}
void Application::Run() {
    while(m_Running) {
        //process events, update and then render
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






