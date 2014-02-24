#include "crystalcandy/main/main.h"
#include "fgpp/def/common/primitives.h"

namespace {
    struct ArgGenerator
    {
        fg::Bool operator()(
            fg::Utf32 &                 _to
            , const fg::StringChar *    _FROM
        ) const
        {
            //TODO
            return false;
        }
    };
}

fg::Int main(
    fg::Int             _argc
    , fg::StringChar ** _argv
)
{
    return crystalcandy::main< ArgGenerator >(
        _argc
        , _argv
    );
}
