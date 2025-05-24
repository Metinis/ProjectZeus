
#pragma once
#include "IRenderer.h"

class VulkanRenderer : public IRenderer {
public:
    void Init() override;

    void Cleanup() override;

    void BeginFrame() override;

    void EndFrame() override;

    void DrawMesh() override;
};
