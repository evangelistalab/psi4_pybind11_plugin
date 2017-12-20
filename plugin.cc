#include "psi4/libmints/basisset.h"
#include "psi4/libmints/wavefunction.h"
#include "psi4/liboptions/liboptions.h"
#include "psi4/libpsi4util/PsiOutStream.h"
#include "psi4/psi4-dec.h"

#include <pybind11/pybind11.h>
namespace py = pybind11;

namespace psi {
namespace pybind_plugin {

/// This function is exposed in the Python interface
int myplugin_function(int n) { return std::pow(2, n); }

/// Function to read options exposed in the Python interface
int read_options(std::string name, Options &options) {
  if (name == "PYBIND_PLUGIN" || options.read_globals()) {
    /*- The amount of information printed to the output file -*/
    options.add_int("PBP_C_PRINT", 1);
//    options.add_int("PBP_C_PRINT", 1);
    options.add_double("PBP_C_CONV", 1e-6);
    options.add_str("PBP_C_TYPE", "CONV", "DF CONV");
  }
  return true;
}

/// Main pluging function exposed in the Python interface
SharedWavefunction myplugin(SharedWavefunction ref_wfn, Options &options) {
  options.set_current_module("PYBIND_PLUGIN");
  outfile->Printf("\n Number of basis functions: %d",
                  ref_wfn->basisset()->nbf());

  outfile->Printf("\n\n Options passed by the user:\n");
  outfile->Printf("\n Ref:   %s", options.get_str("REFERENCE").c_str());
  outfile->Printf("\n Print: %d", options.get_int("PBP_C_PRINT"));
  outfile->Printf("\n Conv:  %f", options.get_double("PBP_C_CONV"));
  outfile->Printf("\n Type:  %s", options.get_str("PBP_C_TYPE").c_str());
  outfile->Printf("\n");

  int n = options.get_int("PBP_C_POW");

  printf("\n  Result of function called in plugin (C++ side)    = %d\n",myplugin_function(n));

  return ref_wfn;
}


PYBIND11_MODULE(pybind_plugin, m) {
  m.doc() = "pybind_plugin: a simple pybind 11 plugin";
  m.def("myplugin", &myplugin, "Run my plugin");
  m.def("myplugin_function", &myplugin_function, "Two to the power of n");
  m.def("read_options", &read_options, "Read options for my plugin");
}
}
} // End namespaces
