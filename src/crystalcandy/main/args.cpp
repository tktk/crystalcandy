#include "crystalcandy/main/args.h"
#include "fgpp/common/string.h"

#include <functional>
#include <map>
#include <algorithm>
#include <cstring>
#include <cstdio>

namespace {
    template<
        typename PROC_T
        , typename T
    >
    struct Option
    {
    private:
        T & value;

    public:
        Option(
            T & _value
        )
            : value( _value )
        {
        }

        fg::Bool operator()(
            crystalcandy::Args::const_iterator &            _it
            , const crystalcandy::Args::const_iterator &    _END
        )
        {
            return PROC_T()(
                _it
                , _END
                , this->value
            );
        }
    };

    struct Help
    {
        fg::Bool operator()(
            crystalcandy::Args::const_iterator &
            , const crystalcandy::Args::const_iterator &
            , fg::Bool &                                    _help
        ) const
        {
            _help = true;

            return true;
        }
    };
}

namespace crystalcandy {
    fg::Bool parseArgs(
        fg::Bool &          _help
        , fg::BootConfig &  _config
        , const Args &      _ARGS
    )
    {
        typedef std::function<
            fg::Bool(
                Args::const_iterator &
                , const Args::const_iterator &
            )
        > OptionProc;

        typedef std::map< fg::BUtf32, OptionProc > OptionProcMap;

        const OptionProcMap PROC_MAP = {
#define OPTION( _PROC, _VALUE ) Option< _PROC, decltype( _VALUE ) >( _VALUE )

            { U"--help", OPTION( Help, _help ) },
            //TODO

#undef  OPTION
        };

        const auto  PROC_MAP_BEGIN = PROC_MAP.begin();
        const auto  PROC_MAP_END = PROC_MAP.end();

        const auto  ARGS_END = _ARGS.end();
        for( auto argsIt = _ARGS.begin() + 1 ; argsIt != ARGS_END ; ++argsIt ) {
            const auto &    ARG = *argsIt;

            const auto  PROC_MAP_IT = std::find_if(
                PROC_MAP_BEGIN
                , PROC_MAP_END
                , [
                    &ARG
                ]
                (
                    const OptionProcMap::value_type &   _PAIR
                )
                {
                    const auto &    KEY = _PAIR.first;

                    const auto  LENGTH = ARG.getLength();
                    if( LENGTH != KEY.length() ) {
                        return false;
                    }

                    const auto  SIZE = LENGTH * sizeof( ARG[ 0 ] );

                    return std::memcmp(
                        &ARG[ 0 ]
                        , KEY.data()
                        , SIZE
                    ) == 0;
                }
            );
            if( PROC_MAP_IT == PROC_MAP_END ) {
                return false;
            }

            const auto &    PROC = PROC_MAP_IT->second;
            if( PROC(
                argsIt
                , ARGS_END
            ) == false ) {
                return false;
            }
        }

        return true;
    }

    void helpArgs(
    )
    {
        //TODO
        std::printf( "HELP\n" );
    }
}
