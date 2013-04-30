  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtP)
    ;%
      section.nData     = 154;
      section.data(154)  = dumData; %prealloc
      
	  ;% rtP.Integrator_IC
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtP.RandomNumber_Mean
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 7;
	
	  ;% rtP.RandomNumber_StdDev
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 8;
	
	  ;% rtP.RandomNumber_Seed
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 9;
	
	  ;% rtP.MatrixGain_Gain
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 10;
	
	  ;% rtP.Constant_Value
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 11;
	
	  ;% rtP.Gain_Gain
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
	  ;% rtP.Constant_Value_o
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 13;
	
	  ;% rtP.Constant_Value_j
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 14;
	
	  ;% rtP.Saturation_UpperSat
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 17;
	
	  ;% rtP.Saturation_LowerSat
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 18;
	
	  ;% rtP.Gain_Gain_f
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 19;
	
	  ;% rtP.RandomNumber_Mean_l
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 20;
	
	  ;% rtP.RandomNumber_StdDev_l
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 21;
	
	  ;% rtP.RandomNumber_Seed_i
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 22;
	
	  ;% rtP.MatrixGain_Gain_f
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 23;
	
	  ;% rtP.Constant_Value_jh
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 24;
	
	  ;% rtP.ADC_Interval
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% rtP.Constant_Value_od
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 26;
	
	  ;% rtP.Saturation_UpperSat_e
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 29;
	
	  ;% rtP.Saturation_LowerSat_a
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 30;
	
	  ;% rtP.Gain_Gain_fy
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 31;
	
	  ;% rtP.RandomNumber_Mean_m
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 32;
	
	  ;% rtP.RandomNumber_StdDev_k
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 33;
	
	  ;% rtP.RandomNumber_Seed_f
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 34;
	
	  ;% rtP.MatrixGain_Gain_o
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 35;
	
	  ;% rtP.Constant_Value_k
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 36;
	
	  ;% rtP.ADC_Interval_h
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 37;
	
	  ;% rtP.Constant_Value_os
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 38;
	
	  ;% rtP.Saturation_UpperSat_k
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 41;
	
	  ;% rtP.Saturation_LowerSat_h
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 42;
	
	  ;% rtP.Gain_Gain_a
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 43;
	
	  ;% rtP.RandomNumber_Mean_i
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 44;
	
	  ;% rtP.RandomNumber_StdDev_g
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 45;
	
	  ;% rtP.RandomNumber_Seed_k
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 46;
	
	  ;% rtP.MatrixGain_Gain_h
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 47;
	
	  ;% rtP.Constant_Value_jd
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 48;
	
	  ;% rtP.ADC_Interval_a
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 49;
	
	  ;% rtP.Constant_Value_b
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 50;
	
	  ;% rtP.Saturation_UpperSat_h
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 53;
	
	  ;% rtP.Saturation_LowerSat_l
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 54;
	
	  ;% rtP.Gain_Gain_k
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 55;
	
	  ;% rtP.RandomNumber_Mean_lt
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 56;
	
	  ;% rtP.RandomNumber_StdDev_c
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 57;
	
	  ;% rtP.RandomNumber_Seed_b
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 58;
	
	  ;% rtP.MatrixGain_Gain_k
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 59;
	
	  ;% rtP.Constant_Value_i
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 60;
	
	  ;% rtP.ADC_Interval_b
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 61;
	
	  ;% rtP.Constant_Value_l
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 62;
	
	  ;% rtP.Saturation_UpperSat_c
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 65;
	
	  ;% rtP.Saturation_LowerSat_e
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 66;
	
	  ;% rtP.Gain_Gain_e
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 67;
	
	  ;% rtP.RandomNumber_Mean_j
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 68;
	
	  ;% rtP.RandomNumber_StdDev_i
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 69;
	
	  ;% rtP.RandomNumber_Seed_e
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 70;
	
	  ;% rtP.MatrixGain_Gain_m
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 71;
	
	  ;% rtP.Constant_Value_c
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 72;
	
	  ;% rtP.ADC_Interval_k
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 73;
	
	  ;% rtP.Constant_Value_e
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 74;
	
	  ;% rtP.Saturation_UpperSat_ck
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 77;
	
	  ;% rtP.Saturation_LowerSat_c
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 78;
	
	  ;% rtP.Gain_Gain_fg
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 79;
	
	  ;% rtP.RandomNumber_Mean_n
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 80;
	
	  ;% rtP.RandomNumber_StdDev_n
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 81;
	
	  ;% rtP.RandomNumber_Seed_e2
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 82;
	
	  ;% rtP.MatrixGain_Gain_j
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 83;
	
	  ;% rtP.Constant_Value_d
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 84;
	
	  ;% rtP.ADC_Interval_hc
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 85;
	
	  ;% rtP.Constant_Value_oe
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 86;
	
	  ;% rtP.Gain_Gain_j
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 89;
	
	  ;% rtP.TmpRTBAtProductInport2_X0
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 90;
	
	  ;% rtP.SineWave_Amp
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 91;
	
	  ;% rtP.SineWave_Bias
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 92;
	
	  ;% rtP.SineWave_Freq
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 93;
	
	  ;% rtP.SineWave_Phase
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 94;
	
	  ;% rtP.SineWave1_Amp
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 95;
	
	  ;% rtP.SineWave1_Bias
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 96;
	
	  ;% rtP.SineWave1_Freq
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 97;
	
	  ;% rtP.SineWave1_Phase
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 98;
	
	  ;% rtP.SineWave2_Amp
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 99;
	
	  ;% rtP.SineWave2_Bias
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 100;
	
	  ;% rtP.SineWave2_Freq
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 101;
	
	  ;% rtP.SineWave2_Phase
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 102;
	
	  ;% rtP.Constant_Value_km
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 103;
	
	  ;% rtP.VectorfromCoMtoCoP_inBodyframeyettobefinalized2_Value
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 104;
	
	  ;% rtP.PWM_Interval
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 107;
	
	  ;% rtP.Gain2_Gain
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 108;
	
	  ;% rtP.Constant_Value_eb
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 109;
	
	  ;% rtP.Saturation_UpperSat_es
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 112;
	
	  ;% rtP.Saturation_LowerSat_cn
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 113;
	
	  ;% rtP.Gain1_Gain
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 114;
	
	  ;% rtP.Gain_Gain_l
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 115;
	
	  ;% rtP.Constant_Value_lz
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 116;
	
	  ;% rtP.Saturation_UpperSat_d
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 119;
	
	  ;% rtP.Saturation_LowerSat_i
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 120;
	
	  ;% rtP.Gain1_Gain_m
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 121;
	
	  ;% rtP.Gain_Gain_p
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 122;
	
	  ;% rtP.Constant_Value_n
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 123;
	
	  ;% rtP.Saturation_UpperSat_b
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 126;
	
	  ;% rtP.Saturation_LowerSat_lu
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 127;
	
	  ;% rtP.Gain1_Gain_l
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 128;
	
	  ;% rtP.Gain_Gain_h
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 129;
	
	  ;% rtP.Constant_Value_f
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 130;
	
	  ;% rtP.Saturation_UpperSat_hv
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 133;
	
	  ;% rtP.Saturation_LowerSat_b
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 134;
	
	  ;% rtP.Gain1_Gain_e
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 135;
	
	  ;% rtP.Gain_Gain_lg
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 136;
	
	  ;% rtP.Constant_Value_ebv
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 137;
	
	  ;% rtP.Saturation_UpperSat_dg
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 140;
	
	  ;% rtP.Saturation_LowerSat_k
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 141;
	
	  ;% rtP.Gain1_Gain_o
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 142;
	
	  ;% rtP.Gain_Gain_n
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 143;
	
	  ;% rtP.Constant_Value_dm
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 144;
	
	  ;% rtP.Saturation_UpperSat_du
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 147;
	
	  ;% rtP.Saturation_LowerSat_d
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 148;
	
	  ;% rtP.Gain1_Gain_j
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 149;
	
	  ;% rtP.Gain_Gain_g
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 150;
	
	  ;% rtP.Gain1_Gain_oy
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 151;
	
	  ;% rtP.IntegerDelay_InitialCondition
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 152;
	
	  ;% rtP.PowerDistributionLosses_Value
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 153;
	
	  ;% rtP.Magnetometer_Value
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 154;
	
	  ;% rtP.TmpRTBAtAddingPowerConsumedInport3_X0
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 155;
	
	  ;% rtP.Uplink_Value
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 156;
	
	  ;% rtP.Beaconandamplifier_Value
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 157;
	
	  ;% rtP.OBC_Value
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 158;
	
	  ;% rtP.SunSensor_Value
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 159;
	
	  ;% rtP.Gain2_Gain_m
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 160;
	
	  ;% rtP.IntegerDelay3_InitialCondition
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 161;
	
	  ;% rtP.IntegerDelay2_InitialCondition
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 162;
	
	  ;% rtP.IntegerDelay1_InitialCondition
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 163;
	
	  ;% rtP.IntegerDelay4_InitialCondition
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 164;
	
	  ;% rtP.VoltageofMagnetorquer_Gain
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 165;
	
	  ;% rtP.Integrator_IC_b
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 166;
	
	  ;% rtP.SFunction_p2
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 167;
	
	  ;% rtP.SFunction_p4
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 176;
	
	  ;% rtP.IntegerDelay_InitialCondition_p
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 177;
	
	  ;% rtP.UnitDelay1_X0
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 178;
	
	  ;% rtP.UnitDelay1_X0_n
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 181;
	
	  ;% rtP.UnitDelay_X0
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 182;
	
	  ;% rtP.Switch_Threshold
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 183;
	
	  ;% rtP.MomentSaturation_UpperSat
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 184;
	
	  ;% rtP.MomentSaturation_LowerSat
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 185;
	
	  ;% rtP.Gain1_Gain_d
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 186;
	
	  ;% rtP.PowerSaturation_UpperSat
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 187;
	
	  ;% rtP.PowerSaturation_LowerSat
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 188;
	
	  ;% rtP.TorquerCurrentSaturation_UpperSat
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 189;
	
	  ;% rtP.TorquerCurrentSaturation_LowerSat
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 190;
	
	  ;% rtP.SFunction_p1
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 191;
	
	  ;% rtP.SFunction_p1_e
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 192;
	
	  ;% rtP.SFunction_p4_b
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 193;
	
	  ;% rtP.SFunction_p2_j
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 194;
	
	  ;% rtP.IntegerDelay1_InitialCondition_f
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 195;
	
	  ;% rtP.IntegerDelay_InitialCondition_l
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 198;
	
	  ;% rtP.IntegerDelay_InitialCondition_f
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 199;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtB)
    ;%
      section.nData     = 181;
      section.data(181)  = dumData; %prealloc
      
	  ;% rtB.Integrator
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtB.FromFile
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 7;
	
	  ;% rtB.TmpRTBAtScope1Inport1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 13;
	
	  ;% rtB.Sum
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 17;
	
	  ;% rtB.Buffer
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 18;
	
	  ;% rtB.Gain
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 19;
	
	  ;% rtB.Constant
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 22;
	
	  ;% rtB.Sum1
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 23;
	
	  ;% rtB.TmpRTBAtQuESTInport1
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 26;
	
	  ;% rtB.Constant_m
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 29;
	
	  ;% rtB.FromFile_l
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 32;
	
	  ;% rtB.FromFile2
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 35;
	
	  ;% rtB.Sum_l
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 36;
	
	  ;% rtB.Buffer_b
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 37;
	
	  ;% rtB.ADC
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 38;
	
	  ;% rtB.Constant_b
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 39;
	
	  ;% rtB.Sum_c
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 42;
	
	  ;% rtB.Buffer_o
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 43;
	
	  ;% rtB.ADC_l
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 44;
	
	  ;% rtB.Constant_e
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 45;
	
	  ;% rtB.Sum_e
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 48;
	
	  ;% rtB.Buffer_m
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 49;
	
	  ;% rtB.ADC_h
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 50;
	
	  ;% rtB.Constant_k
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 51;
	
	  ;% rtB.Sum_h
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 54;
	
	  ;% rtB.Buffer_c
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 55;
	
	  ;% rtB.ADC_hj
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 56;
	
	  ;% rtB.Constant_o
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 57;
	
	  ;% rtB.Sum_a
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 60;
	
	  ;% rtB.Buffer_g
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 61;
	
	  ;% rtB.ADC_j
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 62;
	
	  ;% rtB.Constant_mx
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 63;
	
	  ;% rtB.Sum_k
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 66;
	
	  ;% rtB.Buffer_d
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 67;
	
	  ;% rtB.ADC_o
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 68;
	
	  ;% rtB.TmpRTBAtQuESTInport2
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 69;
	
	  ;% rtB.TmpRTBAtScope10Inport1
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 99;
	
	  ;% rtB.TmpRTBAtScope2Inport1
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 100;
	
	  ;% rtB.TmpRTBAtScope3Inport1
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 103;
	
	  ;% rtB.TmpRTBAtScope4Inport1
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 106;
	
	  ;% rtB.TmpRTBAtScope5Inport1
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 107;
	
	  ;% rtB.TmpRTBAtControlLawInport1
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 110;
	
	  ;% rtB.Clock1
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 113;
	
	  ;% rtB.TmpRTBAtScope6Inport1
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 114;
	
	  ;% rtB.TmpRTBAtScope9Inport1
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 115;
	
	  ;% rtB.TmpRTBAtToWorkspace10Inport1
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 118;
	
	  ;% rtB.TmpRTBAtToWorkspace11Inport1
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 121;
	
	  ;% rtB.TmpRTBAtToWorkspace12Inport1
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 124;
	
	  ;% rtB.TmpRTBAtToWorkspace13Inport1
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 127;
	
	  ;% rtB.TmpRTBAtToWorkspace16Inport1
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 130;
	
	  ;% rtB.TmpRTBAtToWorkspace17Inport1
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 133;
	
	  ;% rtB.TmpRTBAtToWorkspace18Inport1
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 137;
	
	  ;% rtB.TmpRTBAtToWorkspace19Inport1
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 138;
	
	  ;% rtB.TmpRTBAtToWorkspace2Inport1
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 141;
	
	  ;% rtB.TmpRTBAtToWorkspace20Inport1
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 142;
	
	  ;% rtB.TmpRTBAtToWorkspace4Inport1
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 145;
	
	  ;% rtB.TmpRTBAtToWorkspace8Inport1
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 148;
	
	  ;% rtB.Gain_i
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 151;
	
	  ;% rtB.TmpRTBAtProductInport2
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 154;
	
	  ;% rtB.Sum_m
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 157;
	
	  ;% rtB.TmpRTBAtToWorkspace9Inport1
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 160;
	
	  ;% rtB.Sum_h1
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 163;
	
	  ;% rtB.TmpRTBAtw_real1Inport1
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 166;
	
	  ;% rtB.Constant_i
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 169;
	
	  ;% rtB.VectorfromCoMtoCoP_inBodyframeyettobefinalized2
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 170;
	
	  ;% rtB.Sum_p
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 173;
	
	  ;% rtB.Sum_e1
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 176;
	
	  ;% rtB.TmpRTBAtw_real2Inport1
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 179;
	
	  ;% rtB.TmpRTBAtw_real3Inport1
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 182;
	
	  ;% rtB.TmpRTBAtw_real4Inport1
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 185;
	
	  ;% rtB.Gain2
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 188;
	
	  ;% rtB.Clock
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 191;
	
	  ;% rtB.TmpRTBAtToWorkspace15Inport1
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 192;
	
	  ;% rtB.Constant_g
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 193;
	
	  ;% rtB.Gain_f
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 196;
	
	  ;% rtB.Constant_a
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 197;
	
	  ;% rtB.Gain_d
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 200;
	
	  ;% rtB.Constant_j
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 201;
	
	  ;% rtB.Gain_it
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 204;
	
	  ;% rtB.Constant_h
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 205;
	
	  ;% rtB.Gain_g
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 208;
	
	  ;% rtB.Constant_a0
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 209;
	
	  ;% rtB.Gain_p
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 212;
	
	  ;% rtB.Constant_mg
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 213;
	
	  ;% rtB.Gain_o
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 216;
	
	  ;% rtB.TmpRTBAtScope11Inport1
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 217;
	
	  ;% rtB.Gain1
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 223;
	
	  ;% rtB.TmpRTBAtScope12Inport1
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 229;
	
	  ;% rtB.AddingSolarPower
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 235;
	
	  ;% rtB.IntegerDelay
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 236;
	
	  ;% rtB.PowerDistributionLosses
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 237;
	
	  ;% rtB.Magnetometer
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 238;
	
	  ;% rtB.TmpRTBAtAddingPowerConsumedInport3
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 239;
	
	  ;% rtB.Uplink
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 240;
	
	  ;% rtB.Beaconandamplifier
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 241;
	
	  ;% rtB.OBC
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 242;
	
	  ;% rtB.SunSensor
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 243;
	
	  ;% rtB.Clock2
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 244;
	
	  ;% rtB.AddingPowerConsumed
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 245;
	
	  ;% rtB.AddingSolarPower1
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 246;
	
	  ;% rtB.Gain2_h
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 247;
	
	  ;% rtB.TmpRTBAtScope13Inport1
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 248;
	
	  ;% rtB.TmpRTBAtScope14Inport1
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 249;
	
	  ;% rtB.Clock_o
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 250;
	
	  ;% rtB.IntegerDelay3
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 251;
	
	  ;% rtB.IntegerDelay2
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 252;
	
	  ;% rtB.IntegerDelay1
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 253;
	
	  ;% rtB.IntegerDelay4
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 254;
	
	  ;% rtB.TmpRTBAtScope15Inport1
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 255;
	
	  ;% rtB.TmpRTBAtScope16Inport1
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 256;
	
	  ;% rtB.TmpRTBAtScope17Inport1
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 257;
	
	  ;% rtB.TmpRTBAtScope18Inport1
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 258;
	
	  ;% rtB.TmpRTBAtScope19Inport1
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 259;
	
	  ;% rtB.TmpRTBAtScope20Inport1
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 260;
	
	  ;% rtB.VoltageofMagnetorquer
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 261;
	
	  ;% rtB.Integrator_c
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 262;
	
	  ;% rtB.xN
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 263;
	
	  ;% rtB.IntegerDelay1_a
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 270;
	
	  ;% rtB.IntegerDelay_g
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 273;
	
	  ;% rtB.IntegerDelay_i
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 277;
	
	  ;% rtB.Product
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 278;
	
	  ;% rtB.w_l
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 281;
	
	  ;% rtB.w
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 284;
	
	  ;% rtB.y
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 287;
	
	  ;% rtB.DCM
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 288;
	
	  ;% rtB.v_B
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 297;
	
	  ;% rtB.m_SUN
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 300;
	
	  ;% rtB.values
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 330;
	
	  ;% rtB.FromFile_e
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 336;
	
	  ;% rtB.FromFile2_o
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 339;
	
	  ;% rtB.FromFile3
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 345;
	
	  ;% rtB.v_O
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 348;
	
	  ;% rtB.v_O_g
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 351;
	
	  ;% rtB.q_BO_est
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 354;
	
	  ;% rtB.light_est
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 358;
	
	  ;% rtB.v_Sun1
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 359;
	
	  ;% rtB.r_ECEF
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 362;
	
	  ;% rtB.Latitutde
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 365;
	
	  ;% rtB.Longitude
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 366;
	
	  ;% rtB.Altitude
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 367;
	
	  ;% rtB.Batt_cap
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 368;
	
	  ;% rtB.VBat
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 369;
	
	  ;% rtB.Flag_charge
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 370;
	
	  ;% rtB.frac_Batt_cap
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 371;
	
	  ;% rtB.Flag_discharge
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 372;
	
	  ;% rtB.current
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 373;
	
	  ;% rtB.pow_drawn
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 374;
	
	  ;% rtB.Downlink_power
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 375;
	
	  ;% rtB.flag_downlink
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 376;
	
	  ;% rtB.flag_france
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 377;
	
	  ;% rtB.flag_india
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 378;
	
	  ;% rtB.v_B_j
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 379;
	
	  ;% rtB.solar_drag
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 382;
	
	  ;% rtB.tau
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 385;
	
	  ;% rtB.v_B_d
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 388;
	
	  ;% rtB.u_aero
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 391;
	
	  ;% rtB.euler
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 394;
	
	  ;% rtB.q_BO
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 397;
	
	  ;% rtB.w_BOB
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 401;
	
	  ;% rtB.modw
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 404;
	
	  ;% rtB.w_BIB
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 405;
	
	  ;% rtB.xdot
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 408;
	
	  ;% rtB.Fcn
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 415;
	
	  ;% rtB.IntegerDelay_n
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 416;
	
	  ;% rtB.UnitDelay1
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 419;
	
	  ;% rtB.UnitDelay1_b
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 422;
	
	  ;% rtB.TmpRTBAtgatepulseInport4
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 423;
	
	  ;% rtB.UnitDelay
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 424;
	
	  ;% rtB.TmpRTBAteuInport1
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 425;
	
	  ;% rtB.TmpRTBAtmInport1
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 428;
	
	  ;% rtB.TorquerCurrentSaturation
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 431;
	
	  ;% rtB.B
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 434;
	
	  ;% rtB.dB
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 437;
	
	  ;% rtB.N
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 440;
	
	  ;% rtB.P
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 441;
	
	  ;% rtB.t_now
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 444;
	
	  ;% rtB.ieu
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 445;
	
	  ;% rtB.eu
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 448;
	
	  ;% rtB.m
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 451;
	
	  ;% rtB.m_N
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 454;
	
	  ;% rtB.m_D
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 457;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 6;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (rtDWork)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% rtDWork.IntegerDelay_X
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.IntegerDelay3_X
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.IntegerDelay2_X
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.IntegerDelay1_X
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDWork.IntegerDelay4_X
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDWork.IntegerDelay1_X_k
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDWork.IntegerDelay_X_g
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 8;
	
	  ;% rtDWork.IntegerDelay_X_l
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 12;
	
	  ;% rtDWork.IntegerDelay_X_a
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 312;
	
	  ;% rtDWork.UnitDelay1_DSTATE
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 315;
	
	  ;% rtDWork.UnitDelay1_DSTATE_m
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 318;
	
	  ;% rtDWork.UnitDelay_DSTATE
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 319;
	
	  ;% rtDWork.NextOutput
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 320;
	
	  ;% rtDWork.NextOutput_l
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 321;
	
	  ;% rtDWork.NextOutput_n
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 322;
	
	  ;% rtDWork.NextOutput_m
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 323;
	
	  ;% rtDWork.NextOutput_n1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 324;
	
	  ;% rtDWork.NextOutput_ma
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 325;
	
	  ;% rtDWork.NextOutput_d
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 326;
	
	  ;% rtDWork.TmpRTBAtProductInport2_Buffer0
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 327;
	
	  ;% rtDWork.TmpRTBAtAddingPowerConsumedInport3_Buffer0
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 330;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 70;
      section.data(70)  = dumData; %prealloc
      
	  ;% rtDWork.FromFile_PWORK.PrevTimePtr
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.FromFile1_PWORK.PrevTimePtr
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.FromFile_PWORK_g.PrevTimePtr
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDWork.FromFile2_PWORK.PrevTimePtr
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDWork.Scope10_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDWork.Scope2_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDWork.Scope3_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDWork.Scope4_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDWork.Scope5_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDWork.Scope6_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDWork.Scope7_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDWork.Scope8_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 33;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDWork.Scope9_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 34;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDWork.ToWorkspace1_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 35;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDWork.ToWorkspace10_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 36;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDWork.ToWorkspace11_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 37;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDWork.ToWorkspace12_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 38;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDWork.ToWorkspace13_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 39;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDWork.ToWorkspace14_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 40;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDWork.ToWorkspace16_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 41;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDWork.ToWorkspace17_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 42;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDWork.ToWorkspace18_PWORK.LoggedData
	  section.data(23).logicalSrcIdx = 43;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDWork.ToWorkspace19_PWORK.LoggedData
	  section.data(24).logicalSrcIdx = 44;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDWork.ToWorkspace2_PWORK.LoggedData
	  section.data(25).logicalSrcIdx = 45;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDWork.ToWorkspace20_PWORK.LoggedData
	  section.data(26).logicalSrcIdx = 46;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDWork.ToWorkspace3_PWORK.LoggedData
	  section.data(27).logicalSrcIdx = 47;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDWork.ToWorkspace4_PWORK.LoggedData
	  section.data(28).logicalSrcIdx = 48;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDWork.ToWorkspace5_PWORK.LoggedData
	  section.data(29).logicalSrcIdx = 49;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDWork.ToWorkspace6_PWORK.LoggedData
	  section.data(30).logicalSrcIdx = 50;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtDWork.ToWorkspace7_PWORK.LoggedData
	  section.data(31).logicalSrcIdx = 51;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtDWork.ToWorkspace8_PWORK.LoggedData
	  section.data(32).logicalSrcIdx = 52;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtDWork.ToWorkspace9_PWORK.LoggedData
	  section.data(33).logicalSrcIdx = 53;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtDWork.w_real1_PWORK.LoggedData
	  section.data(34).logicalSrcIdx = 54;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtDWork.w_real2_PWORK.LoggedData
	  section.data(35).logicalSrcIdx = 55;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtDWork.w_real3_PWORK.LoggedData
	  section.data(36).logicalSrcIdx = 56;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtDWork.w_real4_PWORK.LoggedData
	  section.data(37).logicalSrcIdx = 57;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtDWork.ToWorkspace15_PWORK.LoggedData
	  section.data(38).logicalSrcIdx = 58;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtDWork.Scope11_PWORK.LoggedData
	  section.data(39).logicalSrcIdx = 59;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtDWork.Scope12_PWORK.LoggedData
	  section.data(40).logicalSrcIdx = 60;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtDWork.Scope13_PWORK.LoggedData
	  section.data(41).logicalSrcIdx = 61;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtDWork.Scope14_PWORK.LoggedData
	  section.data(42).logicalSrcIdx = 62;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtDWork.Scope15_PWORK.LoggedData
	  section.data(43).logicalSrcIdx = 63;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtDWork.Scope16_PWORK.LoggedData
	  section.data(44).logicalSrcIdx = 64;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtDWork.Scope17_PWORK.LoggedData
	  section.data(45).logicalSrcIdx = 65;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtDWork.Scope18_PWORK.LoggedData
	  section.data(46).logicalSrcIdx = 66;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtDWork.Scope19_PWORK.LoggedData
	  section.data(47).logicalSrcIdx = 67;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtDWork.Scope20_PWORK.LoggedData
	  section.data(48).logicalSrcIdx = 68;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtDWork.ToFile_PWORK.FilePtr
	  section.data(49).logicalSrcIdx = 69;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtDWork.ToFile1_PWORK.FilePtr
	  section.data(50).logicalSrcIdx = 70;
	  section.data(50).dtTransOffset = 49;
	
	  ;% rtDWork.ToFile2_PWORK.FilePtr
	  section.data(51).logicalSrcIdx = 71;
	  section.data(51).dtTransOffset = 50;
	
	  ;% rtDWork.ToFile3_PWORK.FilePtr
	  section.data(52).logicalSrcIdx = 72;
	  section.data(52).dtTransOffset = 51;
	
	  ;% rtDWork.ToFile4_PWORK.FilePtr
	  section.data(53).logicalSrcIdx = 73;
	  section.data(53).dtTransOffset = 52;
	
	  ;% rtDWork.Scope_PWORK.LoggedData
	  section.data(54).logicalSrcIdx = 74;
	  section.data(54).dtTransOffset = 53;
	
	  ;% rtDWork.Scope1_PWORK_l.LoggedData
	  section.data(55).logicalSrcIdx = 75;
	  section.data(55).dtTransOffset = 54;
	
	  ;% rtDWork.Scope2_PWORK_g.LoggedData
	  section.data(56).logicalSrcIdx = 76;
	  section.data(56).dtTransOffset = 55;
	
	  ;% rtDWork.Scope_PWORK_o.LoggedData
	  section.data(57).logicalSrcIdx = 77;
	  section.data(57).dtTransOffset = 56;
	
	  ;% rtDWork.Scope1_PWORK_g.LoggedData
	  section.data(58).logicalSrcIdx = 78;
	  section.data(58).dtTransOffset = 57;
	
	  ;% rtDWork.Scope1_PWORK_e.LoggedData
	  section.data(59).logicalSrcIdx = 79;
	  section.data(59).dtTransOffset = 58;
	
	  ;% rtDWork.Scope2_PWORK_p.LoggedData
	  section.data(60).logicalSrcIdx = 80;
	  section.data(60).dtTransOffset = 59;
	
	  ;% rtDWork.Scope3_PWORK_i.LoggedData
	  section.data(61).logicalSrcIdx = 81;
	  section.data(61).dtTransOffset = 60;
	
	  ;% rtDWork.Scope6_PWORK_h.LoggedData
	  section.data(62).logicalSrcIdx = 82;
	  section.data(62).dtTransOffset = 61;
	
	  ;% rtDWork.Scope_PWORK_p.LoggedData
	  section.data(63).logicalSrcIdx = 83;
	  section.data(63).dtTransOffset = 62;
	
	  ;% rtDWork.Scope1_PWORK_h.LoggedData
	  section.data(64).logicalSrcIdx = 84;
	  section.data(64).dtTransOffset = 63;
	
	  ;% rtDWork.Scope2_PWORK_c.LoggedData
	  section.data(65).logicalSrcIdx = 85;
	  section.data(65).dtTransOffset = 64;
	
	  ;% rtDWork.FromFile_PWORK_b.PrevTimePtr
	  section.data(66).logicalSrcIdx = 86;
	  section.data(66).dtTransOffset = 65;
	
	  ;% rtDWork.FromFile2_PWORK_c.PrevTimePtr
	  section.data(67).logicalSrcIdx = 87;
	  section.data(67).dtTransOffset = 66;
	
	  ;% rtDWork.FromFile3_PWORK.PrevTimePtr
	  section.data(68).logicalSrcIdx = 88;
	  section.data(68).dtTransOffset = 67;
	
	  ;% rtDWork.Scope_PWORK_j.LoggedData
	  section.data(69).logicalSrcIdx = 89;
	  section.data(69).dtTransOffset = 68;
	
	  ;% rtDWork.Scope1_PWORK_j.LoggedData
	  section.data(70).logicalSrcIdx = 90;
	  section.data(70).dtTransOffset = 69;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% rtDWork.RandSeed
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.RandSeed_l
	  section.data(2).logicalSrcIdx = 92;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.RandSeed_g
	  section.data(3).logicalSrcIdx = 93;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.RandSeed_m
	  section.data(4).logicalSrcIdx = 94;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDWork.RandSeed_le
	  section.data(5).logicalSrcIdx = 95;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDWork.RandSeed_f
	  section.data(6).logicalSrcIdx = 96;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDWork.RandSeed_o
	  section.data(7).logicalSrcIdx = 97;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% rtDWork.ToFile_IWORK.Count
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.ToFile1_IWORK.Count
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.ToFile2_IWORK.Count
	  section.data(3).logicalSrcIdx = 100;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.ToFile3_IWORK.Count
	  section.data(4).logicalSrcIdx = 101;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDWork.ToFile4_IWORK.Count
	  section.data(5).logicalSrcIdx = 102;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 25;
      section.data(25)  = dumData; %prealloc
      
	  ;% rtDWork.is_active_c7_adcs_v15_integral_Power_dist
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.is_active_c27_adcs_v15_integral_Power_dist
	  section.data(2).logicalSrcIdx = 104;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.is_active_c6_adcs_v15_integral_Power_dist
	  section.data(3).logicalSrcIdx = 105;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.is_active_c1_adcs_v15_integral_Power_dist
	  section.data(4).logicalSrcIdx = 106;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDWork.is_active_c4_adcs_v15_integral_Power_dist
	  section.data(5).logicalSrcIdx = 107;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDWork.is_active_c22_adcs_v15_integral_Power_dist
	  section.data(6).logicalSrcIdx = 108;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDWork.is_active_c12_adcs_v15_integral_Power_dist
	  section.data(7).logicalSrcIdx = 109;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDWork.is_active_c25_adcs_v15_integral_Power_dist
	  section.data(8).logicalSrcIdx = 110;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDWork.is_active_c11_adcs_v15_integral_Power_dist
	  section.data(9).logicalSrcIdx = 111;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDWork.is_active_c30_adcs_v15_integral_Power_dist
	  section.data(10).logicalSrcIdx = 112;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDWork.is_active_c28_adcs_v15_integral_Power_dist
	  section.data(11).logicalSrcIdx = 113;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDWork.is_active_c26_adcs_v15_integral_Power_dist
	  section.data(12).logicalSrcIdx = 114;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDWork.is_active_c31_adcs_v15_integral_Power_dist
	  section.data(13).logicalSrcIdx = 115;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDWork.is_active_c19_adcs_v15_integral_Power_dist
	  section.data(14).logicalSrcIdx = 116;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDWork.is_active_c5_adcs_v15_integral_Power_dist
	  section.data(15).logicalSrcIdx = 117;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDWork.is_active_c8_adcs_v15_integral_Power_dist
	  section.data(16).logicalSrcIdx = 118;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDWork.is_active_c9_adcs_v15_integral_Power_dist
	  section.data(17).logicalSrcIdx = 119;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDWork.is_active_c20_adcs_v15_integral_Power_dist
	  section.data(18).logicalSrcIdx = 120;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDWork.is_active_c16_adcs_v15_integral_Power_dist
	  section.data(19).logicalSrcIdx = 121;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDWork.is_active_c29_adcs_v15_integral_Power_dist
	  section.data(20).logicalSrcIdx = 122;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDWork.is_active_c2_adcs_v15_integral_Power_dist
	  section.data(21).logicalSrcIdx = 123;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDWork.is_active_c10_adcs_v15_integral_Power_dist
	  section.data(22).logicalSrcIdx = 124;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDWork.is_active_c24_adcs_v15_integral_Power_dist
	  section.data(23).logicalSrcIdx = 125;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDWork.is_active_c13_adcs_v15_integral_Power_dist
	  section.data(24).logicalSrcIdx = 126;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDWork.is_active_c23_adcs_v15_integral_Power_dist
	  section.data(25).logicalSrcIdx = 127;
	  section.data(25).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 50;
      section.data(50)  = dumData; %prealloc
      
	  ;% rtDWork.isStable
	  section.data(1).logicalSrcIdx = 128;
	  section.data(1).dtTransOffset = 0;
	
	  ;% rtDWork.doneDoubleBufferReInit
	  section.data(2).logicalSrcIdx = 129;
	  section.data(2).dtTransOffset = 1;
	
	  ;% rtDWork.isStable_h
	  section.data(3).logicalSrcIdx = 130;
	  section.data(3).dtTransOffset = 2;
	
	  ;% rtDWork.doneDoubleBufferReInit_e
	  section.data(4).logicalSrcIdx = 131;
	  section.data(4).dtTransOffset = 3;
	
	  ;% rtDWork.isStable_n
	  section.data(5).logicalSrcIdx = 132;
	  section.data(5).dtTransOffset = 4;
	
	  ;% rtDWork.doneDoubleBufferReInit_h
	  section.data(6).logicalSrcIdx = 133;
	  section.data(6).dtTransOffset = 5;
	
	  ;% rtDWork.isStable_c
	  section.data(7).logicalSrcIdx = 134;
	  section.data(7).dtTransOffset = 6;
	
	  ;% rtDWork.doneDoubleBufferReInit_k
	  section.data(8).logicalSrcIdx = 135;
	  section.data(8).dtTransOffset = 7;
	
	  ;% rtDWork.isStable_a
	  section.data(9).logicalSrcIdx = 136;
	  section.data(9).dtTransOffset = 8;
	
	  ;% rtDWork.doneDoubleBufferReInit_o
	  section.data(10).logicalSrcIdx = 137;
	  section.data(10).dtTransOffset = 9;
	
	  ;% rtDWork.isStable_b
	  section.data(11).logicalSrcIdx = 138;
	  section.data(11).dtTransOffset = 10;
	
	  ;% rtDWork.doneDoubleBufferReInit_g
	  section.data(12).logicalSrcIdx = 139;
	  section.data(12).dtTransOffset = 11;
	
	  ;% rtDWork.isStable_hh
	  section.data(13).logicalSrcIdx = 140;
	  section.data(13).dtTransOffset = 12;
	
	  ;% rtDWork.doneDoubleBufferReInit_kp
	  section.data(14).logicalSrcIdx = 141;
	  section.data(14).dtTransOffset = 13;
	
	  ;% rtDWork.isStable_bw
	  section.data(15).logicalSrcIdx = 142;
	  section.data(15).dtTransOffset = 14;
	
	  ;% rtDWork.doneDoubleBufferReInit_hp
	  section.data(16).logicalSrcIdx = 143;
	  section.data(16).dtTransOffset = 15;
	
	  ;% rtDWork.isStable_nc
	  section.data(17).logicalSrcIdx = 144;
	  section.data(17).dtTransOffset = 16;
	
	  ;% rtDWork.doneDoubleBufferReInit_f
	  section.data(18).logicalSrcIdx = 145;
	  section.data(18).dtTransOffset = 17;
	
	  ;% rtDWork.isStable_ck
	  section.data(19).logicalSrcIdx = 146;
	  section.data(19).dtTransOffset = 18;
	
	  ;% rtDWork.doneDoubleBufferReInit_j
	  section.data(20).logicalSrcIdx = 147;
	  section.data(20).dtTransOffset = 19;
	
	  ;% rtDWork.isStable_o
	  section.data(21).logicalSrcIdx = 148;
	  section.data(21).dtTransOffset = 20;
	
	  ;% rtDWork.doneDoubleBufferReInit_p
	  section.data(22).logicalSrcIdx = 149;
	  section.data(22).dtTransOffset = 21;
	
	  ;% rtDWork.isStable_hr
	  section.data(23).logicalSrcIdx = 150;
	  section.data(23).dtTransOffset = 22;
	
	  ;% rtDWork.doneDoubleBufferReInit_o2
	  section.data(24).logicalSrcIdx = 151;
	  section.data(24).dtTransOffset = 23;
	
	  ;% rtDWork.isStable_ow
	  section.data(25).logicalSrcIdx = 152;
	  section.data(25).dtTransOffset = 24;
	
	  ;% rtDWork.doneDoubleBufferReInit_pg
	  section.data(26).logicalSrcIdx = 153;
	  section.data(26).dtTransOffset = 25;
	
	  ;% rtDWork.isStable_p
	  section.data(27).logicalSrcIdx = 154;
	  section.data(27).dtTransOffset = 26;
	
	  ;% rtDWork.doneDoubleBufferReInit_m
	  section.data(28).logicalSrcIdx = 155;
	  section.data(28).dtTransOffset = 27;
	
	  ;% rtDWork.isStable_n3
	  section.data(29).logicalSrcIdx = 156;
	  section.data(29).dtTransOffset = 28;
	
	  ;% rtDWork.doneDoubleBufferReInit_fx
	  section.data(30).logicalSrcIdx = 157;
	  section.data(30).dtTransOffset = 29;
	
	  ;% rtDWork.isStable_j
	  section.data(31).logicalSrcIdx = 158;
	  section.data(31).dtTransOffset = 30;
	
	  ;% rtDWork.doneDoubleBufferReInit_or
	  section.data(32).logicalSrcIdx = 159;
	  section.data(32).dtTransOffset = 31;
	
	  ;% rtDWork.isStable_p5
	  section.data(33).logicalSrcIdx = 160;
	  section.data(33).dtTransOffset = 32;
	
	  ;% rtDWork.doneDoubleBufferReInit_ea
	  section.data(34).logicalSrcIdx = 161;
	  section.data(34).dtTransOffset = 33;
	
	  ;% rtDWork.isStable_ci
	  section.data(35).logicalSrcIdx = 162;
	  section.data(35).dtTransOffset = 34;
	
	  ;% rtDWork.doneDoubleBufferReInit_b
	  section.data(36).logicalSrcIdx = 163;
	  section.data(36).dtTransOffset = 35;
	
	  ;% rtDWork.isStable_na
	  section.data(37).logicalSrcIdx = 164;
	  section.data(37).dtTransOffset = 36;
	
	  ;% rtDWork.doneDoubleBufferReInit_d
	  section.data(38).logicalSrcIdx = 165;
	  section.data(38).dtTransOffset = 37;
	
	  ;% rtDWork.isStable_cy
	  section.data(39).logicalSrcIdx = 166;
	  section.data(39).dtTransOffset = 38;
	
	  ;% rtDWork.doneDoubleBufferReInit_mo
	  section.data(40).logicalSrcIdx = 167;
	  section.data(40).dtTransOffset = 39;
	
	  ;% rtDWork.isStable_m
	  section.data(41).logicalSrcIdx = 168;
	  section.data(41).dtTransOffset = 40;
	
	  ;% rtDWork.doneDoubleBufferReInit_i
	  section.data(42).logicalSrcIdx = 169;
	  section.data(42).dtTransOffset = 41;
	
	  ;% rtDWork.isStable_je
	  section.data(43).logicalSrcIdx = 170;
	  section.data(43).dtTransOffset = 42;
	
	  ;% rtDWork.doneDoubleBufferReInit_n
	  section.data(44).logicalSrcIdx = 171;
	  section.data(44).dtTransOffset = 43;
	
	  ;% rtDWork.isStable_nf
	  section.data(45).logicalSrcIdx = 172;
	  section.data(45).dtTransOffset = 44;
	
	  ;% rtDWork.doneDoubleBufferReInit_kb
	  section.data(46).logicalSrcIdx = 173;
	  section.data(46).dtTransOffset = 45;
	
	  ;% rtDWork.isStable_cyj
	  section.data(47).logicalSrcIdx = 174;
	  section.data(47).dtTransOffset = 46;
	
	  ;% rtDWork.doneDoubleBufferReInit_pd
	  section.data(48).logicalSrcIdx = 175;
	  section.data(48).dtTransOffset = 47;
	
	  ;% rtDWork.isStable_ca
	  section.data(49).logicalSrcIdx = 176;
	  section.data(49).dtTransOffset = 48;
	
	  ;% rtDWork.doneDoubleBufferReInit_c
	  section.data(50).logicalSrcIdx = 177;
	  section.data(50).dtTransOffset = 49;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 3558220221;
  targMap.checksum1 = 1999991981;
  targMap.checksum2 = 2261420796;
  targMap.checksum3 = 789110634;

