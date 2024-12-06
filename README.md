# FDF

FDF is a project developed as part of the 42 curriculum, focusing on implementing a wireframe model representation of a 3D landscape. The project uses **MLX42**, a modern C graphics library.

---

## Features

- **Wireframe Landscape Rendering**: Visualises 3D landscapes as a wireframe model by linking (x, y, z) points with line segments (edges).  
- **Efficient Rendering**: Implements **Bresenham's line-drawing algorithm** for precise and optimised line generation.  
- **Dynamic Input Parsing**: Reads coordinates from `.fdf` files where the x-axis, y-axis, and altitude (z) values define the landscape.  
- **Smooth Window Management**: Handles user interactions seamlessly:
  - Pressing `ESC` or clicking the close button exits the program cleanly.  
  - Responds smoothly to window minimisation.  

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
   git clone https://github.com/mifavoyke/FdF.git
   ```

2. Install dependencies (GLFW and MLX42):
   ```bash
   brew install glfw             # On macOS with Homebrew
   # Or refer to GLFW installation for Linux/Windows
   git submodule update --init --recursive
   ```

3. Build the project inside the project folder:
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

It started out like this -> ![2](https://github.com/user-attachments/assets/ac55e6d8-1278-4407-9e79-eb159b505987) <img width="569" alt="4" src="https://github.com/user-attachments/assets/3e7d97ce-7095-4c7e-8c18-b10e7b0f185d">


So that it ended up like this -> <img width="1013" alt="5" src="https://github.com/user-attachments/assets/c950a58c-c2fd-4a9a-9def-af20ba8bec45">

<img width="974" alt="6" src="https://github.com/user-attachments/assets/069904ba-1510-4a0b-92d9-19d90f5ddb06">

<img width="1032" alt="7" src="https://github.com/user-attachments/assets/70e32041-24e5-4e14-aa80-5a9d7584e730">
