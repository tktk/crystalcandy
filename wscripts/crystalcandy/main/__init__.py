# -*- coding: utf-8 -*-

from wscripts.builder import buildProgram
from ..builder import getPackageString

MODULE_NAME = 'main'
_TARGET = 'crystalcandy'

def build( _context ):
    buildProgram(
        _context,
        _TARGET,
        getPackageString(
            MODULE_NAME,
            _context.env.MY_MAIN_IMPL,
        ),
    )
