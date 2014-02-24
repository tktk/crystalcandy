#ifndef CRYSTALCANDY_MAIN_MAIN_H
#define CRYSTALCANDY_MAIN_MAIN_H

#include "fgpp/def/common/primitives.h"

#include <vector>

namespace crystalcandy {
    fg::Int main(
        const std::vector< fg::Utf32View > &
    );

    template<
        typename ARG_GENERATOR
        , typename CHAR_T
    >
    fg::Int main(
        fg::Int     _argc
        , CHAR_T ** _argv
    )
    {
        std::vector< fg::Utf32View >    args( _argc );
        std::vector< fg::Utf32 >        argBuffers( _argc );

        auto    argsIt = args.begin();
        auto    argBuffersIt = argBuffers.begin();
        for( decltype( _argc ) i = 0 ; i < _argc ; ++i, ++argsIt, ++argBuffersIt ) {
            auto &  to = *argsIt;
            auto &  toBuffer = *argBuffersIt;
            auto    from = _argv[ i ];

            if( ARG_GENERATOR()(
                toBuffer
                , from
            ) == false ) {
                return 1;
            }

            to.assign( toBuffer );
        }

        return main(
            args
        );
    }
}

#endif  // CRYSTALCANDY_MAIN_MAIN_H
