## Welcome to Zeus!

This is a WIP game engine project in OpenGL (Vulkan coming soon) and C++ using EnTT with ECS-based scripting.
![Screenshot](/Screenshot2.png)

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
- Asset Manager
- GPU Resource Manager
- Scene and Asset Serialization
- User-Defined Runtime Components
- Scripting
- Gizmos


## Features to add

- Vulkan Support
- Compute Ray Tracing
- Physics using Nvidia PhysX
- And More..

## Building
    git clone --recurse-submodules https://github.com/Metinis/ProjectZeus.git
    cd ProjectZeus
    cmake -S . -B build-release -DCMAKE_BUILD_TYPE=Release
    cmake --build build-release -j6
