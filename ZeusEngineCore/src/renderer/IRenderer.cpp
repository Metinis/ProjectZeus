#include "ZeusEngineCore/IRenderer.h"
#include "ZeusEngineCore/RendererAPI.h"
#include "ZeusEngineCore/OpenGLRenderer.h"
#include "ZeusEngineCore/VulkanRenderer.h"

IRenderer *IRenderer::Create(RendererAPI api) {
    switch (api) {
        case RendererAPI::OpenGL: return new OpenGLRenderer();
        case RendererAPI::Vulkan: return new VulkanRenderer();
        default: return nullptr;
    }
}

