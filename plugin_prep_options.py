def prepare_options_for_plugin(module, readopt):
    """Resets P::e.options with options from the C++ "read_options"
    block *readopt* labeled for *module*.

    """
    import psi4
    options = psi4.core.get_options()

    options.set_read_globals(True)
    options.add_int("PBP_C_POW",0);
    readopt(module, options)
    options.set_read_globals(False)
