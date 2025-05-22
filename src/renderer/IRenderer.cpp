#include "IRenderer.h"

#include "OpenGLRenderer.h"
#include "VulkanRenderer.h"

IRenderer *IRenderer::Create(RendererAPI api) {
    switch (api) {
        case RendererAPI::OpenGL: return new OpenGLRenderer();
        case RendererAPI::Vulkan: return new VulkanRenderer();
        default: return nullptr;
    }
}

