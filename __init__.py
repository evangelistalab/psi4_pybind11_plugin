#
# @BEGIN LICENSE
#
# pybind_plugin by Psi4 Developer, a plugin to:
#
# Psi4: an open-source quantum chemistry software package
#
# Copyright (c) 2007-2017 The Psi4 Developers.
#
# The copyrights for code used from other parties are included in
# the corresponding files.
#
# This file is part of Psi4.
#
# Psi4 is free software; you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, version 3.
#
# Psi4 is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License along
# with Psi4; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
#
# @END LICENSE
#

"""Plugin docstring.

"""
__version__ = '0.1'
__author__  = 'Psi4 Developer'
module_name = 'PYBIND_PLUGIN'

# Load Python modules
#from .pymodule import *

# Load pybind11 module
import os
import psi4
from .pybind_plugin import *

from .extras import prepare_options_for_plugin
prepare_options_for_plugin(module_name, pybind_plugin.read_options)

#options = psi4.core.get_options()
#
#options.set_read_globals(True)
##options.set_current_module(module_name)
#pybind_plugin.read_options(module_name,options)
##options.validate_options()
#options.set_read_globals(False)

print("Hello!")
#plugdir = os.path.split(os.path.abspath(__file__))[0]
#sofile = plugdir + '/' + os.path.split(plugdir)[1] + '.so'
#psi4.core.plugin_load(sofile)

