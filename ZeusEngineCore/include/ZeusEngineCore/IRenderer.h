#pragma once

enum class RendererAPI;

class IRenderer {
public:
    virtual ~IRenderer() = default;

    virtual void Init() = 0;
    virtual void Cleanup() = 0;

    virtual void BeginFrame() = 0;
    virtual void EndFrame() = 0;

    virtual void DrawMesh(/*Mesh data*/) = 0;

    static IRenderer* Create(RendererAPI api);
};
