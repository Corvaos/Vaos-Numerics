# Vaos Numerics v1

## Overview
Vaos Numerics is a basic C++ numbers framework designed to optimize various functions specifically for my own projects. 
This includes the (Vaos-Renderer)[https://github.com/Corvaos/Vaos-Renderer], my (Rutherford Scattering Simulation)[https://github.com/Corvaos/Rutherford], and other projects.  

## Capabilities
Vaos Numerics is capable of:
### Data Types
* Vector2/Vector3
* Matrix (Column Major)
* Transforms
### Statistics
* Random Number Generator
### Physics
* Units

## Limitations
Vaos Numerics (v1) is currently limited by the fact that it is independent: it cannot automate things on its own and purely acts as a handler for various data types and tools.  

## Technologies
* C++ 20
* CMake

## Future Developments
Planned Features include:
* Data Types:
* * Quaternions
* Calculus:
* * Derivatives
* * Integrals

## Design Goals
Vaos Numerics is designed with the primary purpose of making development of my future projects more streamlined, so I can focus on the physics behind a simulation rather than the memory management of objects and the misuse of them. Thus, the following design goals were pursued:
* Static Properties. Once an object has been instantiated, only the value can change, not its nature.
* Abstraction. Management of objects should be simple and intuitive.
* Integration. This library should be able to be plugged into a project and be able to calculate various values and variables efficiently.