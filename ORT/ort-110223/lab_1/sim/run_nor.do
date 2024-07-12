if [file exists "work"] {vdel -all}
vlib work

vlog +acc -incr -f ./lists/src_vlog.filelist

vlog -sv +acc -incr -define __NOR__ -f ./lists/tb.filelist


vsim top -t 1ps -displaymsgmode both -lib work -do "onbreak {resume};  log /* -r; add wave -position end  sim:/top/logic_gate_inst/nor_gate_inst/i_A; add wave -position end  sim:/top/logic_gate_inst/nor_gate_inst/i_B; add wave -position end  sim:/top/logic_gate_inst/nor_gate_inst/o_Y; run -all; quit" -wlf top.wlf -l top.log 
