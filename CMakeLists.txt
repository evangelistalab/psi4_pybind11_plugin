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

cmake_policy(SET CMP0048 NEW)  # project_VERSION* variables populated from project(... VERSION x.x.x) string
project(pybind_plugin
        VERSION 0.1
        LANGUAGES CXX C)
set(pybind_plugin_AUTHORS     "")
set(pybind_plugin_DESCRIPTION "")
set(pybind_plugin_URL         "")
set(pybind_plugin_LICENSE     "LGPL-3.0")

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(psi4 1.0 REQUIRED)

include(psi4OptionsTools)

option_with_print(ENABLE_OPENMP "Enable threadsafe linking to OpenMP parallelized programs." ON)

include(autocmake_omp)

add_psi4_plugin(pybind_plugin plugin.cc)
