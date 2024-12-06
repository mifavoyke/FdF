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
   # On macOS with Homebrew
   brew install glfw
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

Ensure these dependencies are installed and properly configured.

---

## Screenshots/Demo

It started out like this ->

![2](https://github.com/user-attachments/assets/72229fa8-f2cb-45a0-bed5-01b5cda08b34)

<img width="465" alt="4" src="https://github.com/user-attachments/assets/fb553dfb-3040-4590-8d8d-86e26158b538">

So that it ended up like this ->

<img width="772" alt="5" src="https://github.com/user-attachments/assets/0a5a5424-36e5-4b78-aeb8-3eaceffecfd3">

<img width="683" alt="6" src="https://github.com/user-attachments/assets/cbc31b83-561d-49a0-903d-e2a531ffebaf">

<img width="728" alt="7" src="https://github.com/user-attachments/assets/7b214a91-ff92-4ac8-a2e6-f184748454c3">
