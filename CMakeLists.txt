cmake_minimum_required(VERSION 3.26)

option(IS_RELEASE "RELEASE" ON)
if(IS_RELEASE)
    set(CMAKE_BUILD_TYPE Release)
endif(IS_RELEASE)

project(tinystory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(tinystory main.cpp
        GameMenu.cpp
        Engine.cpp
        EntityManager.cpp
        IDManager.cpp
        ECS/System.cpp
        ECS/Entity.cpp
        Components/BoundsComponent.cpp
        Components/SpriteComponent.cpp
        Components/TransformComponent.cpp
        Components/CollisionComponent.cpp
        Components/DescriptionComponent.cpp
        Systems/CollisionSystem.cpp
        Systems/InputSystem.cpp
        Systems/RenderSystem.cpp
        Systems/InventorySystem.cpp
        Systems/MoveSystem.cpp
        Systems/InteractionSystem.cpp
        Systems/ScriptSystem.cpp
        Entities/PlayerEntity.cpp
        Entities/InventoryEntity.cpp
        Entities/ObjectEntity.cpp
        Entities/InteractiveObjectEntity.cpp
        Entities/LocationObjectEntity.cpp
        Entities/StaticObjectEntity.cpp
        Entities/EmptyObjectEntity.cpp
)
        

set(SFML_STATIC_LIBRARIES TRUE)

if(IS_RELEASE)
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static -mwindows")
endif(IS_RELEASE)

set(SFML_DIR C:/dev/cpp/SFML-2.6.2/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(${SFML_DIR}/include)
target_link_libraries(tinystory sfml-system sfml-window sfml-graphics sfml-audio)

file(COPY Assets DESTINATION .)

unset(IS_RELEASE CACHE)
