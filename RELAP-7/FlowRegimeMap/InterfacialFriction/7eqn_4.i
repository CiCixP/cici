horizontal = false
ht_geom = PIPE
# alpha_vapor limits
alpha_vapor_min = 0.0001
alpha_vapor_max = 0.9999

[ClosureTest2Phase]
  A = 1e-4
  D_h = 2e-5

  # volume fraction
  alpha_vapor = 0.2
  # temperatures
  T_liquid = 393.36154593649
  T_vapor = 393.36154593649
  # pressures
  p_liquid = 2e5
  p_vapor = 2e5
  # velocities
  vel_liquid = 2.5
  vel_vapor = 2.5
[]

[Functions]
  [./q_wall_fn]
    type = ConstantFunction
    value = 10e6
  [../]
[]

[Materials]
  [./frm]
    type = FlowRegimeMaterial
    horizontal = ${horizontal}
    A = A
    alpha_vapor = alpha_vapor
    arhoA_liquid = arhoA_liquid
    arhoA_vapor = arhoA_vapor
    H_liquid = H_liquid
    H_vapor = H_vapor
    e_liquid = e_liquid
    e_vapor = e_vapor
    vel_liquid = vel_liquid
    vel_vapor = vel_vapor
    rho_liquid = rho_liquid
    rho_vapor = rho_vapor
    v_liquid = v_liquid
    v_vapor = v_vapor
    D_h = D_h
    cp_liquid = cp_liquid
    k_liquid = k_liquid
    p_liquid = p_liquid
    p_vapor = p_vapor
    T_liquid = T_liquid
    T_vapor = T_vapor
    mu_vapor = mu_vapor
    surface_tension = surface_tension
    q_wall = q_wall_fn
    fp = fp_2phase
    ht_geom = ${ht_geom}
    alpha_v_min = ${alpha_vapor_min}
    alpha_v_max = ${alpha_vapor_max}
    inclined_angle = 90
    chf_table = chf_table
  [../]
[]

[AuxVariables]
  [./idfr_DispersedBubble]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./idfr_CapSlug]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./idfr_AnnularMist]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./idfr_Stratified]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./idfr_InvertedAnnular]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./idfr_InvertedSlug]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./idfr_DispersedDroplet]
    family = MONOMIAL
    order = CONSTANT
  [../]
[]

[AuxKernels]
  [./idfrm0_aux]
    type = MaterialStdVectorAux
    variable = idfr_DispersedBubble
    property = 'interfacial_drag_flow_regime'
    index = 0
  [../]
  [./idfrm1_aux]
    type = MaterialStdVectorAux
    variable = idfr_CapSlug
    property = 'interfacial_drag_flow_regime'
    index = 1
  [../]
  [./idfrm2_aux]
    type = MaterialStdVectorAux
    variable = idfr_AnnularMist
    property = 'interfacial_drag_flow_regime'
    index = 2
  [../]
  [./idfrm3_aux]
    type = MaterialStdVectorAux
    variable = idfr_Stratified
    property = 'interfacial_drag_flow_regime'
    index = 3
  [../]
  [./idfrm4_aux]
    type = MaterialStdVectorAux
    variable = idfr_InvertedAnnular
    property = 'interfacial_drag_flow_regime'
    index = 4
  [../]
  [./idfrm5_aux]
    type = MaterialStdVectorAux
    variable = idfr_InvertedSlug
    property = 'interfacial_drag_flow_regime'
    index = 5
  [../]
  [./idfrm6_aux]
    type = MaterialStdVectorAux
    variable = idfr_DispersedDroplet
    property = 'interfacial_drag_flow_regime'
    index = 6
  [../]
[]

[Postprocessors]
  [./idfr0_DispersedBubble]
    type = ElementalVariableValue
    variable = idfr_DispersedBubble
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./idfr1_CapSlug]
    type = ElementalVariableValue
    variable = idfr_CapSlug
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./idfr2_AnnularMist]
    type = ElementalVariableValue
    variable = idfr_AnnularMist
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./idfr3_Stratified]
    type = ElementalVariableValue
    variable = idfr_Stratified
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./idfr4_InvertedAnnular]
    type = ElementalVariableValue
    variable = idfr_InvertedAnnular
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./idfr5_InvertedSlug]
    type = ElementalVariableValue
    variable = idfr_InvertedSlug
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./idfr6_DispersedDroplet]
    type = ElementalVariableValue
    variable = idfr_DispersedDroplet
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
[]

[Outputs]
  csv = true
[]
