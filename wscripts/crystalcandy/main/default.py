# -*- coding: utf-8 -*-

from wscripts import common
from . import MODULE_NAME

IMPL_NAME = 'default'

def setup(
    _context,
    _sources,
    _libraries,
    _useModules,
):
    _sources[ common.SOURCE_DIR ] = {
        common.CRYSTALCANDY : {
            MODULE_NAME : [
                'main.cpp',
                {
                    IMPL_NAME : {
                        'main.cpp',
                    },
                },
            ],
        },
    }