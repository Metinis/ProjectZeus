#pragma once
#include "IRenderer.h"

class OpenGLRenderer : public IRenderer{
public:
    void Init() override;

    void Cleanup() override;

    void BeginFrame() override;

    void EndFrame() override;

    void DrawMesh() override;
};
