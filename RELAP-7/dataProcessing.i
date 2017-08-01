# Edwards' pipe experiment
#
# A. R. Edwards and T. P. O'Brien, “Studies of Phenomena Connected with the Depressurization of Water Reactors,”
#   Journal of the British Nuclear Energy Society, pp. 125-135, April 1970.
#

[GlobalParams]
  gravity = '0 9.81 0'

  initial_T = 505.
  initial_p = 7.0995e6
  initial_vel = 0

  closures_type = simple

  alpha_vapor_bounds = '0.0001 0.9999'
  volume_fraction_remapper_exponential_region_width = 1e-06

  stabilization = low
[]

[Stabilizations]
  [./low]
    type = EntropyViscosity
    use_first_order = true
  [../]
[]

[FluidProperties]
  [./eos]
    type = IAPWS95LiquidFluidProperties
  [../]
[]

[Functions]
  [./pressure_fn]
    type = PiecewiseLinear
    data_file = 'EdwardPipe_Pres.csv'
    format = columns
    x_index_in_file = 0
    y_index_in_file = 1
  [../]
  [./temperature_fn]
    type = PiecewiseLinear
    data_file = 'EdwardPipe_Temp.csv'
    format = columns
    x_index_in_file = 0
    y_index_in_file = 1
  [../]
  [./void_fn]
    type = PiecewiseLinear
    data_file = 'EdwardPipe_Void.csv'
    format = columns
    x_index_in_file = 0
    y_index_in_file = 1
  [../]
[]

[Components]
  [./pipe]
    type = Pipe
    fp = eos
    # geometry
    position = '0 0 0'
    orientation = '1 0 0'
    length = '4.083 0.013'
    n_elems = '10   5'

    A = 4.20283451e-03
    f = 0.01
    Hw = 0.
    T_wall = 505
  [../]

  [./inlet]
    type = SolidWall
    input = 'pipe(in)'
  [../]

  [./outlet]
    type = SolidWall
    input = 'pipe(out)'
  [../]
[]

[Postprocessors]
  [./pressure_GS_5]
    type = FunctionValuePostprocessor
    function = pressure_fn
  [../]
  [./temperature_GS_5]
    type = FunctionValuePostprocessor
    function = temperature_fn
  [../]
  [./void_GS_5]
    type = FunctionValuePostprocessor
    function = void_fn
  [../]
[]

[Preconditioning]
  [./pc]
    type = SMP
    full = true
    solve_type = PJFNK
    line_search = basic
    petsc_options_iname = '-pc_type'
    petsc_options_value = ' lu     '
  [../]
[]

[Executioner]
  type = Transient
  scheme = 'bdf2'

  [./TimeStepper]
    type = ConstantDT
    dt = 1e-3
  [../]
  dtmin = 1.e-8
  dtmax = 1e-3
  start_time = 0.0
  end_time = 0.6

  nl_rel_tol = 1e-5
  nl_abs_tol = 1e-4
  nl_max_its = 15
  l_tol = 1e-2
  l_max_its = 30

  [./Quadrature]
    type = TRAP
    order = FIRST
  [../]
[]

[Outputs]
  [./csv]
    type = CSV
    execute_on = 'initial timestep_end'
  [../]
[]

[Debug]
  #show_var_residual_norms = true
[]
