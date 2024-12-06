# [PROJECT_NAME]

[PROJECT_NAME] is a project developed as part of the 42 curriculum, focusing on [briefly describe the goal of the project, e.g., "rendering 2D/3D graphics" or "implementing a wireframe viewer"]. The project uses **MLX42**, a modern C graphics library built on top of GLFW, ensuring seamless and efficient rendering.

---

## Features

- [List key features of your project, e.g., "2D wireframe rendering" or "real-time animations."]
- Utilises **Bresenham's line-drawing algorithm** for optimised rendering.
- Supports custom colour parsing in BGRA format.
- [Add any other unique functionality your project provides.]

---

## Requirements

To run the project, ensure you have the following installed:

- **C Compiler**: GCC or Clang.
- **CMake**: Version 3.0 or newer.
- **GLFW**: Required for **MLX42**.

---

## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/[REPOSITORY_NAME].git
   cd [REPOSITORY_NAME]
   ```

2. Install dependencies (GLFW and MLX42):
   ```bash
   brew install glfw             # On macOS with Homebrew
   # Or refer to GLFW installation for Linux/Windows
   git submodule update --init --recursive
   ```

3. Build the project:
   ```bash
   cmake .
   make
   ```

4. Run the program:
   ```bash
   ./[PROJECT_BINARY_NAME]
   ```

---

## Dependencies

This project relies on:

- **MLX42**: A lightweight graphics library by Codam Coding College. [MLX42 GitHub Repository](https://github.com/codam-coding-college/MLX42)
- **GLFW**: A cross-platform library for OpenGL, OpenGL ES, and Vulkan development. [GLFW Website](https://www.glfw.org/)

Ensure these dependencies are installed and properly configured.

---

## Usage

1. [Describe how to use the program, e.g., passing files as arguments or navigating the interface.]
2. Example command:
   ```bash
   ./[PROJECT_BINARY_NAME] example_file.fdf
   ```

---

## Screenshots/Demo

[Add screenshots or a GIF/video demonstrating your project in action.]
