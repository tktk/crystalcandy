# -*- coding: utf-8 -*-

from .. import common
from ..builder import getPackageString as getPackageStringCommon

def getPackageString(
    *_args
):
    return getPackageStringCommon(
        common.CRYSTALCANDY,
        _args
    )
