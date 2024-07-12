

`define TOP_ID                  ("ORT-2023")

function bit check_logic(bit [3 : 0] _val,
                            bit _y
                            );
    bit ret_val;
    bit exp_val;
    
    `ifdef __TASK_1__
        if ((0 < _val) && (0 == _val % 2))
            exp_val = 1;
        else 
            exp_val = 0;
    `elsif __TASK_2__
        exp_val = ^_val;
    `elsif __TASK_3__
         if ((7 > _val) && (0 == _val % 2))
            exp_val = 1;
        else 
            exp_val = 0;
    `else
        $display("%s: Logic function: UNDEFINED", `TOP_ID);
    `endif
    
    ret_val = (_y == exp_val) ? 0 : 1;
    return (ret_val);
endfunction : check_logic

module top;

    logic [3 : 0] in_val;
    logic y;
    
    bit start;
    
    integer fd;
    string fname;
    string lname;
    string str;
    bit check_status;
    int status;

    logic_gate logic_gate_inst (
            .i_A(in_val[3]),
            .i_B(in_val[2]),
            .i_C(in_val[1]),
            .i_D(in_val[0]),
            .o_Y(y)
        );

    initial begin
        start = 0;
        $display("%s: ====================================================", `TOP_ID);
        `ifdef __TASK_1__
            $display("%s: Logic table for task 1", `TOP_ID);
            fname = "./results/task_1.log";
            lname = "OR";
        `elsif __TASK_2__
            $display("%s: Logic table for task 2", `TOP_ID);
             fname = "./results/task_2.log";
             lname = "NOR";
        `elsif __TASK_3__
            $display("%s: Logic table for task 3", `TOP_ID);
             fname = "./results/task_3.log";    
        `else
            $display("%s: Logic gate: UNDEFINED", `TOP_ID);
        `endif
        fd = $fopen(fname, "w");
        $fdisplay(fd, "task:", lname);
        start = 1;
    end
        
    initial begin
        in_val = 0;
        status = 0;
        wait (1 == start);
    
        $display("%s: ====================================================", `TOP_ID);
        $display("%s: \t---------------------", `TOP_ID);
        $display("%s: \t| A | B | C | D | Y |", `TOP_ID);
        $display("%s: \t---------------------", `TOP_ID);
        
        #5ns;
        
        for (int i = 0; i < 16; i++) begin
        
            in_val = i;
            #5ns;
            check_status = check_logic(in_val, y);
            status += check_status;
            str = $sformatf("%b %b %b %b %b - %s",
                            in_val[3], in_val[2], 
                            in_val[1], in_val[0],
                            y, ((0 == check_status) ? "OK" : "NOK")
                            );
            //$display("%s", str);
            $fdisplay(fd, str);
            $display("%s: \t| %b | %b | %b | %b | %b |", `TOP_ID,
                        in_val[3], in_val[2], 
                        in_val[1], in_val[0], 
                        y
                        );
            $display("%s: \t---------------------", `TOP_ID);
        
        end // for (int i = 0; i < 16; i++)
        
        $display("%s: ====================================================", `TOP_ID);
        str = $sformatf("final:%s", ((0 == status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $display("%s: FINAL - %s", `TOP_ID,
                    ((0 == status) ? "OK" : "NOK"));
        $finish();
    end

endmodule : top

