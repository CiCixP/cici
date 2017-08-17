horizontal = false
ht_geom = PIPE
# alpha_vapor limits
alpha_vapor_min = 0.0001
alpha_vapor_max = 0.9999

[ClosureTest2Phase]
  A = 1e-4
  D_h = 2e-5

  # volume fraction
  alpha_vapor = 0.83
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
    value = 0
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
  [./iht_DispersedBubble]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./iht_CapSlug]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./iht_AnnularMist]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./iht_Stratified]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./iht_InvertedAnnular]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./iht_InvertedSlug]
    family = MONOMIAL
    order = CONSTANT
  [../]
  [./iht_DispersedDroplet]
    family = MONOMIAL
    order = CONSTANT
  [../]
[]

[AuxKernels]
  [./iht0_aux]
    type = MaterialStdVectorAux
    variable = iht_DispersedBubble
    property = 'interfacial_heat_transfer_flow_regime'
    index = 0
  [../]
  [./iht1_aux]
    type = MaterialStdVectorAux
    variable = iht_CapSlug
    property = 'interfacial_heat_transfer_flow_regime'
    index = 1
  [../]
  [./iht2_aux]
    type = MaterialStdVectorAux
    variable = iht_AnnularMist
    property = 'interfacial_heat_transfer_flow_regime'
    index = 2
  [../]
  [./iht3_aux]
    type = MaterialStdVectorAux
    variable = iht_Stratified
    property = 'interfacial_heat_transfer_flow_regime'
    index = 3
  [../]
  [./iht4_aux]
    type = MaterialStdVectorAux
    variable = iht_InvertedAnnular
    property = 'interfacial_heat_transfer_flow_regime'
    index = 4
  [../]
  [./iht5_aux]
    type = MaterialStdVectorAux
    variable = iht_InvertedSlug
    property = 'interfacial_heat_transfer_flow_regime'
    index = 5
  [../]
  [./iht6_aux]
    type = MaterialStdVectorAux
    variable = iht_DispersedDroplet
    property = 'interfacial_heat_transfer_flow_regime'
    index = 6
  [../]
[]

[Postprocessors]
  [./iht0_DispersedBubble]
    type = ElementalVariableValue
    variable = iht_DispersedBubble
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./iht1_CapSlug]
    type = ElementalVariableValue
    variable = iht_CapSlug
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./iht2_AnnularMist]
    type = ElementalVariableValue
    variable = iht_AnnularMist
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./iht3_Stratified]
    type = ElementalVariableValue
    variable = iht_Stratified
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./iht4_InvertedAnnular]
    type = ElementalVariableValue
    variable = iht_InvertedAnnular
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./iht5_InvertedSlug]
    type = ElementalVariableValue
    variable = iht_InvertedSlug
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
  [./iht6_DispersedDroplet]
    type = ElementalVariableValue
    variable = iht_DispersedDroplet
    elementid = 0
    execute_on = 'initial timestep_end'
  [../]
[]

[Outputs]
  csv = true
[]
