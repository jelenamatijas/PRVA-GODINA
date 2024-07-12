set status "" 

if [file exists "work"] {vdel -all}
vlib work

catch "vlog +acc -incr -f ./lists/task_3_src_vlog.filelist" status

if [expr {${status} != ""}] then {
    quit -f;
}

vlog -sv +acc -incr -define __TASK_3__ -f ./lists/tb.filelist


vsim top -t 1ps -displaymsgmode both -lib work -do "onbreak {resume};  log /* -r; \
    add wave -position end  sim:/top/logic_gate_inst/task_3_gate_inst/i_A; \
    add wave -position end  sim:/top/logic_gate_inst/task_3_gate_inst/i_B; \
    add wave -position end  sim:/top/logic_gate_inst/task_3_gate_inst/i_C; \
    add wave -position end  sim:/top/logic_gate_inst/task_3_gate_inst/i_D; \
    add wave -position end  sim:/top/logic_gate_inst/task_3_gate_inst/o_Y; \
    run -all; quit" -wlf top.wlf -l top.log 
