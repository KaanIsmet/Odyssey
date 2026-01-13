# Odyssey: Pixel Gladiator Arena

A 2D overhead gladiator combat game inspired by epic tales of arena combat, built with C++, OpenGL, and GLFW.

> **Current Status**: Sprint 1 - Rendering & Input Foundation

## Overview

This project is being built system-by-system following an agile sprint methodology. The goal is to create a visceral, pixel-art gladiator combat experience with deep AI systems and satisfying melee combat mechanics.

## Sprint 1: Rendering & Input System

### Goal
Render and control a pixel-art gladiator sprite in a basic arena environment.

### Completed Features
- [ ] OpenGL context and window setup
- [ ] Shader compilation and management system
- [ ] Texture loading with pixel-perfect filtering
- [ ] Sprite rendering with transformations (position, rotation, scale)
- [ ] 2D camera system with pan and zoom
- [ ] Input manager with key state tracking
- [ ] Action mapping system (decouple input from game logic)
- [ ] Player movement with WASD/arrow keys
- [ ] Test arena scene with controllable gladiator

### What You Can Do Right Now
- Launch the game and see a pixelated gladiator in a simple arena
- Move the gladiator smoothly in 8 directions
- Camera follows the player character
- Clean, sharp pixel art rendering (no blur)

## Technical Stack

### Core Libraries
- **GLFW** - Window management and input handling
- **OpenGL 3.3+** - Graphics rendering (core profile)
- **GLM** - Mathematics library for vectors and matrices
- **stb_image.h** - Image loading (single-header library)

### Build Requirements
- C++17 or later
- CMake 3.15+
- OpenGL 3.3+ compatible GPU
- GLFW3 development libraries

## Building the Project

### Linux
```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install libglfw3-dev libglm-dev

# Build
mkdir build && cd build
cmake ..
make

# Run
./odyssey
```

### macOS
```bash
# Install dependencies
brew install glfw glm

# Build
mkdir build && cd build
cmake ..
make

# Run
./spartacus
```

### Windows (Visual Studio)
```bash
# Install dependencies via vcpkg
vcpkg install glfw3 glm

# Build
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=[vcpkg root]/scripts/buildsystems/vcpkg.cmake
cmake --build .

# Run
.\Debug\odyssey.exe
```

## Project Structure

```
odyssey/
├── src/
│   ├── rendering/
│   │   ├── Texture.h/cpp       # Texture loading and management
│   │   ├── Shader.h/cpp        # Shader compilation and uniforms
│   │   ├── SpriteRenderer.h/cpp # Quad rendering with sprites
│   │   └── Camera.h/cpp        # 2D camera with projection
│   ├── input/
│   │   └── InputManager.h/cpp  # Keyboard input and action mapping
│   └── main.cpp                # Game loop and initialization
├── assets/
│   ├── shaders/
│   │   ├── sprite.vert         # Vertex shader
│   │   └── sprite.frag         # Fragment shader
│   └── sprites/
│       ├── gladiator.png       # Player sprite
│       └── arena_floor.png     # Arena tileset
├── CMakeLists.txt
└── README.md
```

## Controls (Sprint 1)

| Key | Action |
|-----|--------|
| W / ↑ | Move Up |
| S / ↓ | Move Down |
| A / ← | Move Left |
| D / → | Move Right |
| ESC | Quit |

## Rendering Architecture

### Pixel-Perfect Rendering
- All textures use `GL_NEAREST` filtering for sharp pixels
- Fixed internal resolution approach (planned for Sprint 2)
- Pixel grid alignment to prevent sub-pixel jittering

### Coordinate System
- Y-axis points up
- Origin at center of screen
- World units: 16 pixels = 1 game unit (configurable)

### Shader Pipeline
```
Vertex Shader:
- Transform: Model → View → Projection
- Pass UVs and color to fragment shader

Fragment Shader:
- Sample texture with GL_NEAREST
- Apply color tint
- Output to framebuffer
```

## Upcoming Sprints

### Sprint 2: Physics & Collision (Week 3)
- AABB and circle collision detection
- Movement physics with velocity/friction
- Arena boundaries
- Attack range detection system

### Sprint 3: Basic Combat (Weeks 4-5)
- Weapon system (sword, spear, shield)
- Attack execution with hitboxes
- Health and damage
- Blocking and parrying

### Sprint 4: Animation System (Weeks 5-6)
- Sprite sheet parsing
- Animation state machine
- Combat animations
- Movement animations

### Sprint 5: Enemy AI (Weeks 6-7)
- Finite state machine
- Pathfinding (A*)
- Combat behaviors
- Group coordination

_See [ROADMAP.md](ROADMAP.md) for full epic breakdown_

## Design Philosophy

### Systems-First Approach
Building complete, isolated systems rather than building the whole game at once. Each system has:
- Clear interface/API
- Minimal coupling to other systems
- Comprehensive functionality within its domain

### Performance Targets
- 60 FPS on mid-range hardware
- Support 20+ active enemies simultaneously
- Sub-16ms frame time budget

### Code Quality
- Modern C++17 practices
- RAII for resource management
- Clear separation of concerns
- Data-driven where possible (configs for weapons, enemies, etc.)

## Contributing

This is a personal learning project, but feedback and suggestions are welcome! Feel free to:
- Open issues for bugs or ideas
- Submit PRs for improvements
- Share your thoughts on the architecture

## License

MIT License - See [LICENSE](LICENSE) for details

## Acknowledgments

- Inspired by the Spartacus TV series
- Built as a learning project to improve backend development skills through game systems thinking
- Uses discrete math and algorithms (graph theory, pathfinding, state machines) that translate to backend work

---

**Current Sprint**: 1 of 12  
**Status**: In Progress  
**Next Milestone**: Controllable gladiator with pixel-perfect rendering
