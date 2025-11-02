## Welcome to Zeus!

This is a WIP rendering engine project in OpenGL (Vulkan coming soon) and C++ that may eventually become a game engine.

![Screenshot](/Screenshot1.png)

## Features

- ENTT ECS integration
- Lighting
- An editor
- Component manipulation
- API independent rendering
- Physics-based rendering
- Image-based lighting
- Event System
- Model Loading


## Features to add


- Vulkan Support
- Compute Ray Tracing
- User-Defined Components
- Scripting
- Physics Bodies
- And More..

## Building
    git clone --recurse-submodules https://github.com/Metinis/ProjectZeus.git
    cd ProjectZeus
    cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
    cmake --build build-release -j6
