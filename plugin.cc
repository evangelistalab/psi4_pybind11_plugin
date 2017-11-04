/*
 * @BEGIN LICENSE
 *
 * pybind_plugin by Psi4 Developer, a plugin to:
 *
 * Psi4: an open-source quantum chemistry software package
 *
 * Copyright (c) 2007-2017 The Psi4 Developers.
 *
 * The copyrights for code used from other parties are included in
 * the corresponding files.
 *
 * This file is part of Psi4.
 *
 * Psi4 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * Psi4 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along
 * with Psi4; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * @END LICENSE
 */

#include "psi4/libmints/basisset.h"
#include "psi4/libmints/wavefunction.h"
#include "psi4/liboptions/liboptions.h"
#include "psi4/libpsi4util/PsiOutStream.h"
#include "psi4/libpsio/psio.hpp"
#include "psi4/psi4-dec.h"
#include "psi4/psi4-dec.h"

#include <pybind11/pybind11.h>
namespace py = pybind11;

namespace psi {
namespace pybind_plugin {

int read_options(std::string name, Options &options) {
  if (name == "PYBIND_PLUGIN" || options.read_globals()) {
    /*- The amount of information printed to the output file -*/
    options.add_int("PBP_C_PRINT", 1);
    options.add_double("PBP_C_CONV", 1e-6);
    options.add_str("PBP_C_TYPE", "CONV", "DF CONV");
  }
  return true;
}

SharedWavefunction myplugin(SharedWavefunction ref_wfn, Options &options) {
  options.set_current_module("PYBIND_PLUGIN");
  outfile->Printf("\n Number of basis functions: %d",
                  ref_wfn->basisset()->nbf());
  outfile->Printf("\n Ref:   %s", options.get_str("REFERENCE").c_str());
  outfile->Printf("\n Print: %d", options.get_int("PBP_C_PRINT"));
  outfile->Printf("\n Conv:  %f", options.get_double("PBP_C_CONV"));
  outfile->Printf("\n Type:  %s", options.get_str("PBP_C_TYPE").c_str());

  printf("\n Ref:   %s", options.get_str("REFERENCE").c_str());
  printf("\n Print: %d", options.get_int("PBP_C_PRINT"));
  printf("\n Conv:  %f", options.get_double("PBP_C_CONV"));
  printf("\n Type:  %s", options.get_str("PBP_C_TYPE").c_str());
  printf("\n");

  return ref_wfn;
}

PYBIND11_PLUGIN(pybind_plugin) {
  py::module m("pybind_plugin", "pybind11 example plugin");

  m.def("myplugin", &myplugin, "Run my plugin");
  m.def("read_options", &read_options, "Read options for my plugin");

  return m.ptr();
}
}
} // End namespaces
