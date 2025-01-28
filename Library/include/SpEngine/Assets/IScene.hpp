#ifndef SCENE_HPP
#define SCENE_HPP

class Scene {
public:
    virtual void display() const = 0; // Add const
    virtual ~Scene() = default;
};

#endif // SCENE_HPP
