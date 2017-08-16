[GlobalParams]
  initial_p = 15.17e6
  initial_vel = 1.
  initial_T = 564.15

  scaling_factor_1phase = '1.e0 1.e-2 1.e-5'
  scaling_factor_temperature = 1e-2
  stabilization = evm1
[]

[Stabilizations]
  [./evm1]
    type = EntropyViscosity
    use_first_order = true
  [../]
[]

[FluidProperties]
  [./eos]
    type = IAPWS95LiquidFluidProperties
  [../]
[]

[HeatStructureMaterials]
  [./fuel-mat]
    type = SolidMaterialProperties
    k = 3.65
    Cp = 288.734
    rho = 1.0412e2
  [../]
  [./gap-mat]
    type = SolidMaterialProperties
    k = 1.084498
    Cp = 1.0
    rho = 1.0
  [../]
  [./clad-mat]
    type = SolidMaterialProperties
    k = 16.48672
    Cp = 321.384
    rho = 6.6e1
  [../]
  [./clad3-mat]
    type = SolidMaterialProperties
    k = 16.48672
    Cp = 6.6e3
    rho = 6.6e1
  [../]

  [./wall-mat]
    type = SolidMaterialProperties
    k = 100.0
    rho = 100.0
    Cp = 100.0
  [../]
[]


[Components]
  [./reactor]
    type = PrescribedReactorPower
    function = 2.77199979e9
  [../]

  #Core region components ########################################################################################################################
  [./CH1]
    type = CoreChannel
    fp = eos
    position = '0 -1.2 0'
    orientation = '0 0 1'
    A = 1.161864
    D_h = 0.01332254
    length = 3.6576
    n_elems = 8

    f = 0.01
    Hw = 5.33e4
    P_hf = 321.341084980423
    initial_Ts = 564.15

    n_heatstruct = 3
    name_of_hs = 'FUEL GAP CLAD'
    fuel_type = cylinder
    width_of_hs = '0.0046955  0.0000955  0.000673'
    elem_number_of_hs = '9 3 3'
    material_hs = 'fuel-mat gap-mat clad-mat'
    power = reactor
    power_fraction = '3.33672612e-1 0 0'
  [../]

  [./CH2]
    type = CoreChannel
    fp = eos
    position = '0 0 0'
    orientation = '0 0 1'
    A = 1.549152542
    D_h = 0.01332254
    length = 3.6576
    n_elems = 8

    f = 0.01
    Hw = 5.33e4
    P_hf = 428.454929876871
    initial_Ts = 564.15

    n_heatstruct = 3
    name_of_hs = 'FUEL GAP CLAD'
    fuel_type = cylinder
    width_of_hs = '0.0046955  0.0000955  0.000673'
    elem_number_of_hs = '9 3 3'
    material_hs = 'fuel-mat gap-mat clad-mat'
    power = reactor
    power_fraction = '3.69921461e-1 0 0'
  [../]

  [./CH3]
    type = CoreChannel
    fp = eos
    position = '0 1.2 0'
    orientation = '0 0 1'
    A = 1.858983051
    D_h = 0.01332254
    length = 3.6576
    n_elems = 8

    f = 0.01
    Hw = 5.33e4
    P_hf = 514.145916018189
    initial_Ts = 564.15

    n_heatstruct = 3
    name_of_hs = 'FUEL GAP CLAD'
    fuel_type = cylinder
    width_of_hs = '0.0046955  0.0000955  0.000673'
    elem_number_of_hs = '9 3 3'
    material_hs = 'fuel-mat gap-mat clad3-mat'
    power = reactor
    power_fraction = '2.96405926e-1 0 0'
  [../]

  [./bypass_pipe]
    type = Pipe
    fp = eos
    position = '0 1.5 0'
    orientation = '0 0 1'
    A = 1.589571014
    D_h = 1.42264
    length = 3.6576
    n_elems = 5

    f = 0.001
    Hw = 0.0
  [../]

  [./LowerPlenum]
    type = Branch
    inputs = 'DownComer-A(out) DownComer-B(out)'
    outputs = 'CH1:pipe(in) CH2:pipe(in) CH3:pipe(in) bypass_pipe(in)'
    K = '0.2 0.2 0.2 0.2 0.4 40.0'
    A_ref = 3.618573408
    scaling_factors = '1e-3 1'
  [../]

  [./UpperPlenum]
    type = Branch
    inputs = 'CH1:pipe(out) CH2:pipe(out) CH3:pipe(out) bypass_pipe(out)'
    outputs = 'pipe1-HL-A(in) pipe1-HL-B(in)'
    K = '0.5 0.5 0.5 80.0 0.5 0.5'
    A_ref = 7.562307456
    scaling_factors = '1e-3 1'
  [../]
  ################################################################################################################################################

  #Loop A components #############################################################################################################################
  [./DownComer-A]
    type = Pipe
    fp = eos
    position = '0 2.0 4.0'
    orientation = '0 0 -1'
    A = 3.6185734
    D_h = 1.74724302
    length = 4
    n_elems = 3

    f = 0.001
    Hw = 0.
  [../]

  [./pipe1-HL-A]
    type = Pipe
    fp = eos
    position = '0 0.5 4.0'
    orientation = '0 0 1'
    A = 7.562307456
    D_h = 3.103003207
    length = 4.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe2-HL-A]
    type = Pipe
    fp = eos
    position = '0 0.5 8.0'
    orientation = '0 1 0'
    A = 2.624474
    D_h = 1.828
    length = 3.5
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe1-CL-A]
    type = Pipe
    fp = eos
    position = '0 3.0 4.0'
    orientation = '0 -1 0'
    A = 2.624474
    D_h = 1.828
    length = 1.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe2-CL-A]
    type = Pipe
    fp = eos
    position = '0 4 4.0'
    orientation = '0 -1 0'
    A = 2.624474
    D_h = 1.828
    length = 0.8
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe1-SC-A]
    type = Pipe
    fp = eos
    position = '0 5.2 4.0'
    orientation = '0 -1 0'
    A = 2.624474
    D_h = 1.828
    length = 1.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe2-SC-A]
    type = Pipe
    fp = eos
    position = '0 4.2 8.0'
    orientation = '0 1 0'
    A = 2.624474
    D_h = 1.828
    length = 1.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./Branch1-A]
    type = Branch
    inputs = 'pipe1-HL-A(out)'
    outputs = 'pipe2-HL-A(in) pipe-to-Pressurizer(in)'
    K = '0.5 0.7 80.'
    A_ref = 7.562307456
    scaling_factors = '1e-3 1'
  [../]

  [./Branch2-A]
    type = Branch
    inputs = 'pipe1-CL-A(out)'
    outputs = 'DownComer-A(in)'
    K = '0.5 0.7'
    A_ref = 3.6185734
    scaling_factors = '1e-3 1'
  [../]

  [./Branch3-A]
    type = Branch
    inputs = 'pipe2-HL-A(out)'
    outputs = 'HX-A:primary_pipe(in)'
    K = '0.5 0.7'
    A_ref = 2.624474
    scaling_factors = '1e-3 1'
  [../]

  [./Pump-A]
    type = Pump
    fp = eos
    inputs = 'pipe2-CL-A(out)'
    outputs = 'pipe1-CL-A(in)'
    A_ref = 2.624474
    K_reverse = '0 0'
    head = 8.66
  [../]

  [./HX-A:primary_pipe]
    type = Pipe
    position = '0 4 8'
    orientation = '0 0 -1'
    length = 4
    n_elems = 10
    fp = eos
    A = 5.
    P_hf = 2695.1
    D_h = 0.01
    roughness = 0
    f = 0.01
    Hw = 1.e4
    heat_transfer_geom = PIPE
  [../]

  [./HX-A:wall]
    type = HeatStructure
    dim = 2
    position = '0 4.1 8'
    orientation = '0 0 -1'
    axial_offset = 0
    initial_T = 564.15
    length = 4
    n_elems = 10
    names = 'solid_wall'
    widths = '0.001'
    n_part_elems = '2'
    materials = 'wall-mat'
    hs_type = PLATE
    depth = 1
  [../]

  [./HX-A:secondary_pipe]
    type = Pipe
    position = '0 4.201 4'
    orientation = '0 0 1'
    length = 4
    n_elems = 10
    fp = eos
    A = 5.
    P_hf = 2695.1
    D_h = 0.01
    roughness = 0
    f = 0.01
    Hw = 1.e4
    PoD = 1
    heat_transfer_geom = PIPE

    initial_p = 15.17e6
    initial_T = 564.15
    initial_vel = 1.
  [../]

  [./HX-A:hx_conn_pri]
    type = HXConnector
    pipe = HX-A:primary_pipe
    hs = HX-A:wall
    hs_side = bottom
  [../]

  [./HX-A:hx_conn_sec]
    type = HXConnector
    pipe = HX-A:secondary_pipe
    hs = HX-A:wall
    hs_side = top
  [../]

  [./Branch4-A]
    type = Branch
    inputs = 'pipe1-SC-A(out)'
    outputs = 'HX-A:secondary_pipe(in)'
    K = '0.5 0.7'
    A_ref = 2.624474e2
    scaling_factors = '1e-3 1'
  [../]

  [./Branch5-A]
    type = Branch
    inputs = 'HX-A:secondary_pipe(out)'
    outputs = 'pipe2-SC-A(in)'
    K = '0.5 0.7'
    A_ref = 2.624474e2
    scaling_factors = '1e-3 1'
  [../]

  [./Branch6-A]
    type = Branch
    inputs = 'HX-A:primary_pipe(out)'
    outputs = 'pipe2-CL-A(in)'
    K = '0.5 0.7'
    A_ref = 2.624474e2
    scaling_factors = '1e-3 1'
  [../]

  [./MassFlowRateIn-SC-A]
    type = Inlet
    input = 'pipe1-SC-A(in)'
    rho = 790.214380528884476
    vel = 4.542
  [../]
  [./PressureOutlet-SC-A]
    type = Outlet
    input = 'pipe2-SC-A(out)'
    p = '151.7e5'
    legacy = true
  [../]
  ################################################################################################################################################

  #Loop B components #############################################################################################################################
  [./DownComer-B]
    type = Pipe
    fp = eos
    position = '0 -2.0 4.0'
    orientation = '0 0 -1'
    A = 3.6185734
    D_h = 1.74724302
    length = 4
    n_elems = 3

    f = 0.001
    Hw = 0.
  [../]

  [./pipe1-HL-B]
    type = Pipe
    fp = eos
    position = '0 -0.5 4.0'
    orientation = '0 0 1'
    A = 7.562307456
    D_h = 3.103003207
    length = 4.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe2-HL-B]
    type = Pipe
    fp = eos
    position = '0 -0.5 8.0'
    orientation = '0 -1 0'
    A = 2.624474
    D_h = 1.828
    length = 3.5
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe1-CL-B]
    type = Pipe
    fp = eos
    position = '0 -3.0 4.0'
    orientation = '0 1 0'
    A = 2.624474
    D_h = 1.828
    length = 1.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe2-CL-B]
    type = Pipe
    fp = eos
    position = '0 -4.0 4.0'
    orientation = '0 1 0'
    A = 2.624474
    D_h = 1.828
    length = 0.8
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe1-SC-B]
    type = Pipe
    fp = eos
    position = '0 -5.2 4.0'
    orientation = '0 1 0'
    A = 2.624474
    D_h = 1.828
    length = 1.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./pipe2-SC-B]
    type = Pipe
    fp = eos
    position = '0 -4.2 8.0'
    orientation = '0 -1 0'
    A = 2.624474
    D_h = 1.828
    length = 1.
    n_elems = 3

    f = 0.001
    Hw = 0.0
  [../]

  [./Branch1-B]
    type = Branch
    inputs = 'pipe1-HL-B(out)'
    outputs = 'pipe2-HL-B(in)'
    K = '0.5 0.7'
    A_ref = 7.562307456
    scaling_factors = '1e-3 1'
  [../]

  [./Branch2-B]
    type = Branch
    inputs = 'pipe1-CL-B(out)'
    outputs = 'DownComer-B(in)'
    K = '0.5 0.7'
    A_ref = 3.6185734
    scaling_factors = '1e-3 1'
  [../]

  [./Branch3-B]
    type = Branch
    inputs = 'pipe2-HL-B(out)'
    outputs = 'HX-B:primary_pipe(in)'
    K = '0.5 0.7'
    A_ref = 2.624474
    scaling_factors = '1e-3 1'
  [../]

  [./Pump-B]
    type = Pump
    fp = eos
    inputs = 'pipe2-CL-B(out)'
    outputs = 'pipe1-CL-B(in)'
    A_ref = 2.624474
    K_reverse = '0 0'
    head = 8.66
  [../]

[./HX-B:primary_pipe]
    type = Pipe
    position = '0 -4 8'
    orientation = '0 0 -1'
    length = 4
    n_elems = 10
    fp = eos
    A = 5.
    P_hf = 2695.1
    D_h = 0.01
    f = 0.01
    Hw = 1.e4
  [../]

  [./HX-B:wall]
    type = HeatStructure
    dim = 2
    position = '0 -4.101 8'
    orientation = '0 0 -1'
    axial_offset = 0
    initial_T = 564.15
    length = 4
    n_elems = 10
    names = 'solid_wall'
    widths = '0.001'
    n_part_elems = '2'
    materials = 'wall-mat'
    hs_type = PLATE
    depth = 1
  [../]

  [./HX-B:secondary_pipe]
    type = Pipe
    position = '0 -4.201 4'
    orientation = '0 0 1'
    length = 4
    n_elems = 10
    fp = eos
    A = 5.
    P_hf = 2695.1
    D_h = 0.01
    f = 0.01
    Hw = 1.e4
    heat_transfer_geom = PIPE
  [../]

  [./HX-B:hx_conn_pri]
    type = HXConnector
    pipe = HX-B:primary_pipe
    hs = HX-B:wall
    hs_side = top
  [../]

  [./HX-B:hx_conn_sec]
    type = HXConnector
    pipe = HX-B:secondary_pipe
    hs = HX-B:wall
    hs_side = bottom
  [../]

  [./Branch4-B]
    type = Branch
    inputs = 'pipe1-SC-B(out)'
    outputs = 'HX-B:secondary_pipe(in)'
    K = '0.5 0.7'
    A_ref = 2.624474e2
    scaling_factors = '1e-3 1'
  [../]

  [./Branch5-B]
    type = Branch
    inputs = 'HX-B:secondary_pipe(out)'
    outputs = 'pipe2-SC-B(in)'
    K = '0.5 0.7'
    A_ref = 2.624474e2
    scaling_factors = '1e-3 1'
  [../]

  [./Branch6-B]
    type = Branch
    inputs = 'HX-B:primary_pipe(out)'
    outputs = 'pipe2-CL-B(in)'
    K = '0.5 0.7'
    A_ref = 2.624474e2
    scaling_factors = '1e-3 1'
  [../]

  [./MassFlowRateIn-SC-B]
    type = Inlet
    input = 'pipe1-SC-B(in)'
    rho = 790.214380528884476
    vel = 4.542
  [../]
  [./PressureOutlet-SC-B]
    type = Outlet
    input = 'pipe2-SC-B(out)'
    p = 151.7e5
    legacy = true
  [../]
  ################################################################################################################################################


  # Pressurizer ##################################################################################################################################
  [./pipe-to-Pressurizer]
    type = Pipe
    fp = eos
    position = '0 0.5 8.0'
    orientation = '0 0 1'
    A = 2.624474
    D_h = 1.828
    length = 0.5
    n_elems = 3

    f = 10.
    Hw = 0.0
  [../]

  [./Pressurizer]
    type = Inlet
    input = 'pipe-to-Pressurizer(out)'
    p0 = 151.7e5
    T0 = 564.15
  [../]
  ################################################################################################################################################
[]



[Preconditioning]
  [./SMP_PJFNK]
    type = SMP
    full = true
    solve_type = 'PJFNK'
    petsc_options_iname = '-pc_type -pc_factor_shift_type -pc_factor_shift_amount'
    petsc_options_value = ' svd      NONZERO               1e-10'
    line_search = basic
  [../]
[]

[Executioner]
  type = Transient
  scheme = 'bdf2'

  [./TimeStepper]
    type = SolutionTimeAdaptiveDT
    dt = 0.01
  [../]

  nl_rel_tol = 1e-10
  nl_abs_tol = 1e-8
  nl_max_its = 30

  l_tol = 1e-3
  l_max_its = 30

  start_time = 0.0
  end_time = 200.0

  [./Quadrature]
    type = TRAP
    order = FIRST
  [../]
[]


[Outputs]
  [./out_displaced]
    type = Exodus
    use_displaced = true
    sequence = false
  [../]
  [./console]
    type = Console
    execute_scalars_on = none
  [../]
[]
