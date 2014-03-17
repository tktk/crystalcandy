#ifndef CRYSTALCANDY_MAIN_ARGS_H
#define CRYSTALCANDY_MAIN_ARGS_H

#include "crystalcandy/main/main.h"
#include "fgpp/boot/boot.h"
#include "fgpp/common/primitives.h"

namespace crystalcandy {
    fg::Bool parseArgs(
        fg::Bool &
        , fg::BootConfig &
        , const Args &
    );

    void helpArgs(
    );
}

#endif  // CRYSTALCANDY_MAIN_ARGS_H
