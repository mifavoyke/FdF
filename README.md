# FDF

FDF is a project developed as part of the 42 curriculum, focusing on implementing a wireframe model representation of a 3D landscape. The project uses **MLX42**, a modern C graphics library.

---

## Features

- **Wireframe Landscape Rendering**: Visualises 3D landscapes as a wireframe model by linking (x, y, z) points with line segments (edges).  
- **Isometric Projection**: Displays the model in an isometric view to provide a clear perspective of the 3D scene.  
- **Efficient Rendering**: Implements **Bresenham's line-drawing algorithm** for precise and optimised line generation.  
- **Dynamic Input Parsing**: Reads coordinates from `.fdf` files where the x-axis, y-axis, and altitude (z) values define the landscape.  
- **Custom Colour Support**: Supports BGRA colour format for detailed visualisation.  
- **Smooth Window Management**: Handles user interactions seamlessly:
  - Pressing `ESC` or clicking the close button exits the program cleanly.  
  - Responds smoothly to window minimisation or focus changes.  
- **Keyboard and Mouse Events**: Built-in functionality to handle input for extended interactivity (future expansion).  
- **Built with MLX42**: Uses MLX42 for creating windows, drawing images, and handling events.  

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
   make
   ```

4. Run the program:
   ```bash
   ./fdf maps/[MAP OF YOUR CHOICE].fdf
   ```

---

## Dependencies

This project relies on:

- **MLX42**: A lightweight graphics library by Codam Coding College. [MLX42 GitHub Repository](https://github.com/codam-coding-college/MLX42)
- **GLFW**: A cross-platform library for OpenGL, OpenGL ES, and Vulkan development. [GLFW Website](https://www.glfw.org/)

Ensure these dependencies are installed and properly configured.

---

## Screenshots/Demo

[Add screenshots or a GIF/video demonstrating your project in action.]
