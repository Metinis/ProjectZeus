#include "ImGUILayer.h"

#include "ImGuiLayerOpenGL.h"
#include "ImGUILayerVulkan.h"
#include "../renderer/RendererAPI.h"
ImGUILayer *ImGUILayer::Create(RendererAPI api) {
    switch (api) {
        case RendererAPI::OpenGL: return new ImGUILayerOpenGL();
        case RendererAPI::Vulkan: return new ImGUILayerVulkan();
        default: return nullptr;
    }
}
