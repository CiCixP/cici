[GlobalParams]
  gravity = '0 0 0'

  initial_T_liquid = 453.03563239147
  initial_T_vapor  = 453.03563239147
  initial_p_liquid = 1e6
  initial_p_vapor  = 1e6
  initial_vel_liquid = 0.
  initial_vel_vapor = 0.
  initial_alpha_vapor = 0.95

  scaling_factor_2phase = '1
                           1 1e-2 1e-4
                           1 1e-3 1e-5'

  interface_transfer = true
  pressure_relaxation = true
  velocity_relaxation = true
  wall_mass_transfer = false

  #specific_interfacial_area_min_value = 1e-15
  #specific_interfacial_area_max_value = 100

  stabilization = p2

  closures_type = trace
[]

[Stabilizations]
 [./evm]
   type = EntropyViscosity
   use_first_order = false
  # use_low_mach_fix = false
  # Cmax_liquid = 7.5
  # Cmax_vapor = 7.5
  # Centropy_liquid = 15
  # Centropy_vapor = 15
  # Cjump_liquid = 2
  # Cjump_vapor = 2
 [../]
 [./Lapidus]
   type = Lapidus
   cl_liquid = 1
   cl_vapor = 1
 [../]
 [./p1]
   type = StabilizationPressure
   order = FIRST
   ce_liquid = 1
   ce_vapor = 1
 [../]
 [./p2]
   type = StabilizationPressure
   order = SECOND
   ce_liquid = 2
   ce_vapor = 2
 [../]
[]

[Functions]
  # Nozzle 2 Design
  [./Dh_fn]
    type = ParsedFunction
    value = '2* if(x<0.95,if(x<0.35,if(x<0.05,0.15,0.0625*cos((pi/3)*(10*x-0.5))+0.0875), \
              0.05*(x-0.35)+0.025),0.055)'
  [../]
  [./area_fn]
    type = ParsedFunction
    value = 'pi*(if(x<0.95,if(x<0.35,if(x<0.05,0.15,0.0625*cos((pi/3)*(10*x-0.5))+0.0875), \
              0.05*(x-0.35)+0.025),0.055))^2'
  [../]
[]

[FluidProperties]
  [./eos]
    type = IAPWS957EqnFluidProperties
  [../]
[]

[Components]
  [./pipe]
    type = Pipe
    position = '0 0 0'
    orientation = '1 0 0'
    length = 1.0
    n_elems = 500

    D_h = Dh_fn
    A = area_fn

    f = 0.01
    f_interface = 0
    #Hw_liquid = 0.0
    #Hw_vapor  = 0.0
    q_wall = 0
    #T_wall = 310 # wall temperature

    fp = eos
  [../]

  [./inlet]
    type = Inlet
    input = 'pipe(in)'

    p0_liquid = 1e6
    T0_liquid = 453.03563239147
    p0_vapor = 1e6
    T0_vapor = 453.03563239147
    alpha_vapor = 0.95
  [../]

  [./outlet]
    type = Outlet
    input = pipe(out)

    p_vapor = 6e5
    p_liquid = 6e5
    legacy = true
  [../]
[]

[AuxVariables]
  [./pressure_mix]
  [../]
[]

[AuxKernels]
  [./pmix_ak]
    type = MixtureQuantityAux
    variable = pressure_mix
    a = 'alpha_liquid alpha_vapor'
    b = 'p_liquid p_vapor'
    execute_on = 'initial timestep_end'
  [../]
[]

[Preconditioning]
  [./SMP_PJFNK]
    type = SMP
    full = true
    solve_type = PJFNK
    line_search = basic
  [../]
[]

[Executioner]
  type = Transient
  scheme = 'bdf2'

  nl_rel_tol = 1e-6
  nl_abs_tol = 1e-3
  nl_max_its = 5

  l_tol = 1e-3
  l_max_its = 100

  start_time = 0.0
  end_time = 10
  [./TimeStepper]
    type = SolutionTimeAdaptiveDT
    dt = 0.0001
  [../]
  dtmin = 1.e-8
  dtmax = 1.e-4

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
    output_material_properties = true
    show_material_properties = 'specific_interfacial_area'
  [../]
  [./file]
    type = Console
    output_file = true
  [../]
[]
