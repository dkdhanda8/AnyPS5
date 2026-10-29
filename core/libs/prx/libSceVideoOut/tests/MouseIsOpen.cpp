#include "prx/libSceVideoOut/libSceVideoOut.hpp"
#include "prx/libSceMouse/include/Api.hpp"
#include "prx/libSceMouse/include/mouse_structs.h"

#include <cstdlib>


static void Require(bool value) { if (!value) std::abort(); }

int main() {
    Require(sceMouseInit() == MOUSE_OK);
    Require(!MouseIsOpen());
    Require(sceMouseOpen(1, 0, 0, nullptr) == MOUSE_HANDLE);
    Require(MouseIsOpen());
    Require(sceMouseClose(MOUSE_HANDLE) == MOUSE_OK);
    Require(!MouseIsOpen());
    return 0;
}
