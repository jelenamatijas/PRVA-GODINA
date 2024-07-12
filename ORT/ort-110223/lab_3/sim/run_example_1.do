if [file exists "work"] {vdel -all}
vlib work

vlog +acc -incr -f ./lists/example_1_src_vlog.filelist

vlog -sv +acc -incr -define __EXAMPLE_1__ -f ./lists/tb.filelist

vsim top -t 1ps -displaymsgmode both -debugDB -lib work -do "onbreak {resume};  log /* -r; \
    add wave -position end  sim:/top/logic_gate_inst/example_1_gate_inst/i_A; \
    add wave -position end  sim:/top/logic_gate_inst/example_1_gate_inst/i_B; \
    add wave -position end  sim:/top/logic_gate_inst/example_1_gate_inst/i_C; \
    add wave -position end  sim:/top/logic_gate_inst/example_1_gate_inst/i_D; \
    add wave -position end  sim:/top/logic_gate_inst/example_1_gate_inst/o_Y; \
    run -all; quit" -wlf top.wlf -l top.log 
