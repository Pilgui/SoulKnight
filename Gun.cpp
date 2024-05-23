//
// Created by nicki on 23.05.2024.
//

#include "Gun.h"

Gun::Gun() {
    if(!texture.loadFromFile("textures\\red.png")){
        return;
    }
}
