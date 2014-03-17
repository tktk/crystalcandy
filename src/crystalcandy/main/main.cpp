#include "crystalcandy/main/main.h"
#include "crystalcandy/main/args.h"
#include "fgpp/boot/config.h"
#include "fgpp/boot/boot.h"
#include "fgpp/common/unique.h"

namespace crystalcandy {
    fg::Int main(
        const Args &    _ARGS
    )
    {
        auto    configUnique = fg::unique( fg::newBootConfig() );
        if( configUnique.get() == nullptr ) {
            return 1;
        }
        auto &  config = *configUnique;

        auto    help = false;
        if( parseArgs(
            help
            , config
            , _ARGS
        ) == false ) {
            return 1;
        }

        if( help ) {
            helpArgs();

            return 0;
        }

        if( fg::boot(
            config
        ) == false ) {
            return 1;
        }

        return 0;
    }
}
