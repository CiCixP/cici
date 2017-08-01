[GlobalParams]
  gravity = '0 0 0'

  initial_T_liquid = 358.15
  initial_T_vapor  = 373.15
  initial_p_liquid = 1.0130E+5
  initial_p_vapor  = 1.0130E+5
  initial_vel_liquid = 0.0
  initial_vel_vapor = 0.0
  initial_alpha_vapor = 0.001

  # 7 eqn global parameters
  phase_interaction = true
  pressure_relaxation = true
  velocity_relaxation = true
  interface_transfer = false
  wall_mass_transfer = false

  chf_table = AECL-2006

  closures_type = trace
  explicit_acoustic_impedance = true

  scaling_factor_2phase = '1e0
                           1e0 1e0 1e0
                           1e0 1e0 1e0'
[]

[FluidProperties]
  [./eos]
    type = IAPWS957EqnFluidProperties
  [../]
[]

[Components]
  [./pipe]
    type = Pipe
    fp = eos
    # geometry
    position = '0 0 0'
    orientation = '1 0 0'
    A   = 4.6355e-1
    D_h  = 1.1778e-2
    P_hf = 1.1778e-2
    q_wall = 1.0343E+4
    length = 1.2
    n_elems = 12
    f = 0
    f_interface = 0
  [../]

  [./inlet]
    type = Inlet
    input = 'pipe(in)'
    alpha_vapor = 0.001
    m_dot_liquid = 448.5558707
    m_dot_vapor = 0.000276938
    T_liquid = 358.15
    T_vapor = 373.15
  [../]

  [./outlet]
    type = Outlet
    input = 'pipe(out)'
    p_liquid = 1.013E5
    p_vapor  = 1.013E5
  [../]
[]

[AuxVariables]
  [./q_CHF]
  [../]
[]

[AuxKernels]
  [./q_CHF]
    type = CriticalHeatFluxAux
    variable = q_CHF
    A = A
    arhoA_liquid = arhoA_liquid
    arhoA_vapor = arhoA_vapor
    H_liquid = H_liquid
    H_vapor = H_vapor
    vel_liquid = vel_liquid
    vel_vapor = vel_vapor
    p_liquid = p_liquid
    fp = eos
    chf_table = chf_table
  [../]
[]

[Preconditioning]
  [./SMP_PJFNK]
    type = SMP
    full = true
    solve_type = 'PJFNK'
    line_search = basic
  [../]
[]

[Executioner]
  type = Transient
  dt = 1.e-5
  dtmin = 1.e-8

  nl_rel_tol = 1e-7
  nl_abs_tol = 1e-7
  nl_max_its = 30

  l_tol = 1e-3
  l_max_its = 100

  start_time = 0.0
  num_steps = 30

  [./Quadrature]
    type = TRAP
    order = FIRST
  [../]
[]

[Outputs]
  [./out]
    type = Exodus
    use_displaced = true
    sequence = false
  [../]
[]
