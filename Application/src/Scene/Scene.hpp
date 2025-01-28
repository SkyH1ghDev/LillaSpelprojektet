#include <iostream>
#include <unordered_map>
#include <functional>
#include <memory>
#include <stdexcept>

// Base Scene class (for polymorphism)
class Scene {
public:
    virtual void display() = 0; 
    virtual ~Scene() = default;
};