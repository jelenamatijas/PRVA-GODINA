@echo off
git config --global --replace-all user.name "Jelena Matijaš"
git config --global --replace-all user.email jelena.matijas@student.etf.unibl.org
git config --global --list
echo "==============================================================================="
set PATH=%PATH%;"C:\intelFPGA_lite\20.1\modelsim_ase\win32aloem\"
vsim -version
echo "==============================================================================="
