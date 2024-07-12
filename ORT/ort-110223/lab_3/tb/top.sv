

`define TOP_ID                  ("ORT-2023")

function bit check_logic(bit [3 : 0] _val,
                            bit [7 : 0]_y
                            );
    bit ret_val;
    bit [7  : 0] exp_val;
    
    `ifdef __TASK_1__
        case (_val)
            0 : exp_val = 7'h7e;
            1 : exp_val = 7'h30;
            2 : exp_val = 7'h6d;
            3 : exp_val = 7'h79;
            4 : exp_val = 7'h33;
            5 : exp_val = 7'h5b;
            6 : exp_val = 7'h5f;
            7 : exp_val = 7'h72;
            8 : exp_val = 7'h7f;
            9 : exp_val = 7'h7b;
            default : exp_val = 7'h4f;
        endcase 
    `elsif __TASK_2__
        if ((0 == (_val >> 1)) || (4 == (_val >> 1)) || 
            (6 == (_val >> 1)) || (7 == (_val >> 1))) begin
            exp_val = 1;
        end else begin
            exp_val = 0;
        end 
    `elsif __TASK_3__
        if ((3 == _val) || (5 == _val) || (6 == _val) || (7 == _val) ||
            (9 == _val) || (10 == _val) || (11 == _val) || (12 == _val) ||
            (13 == _val) || (14 == _val) || (15 == _val)) begin
            exp_val = 1;
        end else begin
            exp_val = 0;
        end 
    `elsif __EXAMPLE_1__
        if ((0 < _val) && (0 == _val % 2))
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
    logic [7 : 0] y;
    
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
            $display("%s: NBCD/7S Converter", `TOP_ID);
            fname = "./results/task_1.log";
            lname = " 1";
        `elsif __TASK_2__
            $display("%s: Logic function: F(1) = {0, 4, 6, 7}", `TOP_ID);
            fname = "./results/task_2.log";
            lname = " 2";
        `elsif __TASK_3__
            $display("%s: Logic function: f(D,C,B,A) = ∑(3,5,6,7,9,10,11,12,13,14,15)", `TOP_ID);
            fname = "./results/task_3.log";
            lname = " 3";    
        `elsif __EXAMPLE_1__
            $display("%s: Logic function: F = ~D & (A | B | C)", `TOP_ID);
            fname = "./results/example_1.log";
            lname = " example 1";
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
        `ifdef __TASK_1__
            $display("%s: \t---------------------------------------------------", `TOP_ID);
            $display("%s: \t|  i || A | B | C | D || a b c d e f g |          |", `TOP_ID);
            $display("%s: \t---------------------------------------------------", `TOP_ID);
        `else
            $display("%s: \t----------------------------", `TOP_ID);
            $display("%s: \t|  i || A | B | C | D || Y |", `TOP_ID);
            $display("%s: \t----------------------------", `TOP_ID);
        `endif /* __TASK_3__ */
        #5ns;
        
        for (int i = 0; i < 16; i++) begin
        
            in_val = i;
            #5ns;
            check_status = check_logic(in_val, y);
            status += check_status;
            str = $sformatf("%2d %b %b %b %b %b - %s", i,
                            in_val[3], in_val[2], 
                            in_val[1], in_val[0],
                            y, ((0 == check_status) ? "OK" : "NOK")
                            );
            //$display("%s", str);
            $fdisplay(fd, str);
            `ifdef __TASK_1__
                $display("%s: \t| %2d || %b | %b | %b | %b || %b %b %b %b %b %b %b | %02h | %03d |", `TOP_ID,
                            i, 
                            in_val[3], in_val[2], 
                            in_val[1], in_val[0], 
                            y[6], y[5], y[4], y[3], y[2], y[1], y[0], y, y
                            );
                $display("%s: \t--------------------------------------------------", `TOP_ID);
            `else
                $display("%s: \t| %2d || %b | %b | %b | %b || %b |", `TOP_ID,
                            i, 
                            in_val[3], in_val[2], 
                            in_val[1], in_val[0], 
                            y[0]
                            );
                $display("%s: \t---------------------------", `TOP_ID);
            `endif /* __TASK_3__ */
        
        end // for (int i = 0; i < 16; i++)
        
        $display("%s: ====================================================", `TOP_ID);
        str = $sformatf("final:%s", ((0 == status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $display("%s: FINAL - %s", `TOP_ID,
                    ((0 == status) ? "OK" : "NOK"));
        $finish();
    end

endmodule : top
