vsim -do ./scripts/run_task_1.do -c
mv top.log ./logs/or.log
vsim -do ./scripts/run_task_2.do -c
mv top.log ./logs/nor.log
vsim -do ./scripts/run_task_3.do -c
mv top.log ./logs/nand.log
