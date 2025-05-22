#include <iostream>

#include "core/Application.h"

int main() {
    RendererAPI api = RendererAPI::OpenGL;
    Application app(api);
    app.Run();
}
