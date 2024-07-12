

`define TOP_ID                  ("ORT-2023")

`ifdef __TASK_1__
    `define __TASK_1_or_EXAMPLE_1__
`elsif __EXAMPLE_1__
    `define __TASK_1_or_EXAMPLE_1__
`endif



module top;

    logic clk;
    logic rst_n;
    
    logic [7 : 0] in_data;
    logic [7 : 0] out_data;
    
    
    wire w_t;
    logic ref_led;
    
    wire ref_d;
    logic ref_q;
    logic ref_q_n;
    
    wire [1 : 0] w_sel;
    logic [3 : 0] ref_reg_q;
    logic [3 : 0] ref_register;
    wire w_reg_data_right;
    wire w_reg_data_left;
    
    bit [3 : 0] ref_cnt;
    
    bit start;
    
    integer fd;
    string fname;
    string lname;
    string str;
    bit check_status;
    int status;

    task reg_shift(bit [1 : 0] _op, bit [3 : 0] _data);
        /* Load */
        if (2'b01 == _op) begin
            @(posedge clk);
            #2ns;
            in_data[7 : 6] = _op;
            in_data[3 : 0] = _data;
        /* Shift L/R */
        end else if ((2'b11 == _op) || (2'b10 == _op)) begin
            for (int i = 0; i < 4; i++) begin
                @(posedge clk);
                #2ns;
                in_data[7 : 6] = _op;
                in_data[5] = _data[i];
                in_data[4] = _data[3 - i];
                in_data[3 : 0] = _data;
            end /* for (int i = 0; i < 4; i++) */
         end else if (2'b00 == _op) begin
            @(posedge clk);
            #2ns;
            in_data[7 : 6] = _op;
            in_data[5] = _data[0];
            in_data[4] = _data[3];
            in_data[3 : 0] = _data;
         end
    endtask : reg_shift



    logic_gate logic_gate_inst (
            .i_clk(clk),
            .i_rst_n(rst_n),
            .i_DATA(in_data),
            .o_DATA(out_data)
        );

    initial begin
        start = 0;
        $display("%s: ====================================================", `TOP_ID);
        `ifdef __TASK_1__
            $display("%s: TASK1", `TOP_ID);
            fname = "./results/task_1.log";
            lname = " 1";
        `elsif __TASK_2__
            $display("%s: TASK2", `TOP_ID);
            fname = "./results/task_2.log";
            lname = " 2";
        `elsif __TASK_3__
            $display("%s: TASK3", `TOP_ID);
            fname = "./results/task_3.log";
            lname = " 3";    
        `elsif __EXAMPLE_1__
            $display("%s: DFF using JKFF", `TOP_ID);
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
        in_data = 0;
        wait (1 == start);
        $display("%s: =============================================================", `TOP_ID);
        rst_n = 0;
        #350ns;
        rst_n = 1;
        
        `ifdef __TASK_1_or_EXAMPLE_1__
            for (int i = 0; i < 100; i++) begin
                @(negedge clk);
                in_data[0] = $urandom_range(0, 1);
            end
            rst_n = 0;
            #350ns;
            for (int i = 0; i < 100; i++) begin
                @(negedge clk);
                in_data[0] = $urandom_range(0, 1);
            end
            #350ns;
            rst_n = 1;
            for (int i = 0; i < 100; i++) begin
                @(negedge clk);
                in_data[0] = $urandom_range(0, 1);
            end
        `elsif __TASK_2__
        
            repeat (3) begin
                // Shift left
                reg_shift(2'b10, 4'b1000);
                // Shift right
                reg_shift(2'b11, 4'b0000);
            end
            repeat (3) begin
                // Shift right
                reg_shift(2'b11, 4'b0001);
                // Shift left
                reg_shift(2'b10, 4'b0000);
            end
            // No Op
            reg_shift(2'b00, 4'b0001);
            #5us;
            
            repeat (3) begin
                // Shift left
                reg_shift(2'b10, 4'b1111);
                // Shift left
                reg_shift(2'b10, 4'b0000);
                // Shift right
                reg_shift(2'b11, 4'b1111);
                // Shift right
                reg_shift(2'b11, 4'b0000);
            end
            // No Op
            reg_shift(2'b00, 4'b0001);
            #5us;
            for (int i = 0; i < 50; i++) begin
                reg_shift($urandom_range(1, 3), $urandom_range(0, 15));
                // No Op
                reg_shift(2'b00, 4'b0000);
                #500ns;
            end
            #500ns;
        `elsif __TASK_3__
            in_data[0] = 1;
            #9us;
            in_data[0] = 0;
            #10us;
            in_data[0] = 1;
            #7us;
            in_data[0] = 0;
            #10us;
            in_data[0] = 1;
            #13us;
            in_data[0] = 0;
            #10us;
        `else
            $display("%s: Logic function: UNDEFINED", `TOP_ID);
        `endif
        
        #1us;
        $display("%s: =============================================================", `TOP_ID);
        $display("%s: STATUS - %s", `TOP_ID,
                    ((0 == status) ? "OK" : "NOK"));
        $display("%s: =============================================================", `TOP_ID);
        str = $sformatf("final:%s", ((0 == status) ? "OK" : "NOK"));
        $fdisplay(fd, str);
        $fclose(fd);
        $finish();
    end


    /*
     * Monitor
     */
    initial begin
        status = 0;
        wait (1 == start);
        
        forever begin
            @(posedge clk);
            
            `ifdef __TASK_1_or_EXAMPLE_1__
                $display("%s: Positive edge CLK ==> RST = %0b, T = %0b, LED = %0b", 
                            `TOP_ID, rst_n, in_data[0], out_data[0]
                            );
                if (ref_led != out_data[0]) begin
                    status++;
                    $error("%s: Checking output LED: FAILED!!! Expected LED = %0b, Actual LED = %0b",
                            `TOP_ID, ref_led, out_data[0]);
                    str = $sformatf("%s: Checking output LED! Expected LED = %0b, Actual LED = %0b - %s",
                                    `TOP_ID, ref_led, out_data[0], "NOK");
                end else begin
                    str = $sformatf("%s: Checking output LED! Expected LED = %0b, Actual LED = %0b - %s",
                                    `TOP_ID, ref_led, out_data[0], "OK");
                end /* if (ref_led != out_data[0]) */
                
                $fdisplay(fd, str);
                
                
                
            `elsif __TASK_2__
                $display("%s: Positive edge CLK ==> RST = %0b, OP = %0b, DATA = %04b, L = %0b, R = %0b Q = %04b", 
                            `TOP_ID, rst_n, 
                            in_data[7 : 6], in_data[3 : 0], in_data[5], in_data[4],
                            out_data[3 : 0]
                            );
                if (out_data[3 : 0] != ref_register) begin
                    status++;
                    $error("%s: Checking register output... FAILED!!! Expected = %04b, Actual = %04b",
                             `TOP_ID, ref_register, out_data[3 : 0]
                            );
                    str = $sformatf("%s: Checking register output... Expected = %04b, Actual = %04b - %s",
                                    `TOP_ID, ref_register, out_data[3 : 0], "NOK"
                                    );
                end else begin
                    str = $sformatf("%s: Checking register output... Expected = %04b, Actual = %04b - %s",
                                    `TOP_ID, ref_register, out_data[3 : 0], "OK"
                                    );
                end /* if (out_data[3 : 0] != ref_register) */
                
                $fdisplay(fd, str);
            `elsif __TASK_3__
                #1;
                $display("%s: Positive edge CLK ==> RST = %0b, DIRECTION: %s, CNT = %04b (%01d/0x%01h)", 
                            `TOP_ID, rst_n, (in_data[0]) ? "UP" : "DOWN" ,out_data[3 : 0], out_data[3 : 0], out_data[3 : 0]
                            );
                if (out_data[3 : 0] != ref_cnt) begin
                    status++;
                    $error("%s: Checking counter output... FAILED!!! Expected = %04b, Actual = %04b",
                             `TOP_ID, ref_cnt, out_data[3 : 0]);
                    str = $sformatf("%s: Checking counter output... Expected = %04b, Actual = %04b - %s",
                                    `TOP_ID, ref_cnt, out_data[3 : 0], "NOK"
                                    );
                end else begin
                    str = $sformatf("%s: Checking counter output... Expected = %04b, Actual = %04b - %s",
                                    `TOP_ID, ref_cnt, out_data[3 : 0], "OK"
                                    );
                end /* if (out_data[3 : 0] != ref_cnt) */ 
                $fdisplay(fd, str);
            `else
                $display("%s: Logic function: UNDEFINED", `TOP_ID);
            `endif
        end /* forever */
    end /*initial */


    /*
     * Clock generation
     */
    initial begin 
        clk = 0;
        forever begin
            #100ns;
            clk = ~clk;
        end /* forever */
    end /* initial */
    
    
    /*
     * Reference Model
     */
    `ifdef __TASK_1_or_EXAMPLE_1__
        assign w_t = in_data[0];
        initial begin
            forever begin
                
                @(posedge clk);
                if (0 == rst_n) begin
                    ref_led <= 0;
                end else begin
                    ref_led <= (w_t) ? 1'b0 : 1'b1;
                    ///ref_q <= ref_d;
                    ///ref_q_n <= ~ref_d;
                end /* if (0 == rst_n) */
                
            end /* forever */
        end /* initial begin */
    `elsif __TASK_2__
        assign w_sel = in_data[7 : 6];
        assign w_reg_data_left = in_data[5];
        assign w_reg_data_right = in_data[4];
        initial begin
            forever begin
                @(posedge clk);
                if (0 == rst_n) begin
                    ref_reg_q <= 0;
                end else begin
                    /* No change */
                    if (2'b00 == w_sel) begin
                        ref_reg_q <= ref_reg_q;
                    /* Load input */
                    end else if (2'b01 == w_sel) begin
                        ref_reg_q <= in_data[3 : 0];
                    /* Shift in left */
                    end else if (2'b10 == w_sel) begin
                        ref_reg_q <= {ref_reg_q[2 : 0], w_reg_data_right};
                    /* shift in right */
                    end else begin
                        ref_reg_q <= {w_reg_data_left, ref_reg_q[3 : 1]};
                    end /* if (2'b00 == w_sel)  */
                end /* if (0 == rst_n) */
            end /* forever */
        end /* initial */
        initial begin
            forever begin
                @(posedge clk);
                ref_register <= ref_reg_q;
            end
        end
    `elsif __TASK_3__
        initial begin
            ref_cnt <= 0;
            forever begin
                @(posedge clk);
                if (0 == rst_n) begin
                    ref_cnt <= 0;
                end else begin
                    if (1 == in_data[0]) begin // UP
                        if (4 == ref_cnt) begin
                            ref_cnt <= 0; 
                        end else begin
                            ref_cnt++;
                        end /* if (4 == ref_cnt) */
                    end else begin // DOWN
                        if (0 == ref_cnt) begin
                            ref_cnt <= 4; 
                        end else begin
                            ref_cnt--;
                        end /* if (0 == ref_cnt) */
                    end
                end /* if (0 == rst_n) */
            end /* forever */
        end /* initial */
    `else
        $display("%s: Logic function: UNDEFINED", `TOP_ID);
    `endif
endmodule : top
