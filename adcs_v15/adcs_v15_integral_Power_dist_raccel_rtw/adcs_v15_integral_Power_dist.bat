@echo off
set MATLAB=C:\Program Files (x86)\MATLAB\R2009b
"%MATLAB%\bin\win32\gmake" -f adcs_v15_integral_Power_dist.mk  GENERATE_REPORT=0 RSIM_SOLVER_SELECTION=2
