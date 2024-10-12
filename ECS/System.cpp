#include "System.hpp"

void System::addEntity(std::shared_ptr<Entity> ptrEntity) {
    vectorEntity.push_back(ptrEntity);
}
