#ifndef CRYSTALCANDY_MAIN_MAIN_H
#define CRYSTALCANDY_MAIN_MAIN_H

#include "fgpp/common/string.h"
#include "fgpp/common/primitives.h"
#include "fgpp/strconv/toutf32.h"

#include <vector>

namespace crystalcandy {
    fg::Int main(
        const std::vector< fg::Utf32 > &
    );

    template<
        typename STRLEN
        , typename CHAR_T
    >
    fg::Bool toUtf32(
        fg::Utf32 &         _to
        , const CHAR_T *    _FROM
        , fg::BUtf32 &      _toBuffer
    )
    {
        const auto  LENGTH = STRLEN()( _FROM );

        _toBuffer.resize( LENGTH * fg::MAX_UTF32_CHAR_COUNT );

        _to.assign( _toBuffer );

        const fg::String    FROM(
            const_cast< CHAR_T * >( _FROM )
            , LENGTH
        );

        fg::Size    outputLength;
        fg::Size    inputLength;

        if( fg::toUtf32(
            _to
            , FROM
            , outputLength
            , inputLength
        ) == false ) {
            return false;
        }

        _toBuffer.resize( outputLength );

        return true;
    }

    template<
        typename STRLEN
        , typename CHAR_T
    >
    fg::Int main(
        fg::Int     _argc
        , CHAR_T ** _argv
    )
    {
        std::vector< fg::Utf32 >    args( _argc );
        std::vector< fg::BUtf32 >   argBuffers( _argc );

        auto    argsIt = args.begin();
        auto    argBuffersIt = argBuffers.begin();
        for( decltype( _argc ) i = 0 ; i < _argc ; ++i, ++argsIt, ++argBuffersIt ) {
            auto &      to = *argsIt;
            auto &      toBuffer = *argBuffersIt;
            const auto  FROM = _argv[ i ];

            if( toUtf32< STRLEN >(
                to
                , FROM
                , toBuffer
            ) == false ) {
                return 1;
            }
        }

        return main(
            args
        );
    }
}

#endif  // CRYSTALCANDY_MAIN_MAIN_H
