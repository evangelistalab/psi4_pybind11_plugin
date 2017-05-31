from __future__ import print_function
import psi4

def test_psi4_basic():
    """tu1-h2o-energy"""
    #! Sample HF/cc-pVDZ H2O computation

    h2o = psi4.geometry("""
      O
      H 1 0.96
      H 1 0.96 2 104.5
    """)

    psi4.set_options({'basis': "cc-pVDZ"})
    psi4.energy('scf')

    assert psi4.compare_values(-76.0266327341067125, psi4.get_variable('SCF TOTAL ENERGY'), 6, 'SCF energy')


def test_plug_1():
    """"""

    import pybind_plugin as pbp # register options here
    
    mymol = psi4.geometry("""
    O
    H 1 R
    H 1 R 2 A
    
    R = .9
    A = 104.5
    """)
    
    psi4.set_options({
      'basis': 'sto-3g'
    })
    
    e, wfn = psi4.energy('scf', return_wfn=True)

    pyopt = psi4.core.get_options()
    
    pbp.myplugin(wfn, pyopt)
    assert pyopt.get_int("PBP_C_PRINT") == 1
    assert pyopt.get_double("PBP_C_CONV") == 1e-6
    assert pyopt.get_str("PBP_C_TYPE") == "CONV"

    psi4.set_module_options("PYBIND_PLUGIN", {
      'PBP_C_PRINT': 2,
      'PBP_C_CONV': 5e-4,
      'PBP_C_TYPE': 'df',
    })
    
    pbp.myplugin(wfn, pyopt)
    assert pyopt.get_int("PBP_C_PRINT") == 2
    assert pyopt.get_double("PBP_C_CONV") == 5e-4
    assert pyopt.get_str("PBP_C_TYPE") == "DF"


def test_plug_1b():
    """"""

    import pybind_plugin as pbp # register options here
    
    mymol = psi4.geometry("""
    O
    H 1 R
    H 1 R 2 A
    
    R = .9
    A = 104.5
    """)
    
    psi4.set_options({
      'basis': 'sto-3g'
    })
    
    e, wfn = psi4.energy('scf', return_wfn=True)

    pyopt = psi4.core.get_options()
    
    pbp.myplugin(wfn, pyopt)
    assert pyopt.get_int("PBP_C_PRINT") == 1
    assert pyopt.get_double("PBP_C_CONV") == 1e-6
    assert pyopt.get_str("PBP_C_TYPE") == "CONV"

    psi4.set_module_options("PYBIND_PLUGIN", {
      'PBP_C_PRINT': 2,
      'PBP_C_CONV': 5e-4,
      'PBP_C_TYPE': 'df',
    })
    
    pbp.myplugin(wfn, pyopt)
    assert pyopt.get_int("PBP_C_PRINT") == 2
    assert pyopt.get_double("PBP_C_CONV") == 5e-4
    assert pyopt.get_str("PBP_C_TYPE") == "DF"

