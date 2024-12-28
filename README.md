# FDF

## It started out like this ->

<img height="400" alt="4" src="https://github.com/user-attachments/assets/3c13f105-2575-4e09-9da5-ab06cca4a850">  <img height="400" alt="4" src="https://github.com/user-attachments/assets/fb553dfb-3040-4590-8d8d-86e26158b538">

### So that it ended up like this ->

<img height="400" alt="5" src="https://github.com/user-attachments/assets/0a5a5424-36e5-4b78-aeb8-3eaceffecfd3">  <img height="400" alt="6" src="https://github.com/user-attachments/assets/cbc31b83-561d-49a0-903d-e2a531ffebaf">  <img height="500" alt="7" src="https://github.com/user-attachments/assets/7b214a91-ff92-4ac8-a2e6-f184748454c3">

---

FDF is a project developed as part of the 42 curriculum, focusing on implementing a wireframe model representation of a 3D landscape. The project uses the graohic library **MLX42**.

---

## Features

- **Wireframe Landscape Rendering**: Visualises 3D landscapes as a wireframe model by linking (x, y, z) points with line segments.  
- **Efficient Rendering**: Implements **Bresenham's line-drawing algorithm** for precise and optimised line generation.  
- **Dynamic Input Parsing**: Reads coordinates from `.fdf` files where the x-axis, y-axis, and altitude (z) values define the landscape.

  Example of the map:
    ```bash
    $>cat 42.fdf
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
    0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
    0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
    0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
    0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
    0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
    0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
    0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
  Here, we encounter the first "10" at the coordinate (3, 3, 10) where x - the third column; y - the third row; z - the number itself meaning altitude.

- **Smooth Window Management**:
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

2. Build the project inside the project folder:
   ```bash
   make
   ```

3. Run the program:
   ```bash
   ./fdf maps/[MAP OF YOUR CHOICE].fdf
   ```
   For instance:
   ```bash
   ./fdf maps/42.fdf
   ```
---

## Dependencies

This project relies on:
- **MLX42**: A lightweight graphics library by Codam Coding College. [MLX42 GitHub Repository](https://github.com/codam-coding-college/MLX42)

The programme will install the MLX42 library for you but you have to make sure you have GLFW, CMake and GCC yourself.
