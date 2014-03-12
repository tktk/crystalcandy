#include "crystalcandy/main/main.h"
#include "fgpp/common/primitives.h"

#include <cstring>

namespace {
    struct Strlen
    {
        fg::Size operator()(
            const fg::StringChar *  _FROM
        ) const
        {
            return std::strlen( _FROM );
        }
    };
}

fg::Int main(
    fg::Int             _argc
    , fg::StringChar ** _argv
)
{
    return crystalcandy::main< Strlen >(
        _argc
        , _argv
    );
}
