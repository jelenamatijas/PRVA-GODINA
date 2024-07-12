if [file exists "work"] {vdel -all}
vlib work

vlog -sv +acc -incr -f ./lists/task_1_src_vlog.filelist

vlog -sv +acc -incr -define __TASK_1__ -f ./lists/tb.filelist

vsim top -t 1ps -displaymsgmode both -debugDB -lib work -do "onbreak {resume};  log /* -r; \
    add wave -position end  sim:/top/logic_gate_inst/task_1_gate_inst/*; \
    run -all; quit" -wlf top.wlf -l top.log 
