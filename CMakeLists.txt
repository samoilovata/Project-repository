cmake_minimum_required(VERSION 3.26)
project(project)

set(CMAKE_CXX_STANDARD 23)

add_executable(project main.cpp
        ECS/System.cpp
        ECS/Entity.cpp
        Components/BoundsComponent.cpp
        Components/SpriteComponent.cpp
        Components/InputComponent.cpp
        Components/TransformComponent.cpp
        Systems/CollisionSystem.cpp
        Systems/InputSystem.cpp
        Systems/RenderSystem.cpp
        Engine.cpp
        SpawnEntity.cpp
)
        

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/Program Files/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/Program Files/SFML/include)
target_link_libraries(project sfml-system sfml-window sfml-graphics sfml-audio)
